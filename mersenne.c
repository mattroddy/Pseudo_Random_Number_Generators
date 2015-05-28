// Matthew Roddy (14212384)

#include "mersenne.h"

Mersenne MT={
		.index=0,
		.mTwist={0},
		.seed=seedFunc,
		.generateNum=generateNumFunc,
		.getNum=getNumFunc
};

void seedFunc(struct Mersenne* self, uint32_t seedint){
	uint32_t i;
	uint32_t tmp;
	int mask = ~(~0 << 16);
	self->mTwist[0] = seedint;
    for( i=1; i<=623; i++) { // loop over each element
    	tmp = self->mTwist[i-1] >> 30;
        self->mTwist[i] = mask & (1812433253 *(self->mTwist[i-1]^tmp) + i);
    }
}

void generateNumFunc(struct Mersenne* self){
	uint32_t i;
	uint32_t y;
	for(i=0; i <=623; i++){
		y = (self->mTwist[i] & (uint32_t)2147483648) +
				(self->mTwist[(uint32_t)(i+1) % (int32_t)624] &
						(int32_t)2147483647);
		         self->mTwist[i] = self->mTwist[(i + 397) % 624] ^ (y>>1);
		         if ((y % 2) != 0 ){
		            self->mTwist[i] = self->mTwist[i] ^ (2567483615);
		         }
	}

}

int getNumFunc(struct Mersenne* self){
	if(self->index){
		self->generateNum(self);
	}
	uint32_t y = self->mTwist[self->index];
	y = y ^ (y>>11);
	y = y ^ ((y<<7) & 2636928640);
	y = y ^ ((y<<15) & 4022730752);
	y = y ^ (y>>18);

	self->index = (self->index+1) % 624;
	return y;
}
