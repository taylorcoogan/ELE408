#include<stdio.h>

int findMaximum(int grade[], int);
int findMinimum(int grade[], int);
float calculateAverage(int grade[], int);
void printResults(int, int, float);


int main(int argc, char *argv[]){
     
    int grade[argc-1];
    
    int i;
    for(i=1; i<argc; i++){
        grade[i-1] = atoi(argv[i]);
        //printf("%d ", grade[i-1]);
    }
    //printf("\n");
    int Max, Min;
    float Avg;
    Max = findMaximum(grade,argc-1);
    Min = findMinimum(grade,argc-1);
    Avg = calculateAverage(grade,argc-1);
    printResults(Max, Min, Avg);
}

int findMaximum(int grade[], int size) {
    int maxGrade, i;
    maxGrade = grade[0];
    for (i=1; i < size; i++) {
        if(maxGrade < grade[i]) {
            maxGrade = grade[i];
        }
    }
    return maxGrade;
}

int findMinimum(int grade[], int size) {
    int minGrade, i;
    minGrade = grade[0];
    for (i=1; i < size; i++) {
        if(minGrade > grade[i]) {
            minGrade = grade[i];
        }
    }
    return minGrade;
}

float calculateAverage(int grade[], int size) {
    int i;
    float avg = 0;
    for (i=0; i < size; i++) {
        avg = avg + grade[i]*1.0/size;
        //printf("test=%f\n",avg);
    }
    return avg;
}

void printResults(int maximum, int minimum, float average) {
    printf("Maximum grade = %d\n", maximum);
    printf("Minimum grade = %d\n", minimum);
    printf("Average grade = %f\n", average);
}