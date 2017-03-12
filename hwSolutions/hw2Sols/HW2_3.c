#include <stdio.h>
#include <stdlib.h>

#define NumofSimPoints 6

int main() {
    FILE *fp;   // fp = output.txt file pointer
    fp = fopen("output.txt", "w");


    int i;
	long MaxSamples[NumofSimPoints] = {1e3, 1e4, 1e5, 1e6, 1e7, 1e8};
	double x, y, pi;

    for(i = 0; i < NumofSimPoints; i++) {
        long count=0;
        for (long k=0; k<MaxSamples[i]; k++) {
            x=2.0*rand()/RAND_MAX – 1.0;  // Map to the range [-1,1]
            y=2.0*rand()/RAND_MAX – 1.0;
            if (x*x+y*y<=1.0) count++;
        }
        pi=4.0 * (double)count / (double)MaxSamples[i];
        fprintf(fp, "%f %f\n", MaxSamples[i], pi);
    }
}

