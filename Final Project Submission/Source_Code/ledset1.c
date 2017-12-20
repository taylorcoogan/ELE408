#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include "hwlib.h"
#include "soc_cv_av/socal/socal.h"
#include "soc_cv_av/socal/hps.h"
#include "soc_cv_av/socal/alt_gpio.h"
#include "hps_0.h"
#include <stdbool.h>
#include "fpga.h"

#define HW_REGS_BASE ( ALT_STM_OFST )
#define HW_REGS_SPAN ( 0x04000000 )
#define HW_REGS_MASK ( HW_REGS_SPAN - 1 )

// any global declarations
int HexSetDec(int value);

int main(int argc, char *argv[])
{
	// any local declarations
	int value;
	uint32_t switchMask;

	if(!FPGAInit()){
		printf("can't initialize fpga");
		return 0;
	}
	int lives = atoi(argv[1]);
	int oplives = atoi(argv[2]);
	
	oplives = oplives << 7;
	int ledVal = lives | oplives;
	
	FPGALedSet(ledVal);	
//	HexSetDec(num);
	return 1;
}

int HexSetDec(int value)
{
	if(value < 0 || value > 999999)
	{	return 0; }

	int i;
	for (i = 0; i < 6; i++)
	{
		HexSet(i, value % 10);
		value /= 10;
	}
}


