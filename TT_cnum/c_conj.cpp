#include "..//TT.h"

struct cnum *c_conj(struct cnum *A) {
	return init_cnum(A->re, -A->im);
}

struct cnum *c_conj_s(float re, float im) {
	return init_cnum(re, -im);
}

