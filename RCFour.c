// Matthew Roddy (14212384)

#include "RCFour.h"

RC RCObj = {
		.keyLength=4,
		.i = 0,
		.init=initFunc,
		.getNum=getNumFuncRC
};

int keyIndex(struct RC* self, int i){
	int tmp;
	tmp = (self->key >> (4 * i))& 0xff;
	return tmp;

}

void initFunc(struct RC* self, int32_t seedInt){
	self->i=0;
	self->j=0;
	self->key = 2244614371U ^ seedInt;
	int i,tmp;
	for (i=0;i<256; i++ ){
		self->S[i]= i;
		self->T[i]= keyIndex(self,i % self->keyLength);
	}
	//Initial permutation
	for(i=0;i<256;i++){
		self->j=(self->j +self->S[i] + self->T[i])%256;
		//swap
		tmp = self->S[i];
		self->S[i]=self->S[self->j];
		self->S[self->j]=tmp;
	}
}

int32_t getNumFuncRC(struct RC* self){
	int32_t k,tmp,t,y;
	k=0;
	for(y=0;y<4;y++){
		self->i = (self->i +1)%256;
		self->j = (self->j + self->S[self->i])%256;
		tmp = self->S[self->i];
		self->S[self->i]=self->S[self->j];
		self->S[self->j]=tmp;
		t=(self->S[self->i]+self->S[self->j])%256;
		k=(k<<(8)) + self->S[t];
	}
	return k;
}
