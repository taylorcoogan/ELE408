#include <stdio.h>

void Hanoi(int, char, char, char);

int main(int argc, char *argv[]){
     int input;
     if(argc!= 2){
          printf("The number of inputs should be equal to 2!!!");
     }
     else{
          input = atoi(argv[1]);
          Hanoi(input, 'A', 'B', 'C');
     }
}

void Hanoi(int n, char source, char destination, char spare) { 
    if (n == 1)  {
        printf("Move top disk from pole %c ", source);
        printf("to pole %c\n", destination);
    }
    else { /* recursion */
        Hanoi(n-1,source,spare,destination);
        Hanoi(1, source, destination, spare);
        Hanoi(n-1,spare, destination, source);
    }
}