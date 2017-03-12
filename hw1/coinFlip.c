/** 
-Taylor Coogan
-coinFlip.c
-This code takes no user input and flips 200 instances of a coin. 
It then reports the total heads and fails to the user.  The number of coin
flips can be changed by modifying the flips variable. 
**/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int flip();	// declaring the flip method called later


int main()
{
    int flips = 200; // number of coin flips
    int i = 0;  // for counter
    int result = 3; // result of coin flip
    int heads = 0; // total heads
    int tails = 0; // total tails
    srand(time(NULL));  // seeds random num generator with time
                        // so that it is "actually" random
    
    for( i = 0 ; i < flips ; i++ ) // for each flip
    {
        result = flip();        // we get the result of the flip
        if(result == 1) { heads++; }    // check if it is heads...
        else if( result == 0) {tails++; }   // or tails
    }
    
    /* Print results */
    printf("\n Total Heads: %d", heads);
    printf("\n Total Tails: %d \n", tails);
    
    return 0;
}

/* Our function for the actual coin flip */
int flip()
{
    return(rand() % 2); // random number mod 2, so it can only be a 0 or 1
}