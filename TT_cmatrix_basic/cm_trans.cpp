#include "..//TT.h"

//ASM

struct cmatrix *cm_trans(struct cmatrix *origin) {
	struct cmatrix *tmp = init_cmatrix(origin->col, origin->row);
	tmp->stat = (origin->stat & UPP << 1) + (origin->stat & LOW >> 1);
	__m128 *a = (__m128*) origin->re;
	__m128 *aa = (__m128*) origin->im;
	__m128 *d = (__m128*) tmp->re;
	__m128 *dd = (__m128*) tmp->im;
	__asm
	{
		mov esi, a;
		mov edi, d;
		mov ecx, MAX_SIZE_B;
L1:
		mov eax, esi;
		mov edx, edi;
		push ecx;
		mov ecx, MAX_SIZE_B;
L2:
		movaps xmm0, [eax];
		movaps xmm1, [eax + M_WIDTH];
		movaps xmm2, [eax + M_WIDTH2];
		movaps xmm3, [eax + M_WIDTH3];
		movaps xmm4, xmm0;
		movaps xmm5, xmm1;
		unpcklps xmm0, xmm2;
		unpcklps xmm1, xmm3;
		unpckhps xmm4, xmm2;
		unpckhps xmm5, xmm3;
		movaps xmm2, xmm0;
		movaps xmm3, xmm4;
		unpcklps xmm0, xmm1;
		unpcklps xmm4, xmm5;
		unpckhps xmm2, xmm1;
		unpckhps xmm3, xmm5;
		movaps [edx], xmm0;
		movaps [edx + M_WIDTH], xmm2;
		movaps [edx + M_WIDTH2], xmm4;
		movaps [edx + M_WIDTH3], xmm3;
		add eax, B_WIDTH;
		add edx, B_HEIGHT;
		loop L2;
		pop ecx;
		add esi, B_HEIGHT;
		add edi, B_WIDTH;
		loop L1;

		mov esi, aa;
		mov edi, dd;
		mov ecx, MAX_SIZE_B;
L3:
		mov eax, esi;
		mov edx, edi;
		push ecx;
		mov ecx, MAX_SIZE_B;
L4:
		movaps xmm0, [eax];
		movaps xmm1, [eax + M_WIDTH];
		movaps xmm2, [eax + M_WIDTH2];
		movaps xmm3, [eax + M_WIDTH3];
		movaps xmm4, xmm0;
		movaps xmm5, xmm1;
		unpcklps xmm0, xmm2;
		unpcklps xmm1, xmm3;
		unpckhps xmm4, xmm2;
		unpckhps xmm5, xmm3;
		movaps xmm2, xmm0;
		movaps xmm3, xmm4;
		unpcklps xmm0, xmm1;
		unpcklps xmm4, xmm5;
		unpckhps xmm2, xmm1;
		unpckhps xmm3, xmm5;
		movaps [edx], xmm0;
		movaps [edx + M_WIDTH], xmm2;
		movaps [edx + M_WIDTH2], xmm4;
		movaps [edx + M_WIDTH3], xmm3;
		add eax, B_WIDTH;
		add edx, B_HEIGHT;
		loop L4;
		pop ecx;
		add esi, B_HEIGHT;
		add edi, B_WIDTH;
		loop L3;
		emms;
	}
	return tmp;
}

//CPP
//
//struct cmatrix *cm_trans(struct cmatrix *origin) {
//	struct cmatrix *tmp = init_cmatrix(origin->col, origin->row);
//	tmp->stat = origin->stat;
//	int32_t i, j;
//	for (i = 0; i < MAX_SIZE; i++)
//		for (j = 0; j < MAX_SIZE; j++) {
//			tmp->re[i * MAX_SIZE + j] = origin->re[j * MAX_SIZE + i];
//			tmp->im[i * MAX_SIZE + j] = origin->im[j * MAX_SIZE + i];
//		}
//	return tmp;
//}
