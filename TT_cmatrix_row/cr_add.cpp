#include "..//TT.h"

//ASM

int32_t cr_add(struct cmatrix *origin, int32_t i, int32_t j, float x) {
	__m128 *a = (__m128*) origin->re;
	__m128 *b = (__m128*) origin->im;
	__m128 *d = (__m128*) &x;
	__asm
	{
		mov eax, i;
		shl eax, M_WIDTH_LOG;
		mov ebx, eax;
		add eax, a;
		add ebx, b;

		mov edi, j;
		sub edi, i;
		shl edi, M_WIDTH_LOG;

		mov edx, d;
		movups xmm2, [edx];
		shufps xmm2, xmm2, 0h;

		mov esi, 0;
		mov ecx, MAX_SIZE_B;
L1:
		movaps xmm0, [eax + edi];
		movaps xmm1, [ebx + edi];
		mulps xmm0, xmm2;
		mulps xmm1, xmm2;
		addps xmm0, [eax + esi];
		addps xmm1, [ebx + esi];
		movaps [eax + esi], xmm0;
		movaps [ebx + esi], xmm1;
		add esi, B_WIDTH;
		add edi, B_WIDTH;
		loop L1;
		emms;
	}
	return (EXIT_SUCCESS);
}

//CPP
//
//int32_t cr_add(struct cmatrix *origin, int32_t i, int32_t j, float x) {
//	int32_t k;
//	for (k = 0; k < MAX_SIZE; k++) {
//		origin->re[i * MAX_SIZE + k] += origin->re[j * MAX_SIZE + k] * x;
//		origin->im[i * MAX_SIZE + k] += origin->im[j * MAX_SIZE + k] * x;
//	}
//	return (EXIT_SUCCESS);
//}
