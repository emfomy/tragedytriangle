#include "..//TT.h"

struct cmatrix *cm_inverse(struct cmatrix *origin) {
	if (origin->row != origin->col) {
		printf("Could not find inverse for\n");
		cm_print(origin);
		return NULL;
	}
	struct cnum *det = cm_det(origin);
	if (c_equal0(det)) {
		printf("Could not find inverse for\n");
		cm_print(origin);
		return NULL;
	}
	int32_t i, j, ii, jj;
	cnum *cdet;
	struct cmatrix *tmp = init_cmatrix(origin->row, origin->col);
	tmp->stat = (origin->stat & UPP << 1) + (origin->stat & LOW >> 1);
	struct cmatrix *adj = init_cmatrix(origin->row, origin->col);
	struct cmatrix *cof = init_cmatrix(origin->row - 1, origin->col - 1);
	cm_zero(cof);
	for (i = 0; i < origin->row; i++) {
		for (j = 0; j < origin->col; j++) {
			for (ii = 0; ii < i; ii++) {
				for (jj = 0; jj < j; jj++) {
					cof->re[ii * MAX_SIZE + jj] = origin->re[ii * MAX_SIZE + jj];
					cof->im[ii * MAX_SIZE + jj] = origin->im[ii * MAX_SIZE + jj];
				}
				for (jj = j + 1; jj < origin->col; jj++) {
					cof->re[ii * MAX_SIZE + jj - 1] = origin->re[ii * MAX_SIZE + jj];
					cof->im[ii * MAX_SIZE + jj - 1] = origin->im[ii * MAX_SIZE + jj];
				}
			}
			for (ii = i + 1; ii < origin->row; ii++) {
				for (jj = 0; jj < j; jj++) {
					cof->re[(ii - 1) * MAX_SIZE + jj] = origin->re[ii * MAX_SIZE + jj];
					cof->im[(ii - 1) * MAX_SIZE + jj] = origin->im[ii * MAX_SIZE + jj];
				}
				for (jj = j + 1; jj < origin->col; jj++) {
					cof->re[(ii - 1) * MAX_SIZE + jj - 1] = origin->re[ii * MAX_SIZE + jj];
					cof->im[(ii - 1) * MAX_SIZE + jj - 1] = origin->im[ii * MAX_SIZE + jj];
				}
			}
			cdet = cm_det(cof);
			adj->re[j * MAX_SIZE + i] = ((i+j)&1) ? -cdet->re : cdet->re;
			adj->im[j * MAX_SIZE + i] = ((i+j)&1) ? -cdet->im : cdet->im;
		}
	}
	tmp = cm_scalar_cf(adj, c_div1_f(det));
	_aligned_free(adj->re);
	_aligned_free(adj);
	_aligned_free(cof->re);
	_aligned_free(cof);
	return tmp;
}
