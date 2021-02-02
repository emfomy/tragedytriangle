#include "..//TT.h"

struct cnum *c_scalar(struct cnum *A, float x) {
	return init_cnum(A->re *x, A->im * x);
}
