#include "..//TT.h"

//ASM

int32_t r_mul(struct matrix *origin, int32_t i, float x) {
	__m128 *a = (__m128*) origin->e;
	__m128 *d = (__m128*) & x;
	__asm
	{
		mov eax, i;
		shl eax, M_WIDTH_LOG;
		add eax, a;
		mov edx, d;
		movups xmm1, [edx];
		shufps xmm1, xmm1, 0h;
		mov ecx, MAX_SIZE_B;
L1:
		movaps xmm0, [eax];
		mulps xmm0, xmm1;
		movaps [eax], xmm0;
		add eax, B_WIDTH;
		loop L1;
		emms;
	}
	return (EXIT_SUCCESS);
}

//CPP
//
//int32_t r_mul(struct matrix *origin, int32_t i, float x) {
//	int32_t k;
//	for (k = 0; k < MAX_SIZE; k++) {
//		origin->e[i * MAX_SIZE + k] *= x;
//	}
//	return (EXIT_SUCCESS);
//}
