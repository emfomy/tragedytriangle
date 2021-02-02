#include "..//TT.h"

struct cnum *c_sub(struct cnum *A, struct cnum *B) {
	return init_cnum(A->re - B->re, A->im - B->im);
}

struct cnum *c_sub_sl(struct cnum *x, float re, float im) {
	return init_cnum(x->re - re, x->im - im);
}

struct cnum *c_sub_sh(float re, float im, struct cnum *x) {
	return init_cnum(re - x->re, im - x->im);
}
