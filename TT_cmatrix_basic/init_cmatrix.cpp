#include "..//TT.h"

struct cmatrix *init_cmatrix(int32_t row, int32_t col) {
	struct cmatrix *tmp = (struct cmatrix*) _aligned_malloc(sizeof (struct cmatrix), 16);
	tmp->row = row;
	tmp->col = col;
	tmp->stat = DEFAULT;
	tmp->re = (float*) _aligned_malloc(sizeof (float) * MAX_NUMBER2, 16);
	tmp->im = tmp->re + MAX_NUMBER;
	return tmp;
}
