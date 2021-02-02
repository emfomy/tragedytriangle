#include "..//TT.h"

//ASM

int32_t r_switch(struct matrix *origin, int32_t i, int32_t j) {
	__m128 *a = (__m128*) origin->e;
	__asm
	{
		mov eax, i;
		mov ebx, j;
		shl eax, M_WIDTH_LOG;
		shl ebx, M_WIDTH_LOG;
		add eax, a;
		add ebx, a;
		mov esi, 0;
		mov ecx, MAX_SIZE_B;
L1:
		movaps xmm0, [eax + esi];
		movaps xmm1, [ebx + esi];
		movaps [ebx + esi], xmm0;
		movaps [eax + esi], xmm1;
		add esi, B_WIDTH;
		loop L1;
		emms;
	}
	return (EXIT_SUCCESS);
}

//CPP
//
//int32_t r_switch(struct matrix *origin, int32_t i, int32_t j) {
//	float tmp;
//	int32_t k;
//	for (k = 0; k < MAX_SIZE; k++) {
//		tmp = origin->e[i * MAX_SIZE + k];
//		origin->e[i * MAX_SIZE + k] = origin->e[j * MAX_SIZE + k];
//		origin->e[j * MAX_SIZE + k] = tmp;
//	}
//	return (EXIT_SUCCESS);
//}
