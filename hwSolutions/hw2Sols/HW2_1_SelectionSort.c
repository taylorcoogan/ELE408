#include <stdio.h>
#define MAXSIZE 100

void main() {
    int array[MAXSIZE];
    int i, j, position, temp;
     
    for(i = 0; i < MAXSIZE; i++) {
         array[i] = rand() % 1000 + 1;
     }
     
    for (i = 0; i < MAXSIZE; i++) {
         printf("%d\n", array[i]);
     }
     
     /* Selection sorting begins */
      for ( i = 0 ; i < ( MAXSIZE - 1 ) ; i++ ) {
          position = i;
          for ( j = i + 1 ; j < MAXSIZE ; j++ ) {
              if ( array[position] > array[j] )
              position = j;
          }
          
          if ( position != i )
          {
              temp = array[i];
              array[i] = array[position];
              array[position] = temp;
          }
      }
     
     printf("Sorted array is...\n");
     
     for (i = 0; i < MAXSIZE; i++) {
         printf("%d\n", array[i]);
     }
}