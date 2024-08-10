#include <stdio.h>
#include <omp.h>

int main ()
{
 omp_set_num_threads(8);
 int threads_id;
 #pragma omp parallel private(threads_id)
 {
        threads_id = omp_get_thread_num();
        printf("Hello World from thread = %d\n",threads_id);
 }   
}