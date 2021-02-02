#include "..//TT.h"

struct matrix *m_inverse(struct matrix *origin) {
	if (origin->row != origin->col) {
		printf("Could not find inverse for\n");
		m_print(origin);
		return NULL;
	}
	float det = m_det(origin);
	if (det < TOLERANCE && det > -TOLERANCE) {
		printf("Could not find inverse for\n");
		m_print(origin);
		return NULL;
	}
	if (det == ERROR) {
		printf("Could not find inverse for\n");
		m_print(origin);
		return NULL;
	}
	int32_t i, j, ii, jj;
	float cdet;
	struct matrix *tmp = init_matrix(origin->row, origin->col);
	tmp->stat = (origin->stat & UPP << 1) + (origin->stat & LOW >> 1);
	struct matrix *adj = init_matrix(origin->row, origin->col);
	struct matrix *cof = init_matrix(origin->row - 1, origin->col - 1);
	m_zero(cof);
	for (i = 0; i < origin->row; i++) {
		for (j = 0; j < origin->col; j++) {
			for (ii = 0; ii < i; ii++) {
				for (jj = 0; jj < j; jj++) {
					cof->e[ii * MAX_SIZE + jj] = origin->e[ii * MAX_SIZE + jj];
				}
				for (jj = j + 1; jj < origin->col; jj++) {
					cof->e[ii * MAX_SIZE + jj - 1] = origin->e[ii * MAX_SIZE + jj];
				}
			}
			for (ii = i + 1; ii < origin->row; ii++) {
				for (jj = 0; jj < j; jj++) {
					cof->e[(ii - 1) * MAX_SIZE + jj] = origin->e[ii * MAX_SIZE + jj];
				}
				for (jj = j + 1; jj < origin->col; jj++) {
					cof->e[(ii - 1) * MAX_SIZE + jj - 1] = origin->e[ii * MAX_SIZE + jj];
				}
			}
			cdet = m_det(cof);
			adj->e[j * MAX_SIZE + i] = ((i+j)&1) ? -cdet : cdet;
		}
	}
	tmp = m_scalar(adj, 1 / det);
	_aligned_free(adj->e);
	_aligned_free(adj);
	_aligned_free(cof->e);
	_aligned_free(cof);
	return tmp;
}
