// Matthew Roddy (14212384)

// This C object implements a version of
// RC4 from pseudo-code given in
// "Cryptography and Network Security" by
// William Stalling, 6e, 2013.

#ifndef _RCFour_H
#define _RCFour_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct RC{
	int32_t i,j,key,keyLength;
	int32_t T[256];
	int32_t S[256];
	void (*init)(struct RC* self, int seedint);
	int (*getNum)(struct RC* self);
} RC;

void initFunc(struct RC* self, int32_t seedInt);
int32_t getNumFuncRC(struct RC* self);

extern RC RCObj;
#endif
