/** 
 * Taylor Coogan
 * ELE 408 
 * Monte Carlo Pi Estimation 
 **/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const long sampleSize = 1e3;

double monte_carlo()
{
    double x, y, pi;
    long count=0;
    long k;
    for (k=0; k < sampleSize; k++) 
    {
        x =((double)rand()/(double)RAND_MAX);
        y = ((double)rand()/(double)RAND_MAX);
        if (x * x + y * y <= 1.0) 
            count++;
            
    }
    pi = 4.0 * (double)count / (double)sampleSize;
    return pi;
}

int main()
{
    srand((unsigned)time(NULL));
    printf("Welcome to the Monte Carlo Party\n\n");
    printf("Sample Size: %ld \n\n", sampleSize);
    printf("Estimation of Pi: %f \n", monte_carlo());
    return 0;
}


