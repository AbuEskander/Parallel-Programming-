#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_THREADS 10

const unsigned long int size = 1000000000;

int main (int argc , const char **argv)
{
    int j;

    unsigned long int sum;
    double start, delta;

    for(j = 1; j <= MAX_THREADS; j++)
    {
            printf("running on %d threads\n",j);
            omp_set_num_threads(j);
            sum = 0;
            start = omp_get_wtime();
            #pragma omp parallel for reduction(+:sum)
            for(unsigned long int i = 0; i < size; i++)
            {
                sum += i;
            }

            delta = omp_get_wtime() - start;
            printf("Threads = %d, sum = %lu, Seconds = %f\n",j,sum,delta);
    }
}