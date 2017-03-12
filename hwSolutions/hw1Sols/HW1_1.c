#include<stdio.h>

int main(int argc, char *argv[]){
     if(!(argc == 2)) {
          printf("Please input one parameter!");
     }
     else{
		 int i, j;
		 int input;
		 input = atoi(argv[1]);
		 printf("input = %d\n",input);
		 for (i = 0; i < input; i++) {
		     for(j = 0; j < input; j++) {
		         printf("* ");
		     }
			 printf("\n");
		 }
     }
}