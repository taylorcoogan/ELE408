/**
Taylor Coogan
ELE 408
Selection Sort: sorts 100 integers between 1 and 1000 
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
    
    
    int temp, othertemp;   // holds current smallest
    int temp2; // holds other one
    int tindex;  // holds index of smallest temporarily
    
   
    for(i = 0; i < total; i++)
    {
        
        temp = nums[i]; // next unsorted number
        
        for(j = i; j < total; j++) // check rest of array from first unsorted #
        {
            if(nums[j] <= temp)  // if we find a smaller or equal number
            {
                temp = nums[j]; // set it to temp
                tindex = j;      // and keep its index 
            }
        }
        // now we have smallest numer, we switch them
        temp2 = nums[i];    // keep original unsorted # in temp
        nums[i] = temp;     // put new smallest # in original position
        nums[tindex] = temp2;// put original value in smallest's old index
    }
    
    /* print out our results */
    for(i = 0; i < total; i++)
    {
        printf("%d ", nums[i]);
    }
    printf("\n");
    return 0;
}

