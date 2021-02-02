#include "..//TT.h"

//ASM

struct cmatrix *cm_sub(struct cmatrix *matrixA, struct cmatrix *matrixB) {
	if (matrixA->row != matrixB->row || matrixA->col != matrixB->col) {
		printf("Could not substract\n");
		cm_print(matrixA);
		printf("by\n");
		cm_print(matrixB);
		return NULL;
	}
	struct cmatrix *tmp = init_cmatrix(matrixA->row, matrixA->col);
	tmp->stat = matrixA->stat & matrixB->stat;
	__m128 *a = (__m128*) matrixA->re;
	__m128 *b = (__m128*) matrixB->re;
	__m128 *d = (__m128*) tmp->re;
	__asm
	{
		mov eax, a;
		mov ebx, b;
		mov edx, d;
		mov esi, 0;
		mov ecx, ALL_TIMES2;
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
//
//struct cmatrix *cm_sub(struct cmatrix *matrixA, struct cmatrix *matrixB) {
//	if (matrixA->row != matrixB->row || matrixA->col != matrixB->col) {
//		printf("Could not substract\n");
//		cm_print(matrixA);
//		printf("by\n");
//		cm_print(matrixB);
//		return NULL;
//	}
//	struct cmatrix *tmp = init_cmatrix(matrixA->row, matrixA->col);
//	tmp->stat = matrixA->stat & matrixB->stat;
//	int32_t i;
//	for (i = 0; i < MAX_NUMBER; i++) {
//		tmp->re[i] = matrixA->re[i] - matrixB->re[i];
//		tmp->im[i] = matrixA->im[i] - matrixB->im[i];
//	}
//	return tmp;
//}
