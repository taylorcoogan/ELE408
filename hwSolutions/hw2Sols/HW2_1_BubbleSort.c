/* Bubble Sort*/
#include <stdio.h>
#define MAXSIZE 100

void main() {
    int array[MAXSIZE];
    int i, j, temp;
     
    for(i = 0; i < MAXSIZE; i++) {
         array[i] = rand() % 1000 + 1;
     }
     
    for (i = 0; i < MAXSIZE; i++) {
         printf("%d\n", array[i]);
     }
     
     /* Bubble sorting begins */
    for (i = 0; i < MAXSIZE; i++) { 
        for (j = 0; j < (MAXSIZE - i - 1); j++) {
            if (array[j] > array[j + 1]) {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
         }
     }
     
     printf("Sorted array is...\n");
     
     for (i = 0; i < MAXSIZE; i++) {
         printf("%d\n", array[i]);
     }
}