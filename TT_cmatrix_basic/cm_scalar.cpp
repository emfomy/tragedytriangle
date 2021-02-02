#include "..//TT.h"

//ASM

struct cmatrix *cm_scalar(struct cmatrix *origin, float x) {
	struct cmatrix *tmp = init_cmatrix(origin->row, origin->col);
	tmp->stat = origin->stat;
	__m128 *a = (__m128*) origin->re;
	__m128 *b = (__m128*) origin->im;
	__m128 *d = (__m128*) tmp->re;
	__m128 *e = (__m128*) tmp->im;
	__m128 *xx = (__m128*) &x;
	__asm
	{
		mov eax, a;
		mov ebx, b;
		mov edx, d;
		mov edi, e;
		mov esi, xx;
		movups xmm2, [esi];
		shufps xmm2, xmm2, 0h;
		mov esi, 0;
		mov ecx, ALL_TIMES;
L1:
		movaps xmm0, [eax + esi];
		movaps xmm1, [ebx + esi];
		mulps xmm0, xmm2;
		mulps xmm1, xmm2;
		movaps [edx + esi], xmm0;
		movaps [edi + esi], xmm1;
		add esi, B_WIDTH;
		loop L1;
		emms;
	}
	return tmp;
}

//CPP
//
//struct cmatrix *cm_scalar(struct cmatrix *origin, float x) {
//	struct cmatrix *tmp = init_cmatrix(origin->row, origin->col);
//	tmp->stat = origin->stat;
//	int32_t i;
//	for (i = 0; i < MAX_NUMBER; i++) {
//		tmp->re[i] = origin->re[i] * x;
//		tmp->im[i] = origin->im[i] * x;
//	}
//	return tmp;
//}
