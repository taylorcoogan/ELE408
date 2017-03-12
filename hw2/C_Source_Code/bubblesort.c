/**
Taylor Coogan
ELE 408
Bubble Sort: sorts 100 integers between 1 and 1000 
 **/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define total 100

int main()
{
    int nums[total];   // array for numbers 
    srand(time(NULL));    // seed random with time
    int i, j;  // loop counter
    
    /* assign array values */
    for(i = 0; i < total; i++)
    {
        nums[i] = (rand() % 1000);    // nums can range 1-1000
    }
    printf("\n");
   
    /* print initial numbers */
    for(i = 0; i < total; i++)
    {
        printf("%d ", nums[i]);
    }
    printf("\n\n");
    
    
    int temp;   // temporary var for swapping array values
    
   /* we do the following n-1  times */
    for(i = 0; i < (total - 1); i++)
    {
        for(j = 0; j < (total - 1); j++) // go through whole array
        {
            if(nums[j+1] <= nums[j])  // if two are out of order
            {                           // we switch them
                temp = nums[j];
                nums[j] = nums[j+1];
                nums[j+1] = temp;
            }
        }
    }
    
    /* print out our results */
    for(i = 0; i < total; i++)
    {
        printf("%d ", nums[i]);
    }
    printf("\n");
    return 0;
}

