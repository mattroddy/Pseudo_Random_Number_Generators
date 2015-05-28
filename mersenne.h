// Matthew Roddy (14212384)

// This C-object implements a version
// of the Mersennne Twister as given in
// pseudocode from the wikipedia article

#ifndef _MERSENNE_H
#define _MERSENNE_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>

typedef struct Mersenne{
	int index;
	uint32_t mTwist[624];
	void (*seed)(struct Mersenne* self, int seedint);
	void (*generateNum)(struct Mersenne* self);
	int (*getNum)(struct Mersenne* self);
} Mersenne;

void seedFunc(struct Mersenne* self, uint32_t seedint);
void generateNumFunc(struct Mersenne* self);
int getNumFunc(struct Mersenne* self);

extern Mersenne MT;
#endif
