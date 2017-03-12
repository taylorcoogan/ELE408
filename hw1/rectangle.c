/** 
-Taylor Coogan
-rectangle.c
-This code takes the input of an integer and prints a 
square of asterisks of that side length.
**/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int ret = 0;	// for testing if sscan completed without error
    int side = 0;	// variable for side length initialized to zero
	
    ret = sscanf(argv[1], "%d", &side);	// scanning user input for integer value, stores in side
        if (ret != 1)return 0;		// if this fails, exit program
        
    int i = 0;	// initialize loop counters
    int j = 0;	
    printf("\n");	// print new line for formatting
	
	for(i = 1; i <= (side); i++)	// outer loop for rows
	{
		for(j = 1; j <= (side); j++)	// inner loop prints columns
		{
			printf("* ");
		}

		printf("\n");	// after each row is printed, new line 
	}

	getchar();	// just in case console wants to close
	return(0);	// exit program 
}

