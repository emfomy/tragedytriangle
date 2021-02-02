#include "..//TT.h"

int32_t c_equal(struct cnum *A, struct cnum *B) {
	if ((A->re == B->re) && (A->im == B->im)) {
		return EQ;
	} else {
		return NEQ;
	}
}

int32_t c_equal_s(struct cnum *x, float re, float im) {
	if ((x->re == re) && (x->im == im)) {
		return EQ;
	} else {
		return NEQ;
	}
}


int32_t c_equal0(struct cnum *x) {
	if (x->re < TOLERANCE && x->re > -TOLERANCE && x->im < TOLERANCE && x->im > -TOLERANCE) {
		return EQ;
	} else {
		return NEQ;
	}
}
