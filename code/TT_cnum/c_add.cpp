#include "..//TT.h"

struct cnum *c_add(struct cnum *A, struct cnum *B) {
	return init_cnum(A->re + B->re, A->im + B->im);
}

struct cnum *c_add_s(struct cnum *x, float re, float im) {
	return init_cnum(x->re + re, x->im + im);
}

