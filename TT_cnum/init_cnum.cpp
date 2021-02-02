#include "..//TT.h"

struct cnum *init_cnum(float re, float im) {
	struct cnum *tmp = (struct cnum*) _aligned_malloc(sizeof (struct cnum), 16);
	tmp->re = re;
	tmp->im = im;
	return tmp;
}
