/** 
 * tower of hanoi
 **/

#include <stdio.h>
#include <stdlib.h>

void Hanoi(int n, char source, char destination, char spare)
{
    
    if (n == 1) /* base case */
    {
        printf(" Move Disk %d from pole %c", n ,source);	// move disk from source to dest
        printf(" to pole %c \n", destination);				// whenever we get to a single disk
    }
    else // recursion
    { 
    Hanoi(n-1,source,spare,destination);    	// we basically deal with the first two
    printf(" Move Disk %d from pole %c", n ,source);	// and use this algorithm
    printf(" to pole %c \n", destination);			// to deal with any number
	Hanoi(n-1,spare, destination, source);		// of disks
    }
}

int main(int argc, char *argv[])
{
    printf("Welcome to Tower of Hanoi!\n");
    
    int ret = 0;	// for testing if sscan completed without error
	int disks = 0;  // for the number of disks
	
    ret = sscanf(argv[1], "%d", &disks);	// gets # of disks from user arg
        if (ret != 1)return 0;		// if this fails, exit program
    
    char a = 'A';
    char b = 'B';	// name our poles
    char c = 'C';
    
    Hanoi(disks, a, b, c);	// do the things
    
    

    return 0;
}

