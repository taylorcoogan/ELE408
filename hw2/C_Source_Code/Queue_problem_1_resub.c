/** 
* Taylor Coogan
* This program simulates average queue legngth
* It runs through a series of 10 Arrival Rates
* 
* to calculate the mean queue and prints the results to a text file
**/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NumofPoints 10


int main() 
{
	FILE *fp; // fp = output.txt file pointer
	
	//double ArrialRate[NumofPoints] = { 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 0.95};
	double ArrialRate[NumofPoints] = { 0.1, 0.2, 0.25, 0.3, 0.35, 0.4, 0.425, 0.45, 0.475, 0.49};
	//double service_rate[NumofPoints] = { 0.1, 0.2, 0.25, 0.3, 0.35, 0.4, 0.425, 0.45, 0.475, 0.5};
	// arrival rate is lambda
	double meanQueue[NumofPoints] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};// this is L = avg queue length
	
	double s_rate = 0.5; //service rate
	
	long T = 1e6; //simulation time 1e3
	
	double A, S;		// variables for generating arrival and service rates
	double QL = 0; 	// queue length starts as zero. bc is referenced before assigned
	double sum;
	srand((unsigned)time(NULL));	// seed rand with time 
	
	fp = fopen("Qresults1.txt", "w");	// output to file 
	fprintf(fp, "ArrivalRate \t MeanQueue\n");	// headers 
	
	////////////////////loop party////////
	int i, j;	// counter variables
	
	/* Loop through all arrival time values in array*/
	for (i = 0; i < NumofPoints; i++)
	{
		sum  = 0;
		QL = 0;
		/* Now run simulation T times */
		for (j = 0; j < T; j++)
		{
			// we get a random arrival rate between zero and cap
			A = (((double)rand()) / (double)(RAND_MAX) < ArrialRate[i]);

			S = (((double)rand()) / (double)(RAND_MAX) < s_rate);

		
			/* We then calculate the new Queue average*/
			
			QL = (QL + A - S);
			if(QL < 0) { QL = 0; }
			
			sum = sum + QL;	// divide by total time at the end
				
		}
		meanQueue[i] = (sum / (double)T);
		fprintf(fp, "%f \t %f\n", ArrialRate[i], meanQueue[i]);
	}
	exit(0);
	//////////////////////////////////
}
	

