#include "..//TT.h"

struct cnum *c_mul(struct cnum *A, struct cnum *B) {
	return init_cnum(A->re * B->re - A->im * B->im, A->re * B->im + A->im * B->re);
}

struct cnum *c_mul_f(struct cnum *A, struct cnum *B) {
	cnum *tmp = init_cnum(A->re * B->re - A->im * B->im, A->re * B->im + A->im * B->re);
	_aligned_free(A);
	return tmp;
}

struct cnum *c_mul_s(struct cnum *x, float re, float im) {
	return init_cnum(x->re * re - x->im * im, x->re * im + x->im * re);
}

struct cnum *c_mul_sf(struct cnum *x, float re, float im) {
	cnum *tmp = init_cnum(x->re * re - x->im * im, x->re * im + x->im * re);
	_aligned_free(x);
	return tmp;
}
