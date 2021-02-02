#include "..//TT.h"

//ASM

struct matrix *m_sub(struct matrix *matrixA, struct matrix *matrixB) {
	if (matrixA->row != matrixB->row || matrixA->col != matrixB->col) {
		printf("Could not substract\n");
		m_print(matrixA);
		printf("by\n");
		m_print(matrixB);
		return NULL;
	}
	struct matrix *tmp = init_matrix(matrixA->row, matrixA->col);
	tmp->stat = matrixA->stat & matrixB->stat;
	__m128 *a = (__m128*) matrixA->e;
	__m128 *b = (__m128*) matrixB->e;
	__m128 *d = (__m128*) tmp->e;
	__asm
	{
		mov eax, a;
		mov ebx, b;
		mov edx, d;
		mov esi, 0;
		mov ecx, ALL_TIMES;
L1:
		movaps xmm0, [eax + esi];
		subps xmm0, [ebx + esi];
		movaps [edx + esi], xmm0;
		add esi, B_WIDTH;
		loop L1;
		emms;
	}
	return tmp;
}


//CPP

//struct matrix *m_sub(struct matrix *matrixA, struct matrix *matrixB) {
//	if (matrixA->row != matrixB->row || matrixA->col != matrixB->col) {
//		printf("Could not substract\n");
//		m_print(matrixA);
//		printf("by\n");
//		m_print(matrixB);
//		return NULL;
//	}
//	struct matrix *tmp = init_matrix(matrixA->row, matrixA->col);
//	tmp->stat = matrixA->stat & matrixB->stat;
//	int32_t i;
//	for (i = 0; i < MAX_NUMBER; i++)
//			tmp->e[i] = matrixA->e[i] - matrixB->e[i];
//	return tmp;
//}
