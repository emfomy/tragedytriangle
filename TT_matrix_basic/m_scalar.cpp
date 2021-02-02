#include "..//TT.h"

//ASM

struct matrix *m_scalar(struct matrix *origin, float x) {
	struct matrix *tmp = init_matrix(origin->row, origin->col);
	tmp->stat = origin->stat;
	__m128 *a = (__m128*) origin->e;
	__m128 *b = (__m128*) &x;
	__m128 *d = (__m128*) tmp->e;
	__asm
	{
		mov eax, a;
		mov ebx, b;
		mov edx, d;
		mov esi, 0;
		movups xmm1, [ebx];
		shufps xmm1, xmm1, 0h;
		mov ecx, ALL_TIMES;
L1:
		movaps xmm0, [eax + esi];
		mulps xmm0, xmm1;
		movaps [edx + esi], xmm0;
		add esi, B_WIDTH;
		loop L1;
		emms;
	}
	return tmp;
}

//CPP
//
//struct matrix *m_scalar(struct matrix *origin, int32_t x) {
//	struct matrix *tmp = init_matrix(origin->row, origin->col);
//	int32_t i;
//    for (i = 0; i < MAX_NUMBER; i++)
//            tmp->e[i] = matrixA->e[i] * x;
//	return tmp;
//}
