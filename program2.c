#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

int main (){

    omp_set_num_threads(5);
    printf("Number of threads = %d\n",omp_get_num_threads());

    #pragma omp parallel
    {
     
        printf("Number of threads  = %d\n",omp_get_num_threads());
    }
}