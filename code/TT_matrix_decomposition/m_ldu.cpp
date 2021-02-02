#include "..//TT.h"

int32_t m_ldu(struct matrix *origin, struct matrix *matrixL, struct matrix *matrixD, struct matrix *matrixU, struct matrix *matrixP) {
	int i, j;
	for (i = 0; i < MAX_NUMBER; i++) matrixD->e[i] = 0;
	m_lu(origin, matrixL, matrixU, matrixP);
	for (i = 0; i < matrixL->row; i++) {
		for (j = 0; j < matrixL->row; j++) {
			if (matrixU->e[i * MAX_SIZE + j] > TOLERANCE || matrixU->e[i * MAX_SIZE + j]<-TOLERANCE) {
				matrixD->e[i * MAX_SIZE + i] = matrixU->e[i * MAX_SIZE + j];
				r_mul(matrixU, i, 1 / matrixU->e[i * MAX_SIZE + j]);
				break;
			}
		}
	}
	return EXIT_SUCCESS;
}
