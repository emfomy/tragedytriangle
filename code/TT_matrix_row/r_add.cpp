#include "..//TT.h"

//ASM

int32_t r_add(struct matrix *origin, int32_t i, int32_t j, float x) {
	__m128 *a = (__m128*) origin->e;
	__m128 *d = (__m128*) &x;
	__asm
	{
		mov eax, i;
		mov ebx, j;
		shl eax, M_WIDTH_LOG;
		shl ebx, M_WIDTH_LOG;
		add eax, a;
		add ebx, a;
		mov edx, d;
		movups xmm1, [edx];
		shufps xmm1, xmm1, 0h;
		mov esi, 0;
		mov ecx, MAX_SIZE_B;
L1:
		movaps xmm0, [ebx + esi];
		mulps xmm0, xmm1;
		addps xmm0, [eax + esi];
		movaps [eax + esi], xmm0;
		add esi, B_WIDTH;
		loop L1;
		emms;
	}
	return (EXIT_SUCCESS);
}

//CPP
//
//int32_t r_add(struct matrix *origin, int32_t i, int32_t j, float x) {
//	int32_t k;
//	for (k = 0; k < MAX_SIZE; k++) {
//		origin->e[i * MAX_SIZE + k] += origin->e[j * MAX_SIZE + k] * x;
//	}
//	return (EXIT_SUCCESS);
//}
