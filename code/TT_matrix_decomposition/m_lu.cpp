#include "..//TT.h"

//for all elements bigger than e-10

int32_t m_lu(struct matrix *origin, struct matrix *matrixL, struct matrix *matrixU, struct matrix *matrixP) {
	int32_t i, j;
	int32_t n;
	int32_t n1;
	int32_t over;
	float tmp, *tmpL;

	matrixP->stat = DEFAULT;
	matrixL->stat = LOW;
	m_zero(matrixP);
	m_zero(matrixL);
	tmpL = (float *) _aligned_malloc(sizeof (float) * MAX_SIZE, 16);
	for (i = 0; i < MAX_NUMBER; i++) matrixU->e[i] = origin->e[i];
	matrixU->col = origin->col;
	matrixU->row = origin->row;
	if (matrixU->col == matrixU->row) matrixU->stat = UPP;

	for (i = 0; i < matrixP->row; i++) matrixP->e[i * MAX_SIZE + i] = 1;
	for (i = 0; i < matrixL->row; i++) matrixL->e[i * MAX_SIZE + i] = 1;

	for (n = 0; n < matrixU->row && n < matrixU->col; n++) {
		over = 0;
		n1 = n;
		for (i = 0; i < n; i++) tmpL[i] = 0;
		while (matrixU->e[n1 * MAX_SIZE + n] < TOLERANCE && matrixU->e[n1 * MAX_SIZE + n] > TOLERANCE) {
			n1 += 1;
			if (n1 >= matrixU->row) {
				over = 1;
				break;
			}
		}
		if (over == 1) continue;
		r_switch(matrixU, n, n1);
		r_switch(matrixP, n, n1);
		for (i = 0; i < n; i++) {
			tmp = matrixL->e[n * MAX_SIZE + i];
			matrixL->e[n * MAX_SIZE + i] = matrixL->e[n1 * MAX_SIZE + i];
			matrixL->e[n1 * MAX_SIZE + i] = tmp;
		}
		tmpL[n] = 1;
		for (i = n + 1; i < matrixU->row; i++) {
			tmpL[i] = matrixU->e[i * MAX_SIZE + n] / matrixU->e[n * MAX_SIZE + n];
			r_add(matrixU, i, n, -tmpL[i]);
		}
		for (i = n; i < matrixL->col; i++) {
			tmp = 0;
			for (j = 0; j < matrixL->col; j++) {
				tmp += (matrixL->e[i * MAX_SIZE + j]) * (tmpL[j]);
			}
			matrixL->e[i * MAX_SIZE + n] = tmp;
		}

	}
	_aligned_free(tmpL);
	return EXIT_SUCCESS;
}
