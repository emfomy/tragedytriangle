#include "..//TT.h"

struct matrix *init_matrix(int32_t row, int32_t col) {
	struct matrix *tmp = (struct matrix*) _aligned_malloc(sizeof (struct matrix), 16);
	tmp->row = row;
	tmp->col = col;
	tmp->stat = DEFAULT;
	tmp->e = (float*) _aligned_malloc(sizeof (float) * MAX_SIZE * MAX_SIZE, 16);
	return tmp;
}
