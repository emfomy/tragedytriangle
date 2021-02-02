#include "..//TT.h"

struct cnum *c_copy(struct cnum *origin) {
	return init_cnum(origin->re, origin->im);
}
