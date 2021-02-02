#include "..//TT.h"

float c_abs2(struct cnum *x){
	return (x->re * x->re + x->im * x->im);
}

float c_abs2_s(float re, float im){
	return (re *re + im * im);
}
