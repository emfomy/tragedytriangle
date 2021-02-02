#include "..//TT.h"

//ASM

int32_t cr_mul_c(struct cmatrix *origin, int32_t i, cnum* x) {
	__m128 *a = (__m128*) origin->re;
	__m128 *b = (__m128*) origin->im;
	__m128 *d = (__m128*) &(x->re);
	__m128 *e = (__m128*) &(x->im);
	__asm
	{
		mov eax, i;
		shl eax, M_WIDTH_LOG;
		mov ebx, eax;
		add eax, a;
		add ebx, b;

		mov edx, d;
		mov edi, e;
		movups xmm4, [edx];
		movups xmm5, [edi];
		shufps xmm4, xmm4, 0h;
		shufps xmm5, xmm5, 0h;

		mov esi, 0;
		mov ecx, MAX_SIZE_B;
L1:
		movaps xmm0, [eax + esi];
		movaps xmm1, [ebx + esi];
		movaps xmm2, xmm0;
		movaps xmm3, xmm1;
		mulps xmm0, xmm4;
		mulps xmm1, xmm5;
		mulps xmm3, xmm4;
		mulps xmm2, xmm5;
		subps xmm0, xmm1;
		addps xmm3, xmm2;
		movaps [eax + esi], xmm0;
		movaps [ebx + esi], xmm3;
		add esi, B_WIDTH;
		loop L1;
		emms;
	}
	return (EXIT_SUCCESS);
}

//CPP
//
//int32_t cr_mul_c(struct cmatrix *origin, int32_t i, cnum* x) {
//	struct cnum *tmp;
//	int32_t k;
//	for (k = 0; k < MAX_SIZE; k++) {
//		tmp = c_mul_s(x, origin->re[i * MAX_SIZE + k], origin->im[i * MAX_SIZE + k]);
//		origin->re[i * MAX_SIZE + k] = tmp->re;
//		origin->im[i * MAX_SIZE + k] = tmp->im;
//	}
//	return (EXIT_SUCCESS);
//}
