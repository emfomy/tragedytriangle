#include "..//TT.h"

//ASM

int32_t cm_zero(struct cmatrix *origin) {
	__m128 *a = (__m128*) origin->re;
	__m128 *b = (__m128*) origin->im;
	__asm
	{
		andnps xmm0, xmm0;
		mov eax, a;
		mov ebx, b;
		mov esi, 0;
		mov ecx, ALL_TIMES;
L1:
		movaps [eax+esi], xmm0;
		movaps [ebx+esi], xmm0;
		add esi, B_WIDTH;
		loop L1;
		emms;
	}
	return (EXIT_SUCCESS);
}

//CPP
//
//int32_t cm_zero(struct cmatrix *origin) {
//	int32_t i;
//	for (i = 0; i < MAX_NUMBER; i++) {
//		origin->im[i] = 0;
//		origin->re[i] = 0;
//	}
//	return (EXIT_SUCCESS);
//}
