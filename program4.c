#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_THREADS 20

static long steps = 1000000000;
double step;


int main (int argc , char **argv)
{

    int nthreads,tid;
    double pi, sum = 0.0;
    double start, delta;
    step = 1.0/(double) steps;
    
    int i,j;
    for(j = 1; j <= MAX_THREADS; j++)
    {
        omp_set_num_threads(j);
        sum = 0.0;
        start = omp_get_wtime();
        #pragma omp parallel private(i)
        {
            double x;
            #pragma omp for reduction(+:sum)
            for(i = 0; i < steps; i++)
            {
                x = (i + 0.5) * step;
                sum += 4.0/(1.0 + x*x);
            }
        }
        pi = step * sum;
        delta = omp_get_wtime() - start;
        printf("Threads = %d, pi = %f, delta = %f\n",j,pi,delta);
    }

    
}