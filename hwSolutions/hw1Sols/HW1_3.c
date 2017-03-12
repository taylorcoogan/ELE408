#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]){
     if(!(argc == 2)) {
          printf("Please input one parameter!");
     }
     else{
		 int i;
		 int input;
		 input = atoi(argv[1]);
		 printf("input = %d\n",input);
		 for (i = 0; i < input; i++) {
		     printf("%d\n",RandomToss());
		 }
     }
}

int RandomToss() {
    int result;
    result = ((rand()*1.0/RAND_MAX) < 0.5);
    return result;
}