#include "..//TT.h"

//ASM

struct cmatrix *m_to_cm(struct matrix *origin) {
	struct cmatrix *copy = init_cmatrix(origin->row, origin->col);
	copy->stat = origin->stat;
	__m128 *a = (__m128*) origin->e;
	__m128 *d = (__m128*) copy->re;
	__m128 *e = (__m128*) copy->im;
	__asm
	{
		mov eax, a;
		mov edx, d;
		mov edi, e;
		mov esi, 0;
		andnps xmm1, xmm1
		mov ecx, ALL_TIMES;
L1:
		movaps xmm0, [eax + esi];
		movaps [edx + esi], xmm0;
		movaps [edi + esi], xmm1;
		add esi, B_WIDTH;
		loop L1;
		emms;
	}
	return copy;
}

//CPP
//
//struct cmatrix *m_to_cm(struct matrix *origin) {
//	struct cmatrix *copy = init_cmatrix(origin->row, origin->col);
//	copy->stat = origin->stat;
//	int32_t i;
//	for (i = 0; i < MAX_SIZE; i++) {
//		copy->re[i] = origin->e[i];
//		copy->im[i] = 0;
//	}
//	return copy;
//}
