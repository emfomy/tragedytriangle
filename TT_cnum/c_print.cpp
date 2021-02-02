#include "..//TT.h"

int32_t c_print(struct cnum *x) {
	printf("(%+8.3f %+8.3fi)", x->re + TOLERANCE, x->im + TOLERANCE);
	return (EXIT_SUCCESS);
}

int32_t c_print_s(float re, float im) {
	printf("(%+8.3f %+8.3fi)", re + TOLERANCE, im + TOLERANCE);
	return (EXIT_SUCCESS);
}
