#include "..//TT.h"

//ASM

int32_t m_zero(struct matrix *origin) {
	__m128 *a = (__m128*) origin->e;
	__asm
	{
		andnps xmm0, xmm0;
		mov eax, a;
		mov ecx, ALL_TIMES;
L1:
		movaps [eax], xmm0;
		add eax, B_WIDTH;
		loop L1;
		emms;
	}
	return (EXIT_SUCCESS);
}

//CPP
//
//int32_t m_zero(struct matrix *origin) {
//	int32_t i;
//	for (i = 0; i < MAX_NUMBER; i++)
//		origin->e[i] = 0;
//	return (EXIT_SUCCESS);
//}
