/** 
Taylor Coogan
ELE 408
Merge Sort: Sorts 100 integers from 1-1000 using merge sort algorithm
**/
#include <stdio.h>
#include <stdlib.h>
#define total 100

int nums[total];
int cool[total];

/* Method for merging aspect of the merge sort*/
void merge(int low, int mid, int high) {
    
    int temp, temp1, i; // variables used in function

    // we check if first and second halves have sorted to the end 
    for(temp = low, temp1 = mid + 1, i = low; temp <= mid && temp1 <= high; i++) 
    {
        if(nums[temp] <= nums[temp1])   // if low less than the mid value 
            cool[i] = nums[temp++];     // we put the low in new array
        else                            // post-increment temp
            cool[i] = nums[temp1++];    // otherwise we put mid value in cool
    }
   
    while(temp <= mid)              // while the low value less than middle
    {
        cool[i++] = nums[temp++];   // we put low value in new array
    }

    while(temp1 <= high)            // while the second half is less than end
    {
        cool[i++] = nums[temp1++];  // put value in new array
    }

   for(i = low; i <= high; i++) // then we loop through and put back into
   {                            // original array
      nums[i] = cool[i];
   }
}

/* recursive sort function */
void sorter(int low, int high) {
   int mid;
   
   if(low < high) {             // if we have more than one array value
      mid = (low + high) / 2;   // we get middle value 
      sorter(low, mid);         // we sort first half
      sorter(mid+1, high);      // sort second half
      merge(low, mid, high);    // merge them with merge function
   } else { 
      return;
   }   
}
/* Main function generates random numbers, 
   prints original, calls sort, prints result */
int main() { 
   int i;
   // we loop through array generating random numbers
   for(i = 0; i < total; i++)
       nums[i] = (rand() % 1000);    // nums can range 1-1000
   
    
   // we print our original array
   printf("Original Array: \n");
   for(i = 0; i <= total; i++)
      printf("%d ", nums[i]);

   printf("\n\n");


   sorter(0, total);    // we sort the hell out of it

   // we print the results
   printf("Results: \n");
   for(i = 0; i <= total; i++)
      printf("%d ", nums[i]);
      
   printf("\n\n");
}

