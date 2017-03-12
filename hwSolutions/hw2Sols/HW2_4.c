#define _CRT_SECURE_NO_DEPRECATE

#include <stdio.h>
#include <stdlib.h>

#define NumofSimPoints 8
#define SimTime  1e6
#define M 5

int main() {
	FILE *fp;   // fp = output.txt file pointer
	fp = fopen("output.txt", "w");

	int i;
	double Lambda[NumofSimPoints] = {0.1, 0.15, 0.2, 0.25, 0.3, 0.35, 0.4, 0.45}; //arrival rate
	double mu = 0.5; //service rate


	int A;  //arrival
	double S;  //service
	for (i = 0; i < NumofSimPoints; i++) {
		double Q = 0;   // queue-length
		double AvgQ = 0;
		for (long t = 0; t < SimTime - 1; t++) {
			A = ((1.0*rand() / RAND_MAX) < Lambda[i]);
			S = ((1.0*rand() / RAND_MAX) < mu);   // Geo/Geo/1
			//S = 0.5;                              // Geo/D/1
			//S = M*((1.0*rand() / RAND_MAX) < mu/M);  //Geo/X/1
			AvgQ = AvgQ + Q*1.0 / SimTime; 
			Q = Q + A - S;
			if (Q < 0) Q = 0;
		}
		printf("%f %f\n", Lambda[i], AvgQ);
		fprintf(fp, "%f %f\n", Lambda[i], AvgQ);
	}
}
