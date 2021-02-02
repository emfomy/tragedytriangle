#include "..//TT.h"

//ASM

struct matrix *m_copy(struct matrix *origin) {
	struct matrix *tmp = init_matrix(origin->row, origin->col);
	tmp->stat = origin->stat;
	__m128 *a = (__m128*) origin->e;
	__m128 *d = (__m128*) tmp->e;
	__asm
	{
		mov eax, a;
		mov edx, d;
		mov esi, 0;
		mov ecx, ALL_TIMES;
L1:
		movaps xmm0, [eax + esi];
		movaps [edx + esi], xmm0;
		add esi, B_WIDTH;
		loop L1;
		emms;
	}
	return tmp;
}

//CPP
//
//struct matrix *m_copy(struct matrix *origin) {
//	struct matrix *tmp = init_matrix(origin->row, origin->col);
//	tmp->stat = origin->stat;
//	int32_t i;
//	for (i = 0; i < MAX_NUMBER; i++)
//			tmp->e[i] = origin->e[i];
//	return tmp;
//}