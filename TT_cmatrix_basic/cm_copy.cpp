#include "..//TT.h"

//ASM

struct cmatrix *cm_copy(struct cmatrix *origin) {
	struct cmatrix *tmp = init_cmatrix(origin->row, origin->col);
	tmp->stat = origin->stat;
	__m128 *a = (__m128*) origin->re;
	__m128 *b = (__m128*) origin->im;
	__m128 *d = (__m128*) tmp->re;
	__m128 *e = (__m128*) tmp->im;
	__asm
	{
		mov eax, a;
		mov ebx, b;
		mov edx, d;
		mov edi, e;
		mov esi, 0;
		mov ecx, ALL_TIMES;
L1:
		movaps xmm0, [eax + esi];
		movaps xmm1, [ebx + esi];
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
//struct cmatrix *cm_copy(struct cmatrix *origin) {
//	struct cmatrix *tmp = init_cmatrix(origin->row, origin->col);
//	tmp->stat = origin->stat;
//	int32_t i;
//	for (i = 0; i < MAX_NUMBER; i++) {
//		tmp->re[i] = origin->re[i];
//		tmp->im[i] = origin->im[i];
//	}
//	return tmp;
//}
