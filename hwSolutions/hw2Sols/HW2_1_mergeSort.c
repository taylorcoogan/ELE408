#include <stdio.h>
#define MAXSIZE 100

int array[MAXSIZE];
int temp[MAXSIZE];

void merging(int, int, int);
void sort(int, int) ;

void main() {
    
    int i; 
    for(i = 0; i < MAXSIZE; i++) {
         array[i] = rand() % 1000 + 1;
     }
     
    for (i = 0; i < MAXSIZE; i++) {
         printf("%d\n", array[i]);
     }
     
     /* Selection sorting begins */
     sort(0, MAXSIZE);
     
     printf("Sorted array is...\n");
     
     for (i = 0; i < MAXSIZE; i++) {
         printf("%d\n", array[i]);
     }
}

void merging(int low, int mid, int high) {
   int l1, l2, i;

   for(l1 = low, l2 = mid + 1, i = low; l1 <= mid && l2 <= high; i++) {
      if(array[l1] <= array[l2])
         temp[i] = array[l1++];
      else
         temp[i] = array[l2++];
   }
   
   while(l1 <= mid)    
      temp[i++] = array[l1++];

   while(l2 <= high)   
      temp[i++] = array[l2++];

   for(i = low; i <= high; i++)
      array[i] = temp[i];
}

void sort(int low, int high) {
   int mid;
   
   if(low < high) {
      mid = (low + high) / 2;
      sort(low, mid);
      sort(mid+1, high);
      merging(low, mid, high);
   } else { 
      return;
   }   
}