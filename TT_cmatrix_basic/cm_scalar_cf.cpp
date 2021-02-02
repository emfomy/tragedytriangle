#include "..//TT.h"

//ASM

struct cmatrix *cm_scalar_cf(struct cmatrix *origin, struct cnum *x) {
	struct cmatrix *tmp = init_cmatrix(origin->row, origin->col);
	tmp->stat = origin->stat;
	__m128 *a = (__m128*) origin->re;
	__m128 *b = (__m128*) origin->im;
	__m128 *d = (__m128*) tmp->re;
	__m128 *e = (__m128*) tmp->im;
	__m128 *xr = (__m128*) &(x->re);
	__m128 *xi = (__m128*) &(x->im);
	__asm
	{
		mov eax, a;
		mov ebx, b;
		mov edx, d;
		mov edi, e;
		mov ecx, xr;
		mov esi, xi;
		movups xmm4, [ecx];
		movups xmm5, [esi];
		shufps xmm4, xmm4, 0h;
		shufps xmm5, xmm5, 0h;
		mov esi, 0;
		mov ecx, ALL_TIMES;
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
		movaps [edx + esi], xmm0;
		movaps [edi + esi], xmm3;
		add esi, B_WIDTH;
		loop L1;
		emms;
	}
	_aligned_free(x);
	return tmp;
}

//CPP
//
//struct cmatrix *cm_scalar_c(struct cmatrix *origin, struct cnum *x) {
//	struct cmatrix *tmp = init_cmatrix(origin->row, origin->col);
//	tmp->stat = origin->stat;
//	int32_t i;
//	for (i = 0; i < MAX_NUMBER; i++) {
//		tmp->re[i] = origin->re[i] * x->re - origin->im[i] * x->im;
//		tmp->im[i] = origin->re[i] * x->im + origin->im[i] * x->re;
//	}
//	return tmp;
//}
