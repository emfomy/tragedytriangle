#include "..//TT.h"

//ASM

struct matrix *m_mul(struct matrix *matrixA, struct matrix *matrixB) {
	if (matrixA->col != matrixB->row) {
		printf("Could not multiply\n");
		m_print(matrixA);
		printf("by\n");
		m_print(matrixB);
		return NULL;
	}
	struct matrix *tmp = init_matrix(matrixA->row, matrixB->col);
	tmp->stat = matrixA->stat & matrixB->stat;
	struct matrix *matrixBT = m_trans(matrixB);
	__m128 *a = (__m128*) matrixA->e;
	__m128 *b = (__m128*) matrixBT->e;
	__m128 *d = (__m128*) tmp->e;
	__asm
	{
		andnps xmm7, xmm7

		mov eax, a;
		mov edx, d;
		mov ecx, MAX_SIZE;
L1:
		push ecx;
		mov ebx, b;

		mov ecx, MAX_SIZE_B;
L2:
		push ecx;

		movaps xmm0, xmm7;
		mov esi, 0;
		mov ecx, MAX_SIZE_B;
L3a:
		movaps xmm4, [eax + esi];
		mulps xmm4, [ebx + esi];
		addps xmm0, xmm4;
		add esi, B_WIDTH;
		loop L3a;

		add ebx, M_WIDTH;
		movaps xmm1, xmm7;
		mov esi, 0;
		mov ecx, MAX_SIZE_B;
L3b:
		movaps xmm4, [eax + esi];
		mulps xmm4, [ebx + esi];
		addps xmm1, xmm4;
		add esi, B_WIDTH;
		loop L3b;

		add ebx, M_WIDTH;
		movaps xmm2, xmm7;
		mov esi, 0;
		mov ecx, MAX_SIZE_B;
L3c:
		movaps xmm4, [eax + esi];
		mulps xmm4, [ebx + esi];
		addps xmm2, xmm4;
		add esi, B_WIDTH;
		loop L3c;

		add ebx, M_WIDTH;
		movaps xmm3, xmm7;
		mov esi, 0;
		mov ecx, MAX_SIZE_B;
L3d:
		movaps xmm4, [eax + esi];
		mulps xmm4, [ebx + esi];
		addps xmm3, xmm4;
		add esi, B_WIDTH;
		loop L3d;

		haddps xmm0, xmm1;
		haddps xmm2, xmm3;
		haddps xmm0, xmm2;
		movaps [edx], xmm0;

		add ebx, M_WIDTH;
		add edx, B_WIDTH;
		pop ecx;
		dec ecx;
		jnz L2;

		add eax, M_WIDTH;
		pop ecx;
		dec ecx;
		jnz L1;

		emms;
	}
	_aligned_free(matrixBT->e);
	_aligned_free(matrixBT);
	return tmp;
}

//CPP
//
//struct matrix *m_mul(struct matrix *matrixA, struct matrix *matrixB) {
//	if (matrixA->col != matrixB->row) {
//		printf("Could not multiply\n");
//		m_print(matrixA);
//		printf("by\n");
//		m_print(matrixB);
//		return NULL;
//	}
//	struct matrix *tmp = init_matrix(matrixA->row, matrixB->col);
//	tmp->stat = matrixA->stat & matrixB->stat;
//	int32_t i, j, k;
//	for (i = 0; i < MAX_SIZE; i++) {
//		for (j = 0; j < MAX_SIZE; j++) {
//			tmp->e[i * MAX_SIZE + j] = 0;
//			for (k = 0; k < MAX_SIZE; k++) {
//				tmp->e[i * MAX_SIZE + j] += matrixA->e[i * MAX_SIZE + k] * matrixB->e[k * MAX_SIZE + j];
//			}
//		}
//	}
//	return tmp;
//}
