#include <omp.h>
#include <stdio.h>


# define MAX_THREADS 10 

int main ()
{
	omp_set_num_threads(MAX_THREADS);
    int numberofthreads = omp_get_max_threads();
    printf("Number of threads = %d\n",numberofthreads);

    int sum = 0;
    #pragma omp parallel  reduction(+:sum)
       {
            sum = 1;    
        }
    printf("Sum = %d\n",sum);
}
