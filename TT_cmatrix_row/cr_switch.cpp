#include "..//TT.h"

//ASM

int32_t cr_switch(struct cmatrix *origin, int32_t i, int32_t j) {
	__m128 *a = (__m128*) origin->re;
	__m128 *d = (__m128*) origin->im;
	__asm
	{
		mov eax, i;
		shl eax, M_WIDTH_LOG;
		mov edx, eax
		add eax, a;
		add edx, d;

		mov ebx, j;
		shl ebx, M_WIDTH_LOG;
		mov edi, ebx
		add ebx, a;
		add edi, d;

		mov esi, 0;
		mov ecx, MAX_SIZE_B;
L1:
		movaps xmm0, [eax + esi];
		movaps xmm1, [ebx + esi];
		movaps xmm2, [edx + esi];
		movaps xmm3, [edi + esi];
		movaps [eax + esi], xmm1;
		movaps [ebx + esi], xmm0;
		movaps [edx + esi], xmm3;
		movaps [edi + esi], xmm2;
		add esi, B_WIDTH;
		loop L1;
		emms;
	}
	return (EXIT_SUCCESS);
}

//CPP
//
//int32_t cr_switch(struct cmatrix *origin, int32_t i, int32_t j) {
//	float tmp;
//	int32_t k;
//	for (k = 0; k < MAX_SIZE; k++) {
//		tmp = origin->re[i*MAX_SIZE+k];
//		origin->re[i*MAX_SIZE+k] = origin->re[j*MAX_SIZE+k];
//		origin->re[j*MAX_SIZE+k] = tmp;
//		tmp = origin->im[i*MAX_SIZE+k];
//		origin->im[i*MAX_SIZE+k] = origin->im[j*MAX_SIZE+k];
//		origin->im[j*MAX_SIZE+k] = tmp;
//	}
//    return (EXIT_SUCCESS);
//}
