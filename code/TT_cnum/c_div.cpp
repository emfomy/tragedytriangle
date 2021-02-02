#include "..//TT.h"

struct cnum *c_div(struct cnum *A, struct cnum *B) {
	return c_scalar(c_mul(A, c_conj(B)), 1 / c_abs2_s(B->re,  B->im));
}

struct cnum *c_div_fh(struct cnum *A, struct cnum *B) {
	cnum *tmp = c_scalar(c_mul(A, c_conj(B)), 1 / c_abs2_s(B->re,  B->im));
	_aligned_free(A);
	return tmp;
}

struct cnum *c_div_fl(struct cnum *A, struct cnum *B) {
	cnum *tmp = c_scalar(c_mul(A, c_conj(B)), 1 / c_abs2_s(B->re,  B->im));
	_aligned_free(B);
	return tmp;
}

struct cnum *c_div_sh(float re, float im, struct cnum *x) {
	return c_scalar(c_mul_s(c_conj(x), re, im), 1 / c_abs2_s(x->re, x->im));
}

struct cnum *c_div_shf(float re, float im, struct cnum *x) {
	cnum *tmp = c_scalar(c_mul_s(c_conj(x), re, im), 1 / c_abs2_s(x->re, x->im));
	_aligned_free(x);
	return tmp;
}

struct cnum *c_div_sl(struct cnum *x, float re, float im) {
	return c_scalar(c_mul_s(x, re, -im), 1 / c_abs2_s(re, im));
}

struct cnum *c_div_slf(struct cnum *x, float re, float im) {
	cnum *tmp = c_scalar(c_mul_s(x, re, -im), 1 / c_abs2_s(re, im));
	_aligned_free(x);
	return tmp;
}

struct cnum *c_div1(struct cnum *x) {
	return c_scalar(c_conj(x), 1 / c_abs2(x));
}

struct cnum *c_div1_f(struct cnum *x) {
	cnum *tmp = c_scalar(c_conj(x), 1 / c_abs2(x));
	_aligned_free(x);
	return tmp;
}

struct cnum *c_div1_s(float re, float im) {
	return c_scalar(c_conj_s(re, im), 1 / c_abs2_s(re, im));
}
