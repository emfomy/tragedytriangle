#include "..//TT.h"

//ASM

struct cmatrix *cm_mul(struct cmatrix *matrixA, struct cmatrix *matrixB) {
	if (matrixA->col != matrixB->row) {
		printf("Could not multiply\n");
		cm_print(matrixA);
		printf("by\n");
		cm_print(matrixB);
		return NULL;
	}
	struct cmatrix *tmp = init_cmatrix(matrixA->row, matrixB->col);
	tmp->stat = matrixA->stat & matrixB->stat;
	struct cmatrix *matrixBT = cm_trans(matrixB);
	__m128 *a = (__m128*) matrixA->re;
	__m128 *b = (__m128*) matrixBT->re;
	__m128 *d = (__m128*) tmp->re;
	__m128 *aa = (__m128*) matrixA->im;
	__m128 *bb = (__m128*) matrixBT->im;
	__m128 *dd = (__m128*) tmp->im;
	__asm
	{
		andnps xmm7, xmm7;

		mov eax, aa;
		mov edx, d;
		mov ecx, MAX_SIZE;
La1:
		push ecx;
		mov ebx, bb;

		mov ecx, MAX_SIZE_B;
La2:
		push ecx;

		movaps xmm0, xmm7;
		mov esi, 0;
		mov ecx, MAX_SIZE_B;
La3a:
		movaps xmm4, [eax + esi];
		mulps xmm4, [ebx + esi];
		addps xmm0, xmm4;
		add esi, B_WIDTH;
		loop La3a;

		add ebx, M_WIDTH;
		movaps xmm1, xmm7;
		mov esi, 0;
		mov ecx, MAX_SIZE_B;
La3b:
		movaps xmm4, [eax + esi];
		mulps xmm4, [ebx + esi];
		addps xmm1, xmm4;
		add esi, B_WIDTH;
		loop La3b;

		add ebx, M_WIDTH;
		movaps xmm2, xmm7;
		mov esi, 0;
		mov ecx, MAX_SIZE_B;
La3c:
		movaps xmm4, [eax + esi];
		mulps xmm4, [ebx + esi];
		addps xmm2, xmm4;
		add esi, B_WIDTH;
		loop La3c;

		add ebx, M_WIDTH;
		movaps xmm3, xmm7;
		mov esi, 0;
		mov ecx, MAX_SIZE_B;
La3d:
		movaps xmm4, [eax + esi];
		mulps xmm4, [ebx + esi];
		addps xmm3, xmm4;
		add esi, B_WIDTH;
		loop La3d;

		haddps xmm0, xmm1;
		haddps xmm2, xmm3;
		haddps xmm0, xmm2;
		movaps [edx], xmm0;

		add ebx, M_WIDTH;
		add edx, B_WIDTH;
		pop ecx;
		dec ecx;
		jnz La2;

		add eax, M_WIDTH;
		pop ecx;
		dec ecx;
		jnz La1;


		mov eax, a;
		mov edx, d;
		mov ecx, MAX_SIZE;
Lb1:
		push ecx;
		mov ebx, b;

		mov ecx, MAX_SIZE_B;
Lb2:
		push ecx;

		movaps xmm0, xmm7;
		mov esi, 0;
		mov ecx, MAX_SIZE_B;
Lb3a:
		movaps xmm4, [eax + esi];
		mulps xmm4, [ebx + esi];
		addps xmm0, xmm4;
		add esi, B_WIDTH;
		loop Lb3a;

		add ebx, M_WIDTH;
		movaps xmm1, xmm7;
		mov esi, 0;
		mov ecx, MAX_SIZE_B;
Lb3b:
		movaps xmm4, [eax + esi];
		mulps xmm4, [ebx + esi];
		addps xmm1, xmm4;
		add esi, B_WIDTH;
		loop Lb3b;

		add ebx, M_WIDTH;
		movaps xmm2, xmm7;
		mov esi, 0;
		mov ecx, MAX_SIZE_B;
Lb3c:
		movaps xmm4, [eax + esi];
		mulps xmm4, [ebx + esi];
		addps xmm2, xmm4;
		add esi, B_WIDTH;
		loop Lb3c;

		add ebx, M_WIDTH;
		movaps xmm3, xmm7;
		mov esi, 0;
		mov ecx, MAX_SIZE_B;
Lb3d:
		movaps xmm4, [eax + esi];
		mulps xmm4, [ebx + esi];
		addps xmm3, xmm4;
		add esi, B_WIDTH;
		loop Lb3d;

		haddps xmm0, xmm1;
		haddps xmm2, xmm3;
		haddps xmm0, xmm2;
		subps xmm0, [edx];
		movaps [edx], xmm0;

		add ebx, M_WIDTH;
		add edx, B_WIDTH;
		pop ecx;
		dec ecx;
		jnz Lb2;

		add eax, M_WIDTH;
		pop ecx;
		dec ecx;
		jnz Lb1;


		mov eax, a;
		mov edx, dd;
		mov ecx, MAX_SIZE;
Lc1:
		push ecx;
		mov ebx, bb;

		mov ecx, MAX_SIZE_B;
Lc2:
		push ecx;

		movaps xmm0, xmm7;
		mov esi, 0;
		mov ecx, MAX_SIZE_B;
Lc3a:
		movaps xmm4, [eax + esi];
		mulps xmm4, [ebx + esi];
		addps xmm0, xmm4;
		add esi, B_WIDTH;
		loop Lc3a;

		add ebx, M_WIDTH;
		movaps xmm1, xmm7;
		mov esi, 0;
		mov ecx, MAX_SIZE_B;
Lc3b:
		movaps xmm4, [eax + esi];
		mulps xmm4, [ebx + esi];
		addps xmm1, xmm4;
		add esi, B_WIDTH;
		loop Lc3b;

		add ebx, M_WIDTH;
		movaps xmm2, xmm7;
		mov esi, 0;
		mov ecx, MAX_SIZE_B;
Lc3c:
		movaps xmm4, [eax + esi];
		mulps xmm4, [ebx + esi];
		addps xmm2, xmm4;
		add esi, B_WIDTH;
		loop Lc3c;

		add ebx, M_WIDTH;
		movaps xmm3, xmm7;
		mov esi, 0;
		mov ecx, MAX_SIZE_B;
Lc3d:
		movaps xmm4, [eax + esi];
		mulps xmm4, [ebx + esi];
		addps xmm3, xmm4;
		add esi, B_WIDTH;
		loop Lc3d;

		haddps xmm0, xmm1;
		haddps xmm2, xmm3;
		haddps xmm0, xmm2;
		movaps [edx], xmm0;

		add ebx, M_WIDTH;
		add edx, B_WIDTH;
		pop ecx;
		dec ecx;
		jnz Lc2;

		add eax, M_WIDTH;
		pop ecx;
		dec ecx;
		jnz Lc1;


		mov eax, aa;
		mov edx, dd;
		mov ecx, MAX_SIZE;
Ld1:
		push ecx;
		mov ebx, b;

		mov ecx, MAX_SIZE_B;
Ld2:
		push ecx;

		movaps xmm0, xmm7;
		mov esi, 0;
		mov ecx, MAX_SIZE_B;
Ld3a:
		movaps xmm4, [eax + esi];
		mulps xmm4, [ebx + esi];
		addps xmm0, xmm4;
		add esi, B_WIDTH;
		loop Ld3a;

		add ebx, M_WIDTH;
		movaps xmm1, xmm7;
		mov esi, 0;
		mov ecx, MAX_SIZE_B;
Ld3b:
		movaps xmm4, [eax + esi];
		mulps xmm4, [ebx + esi];
		addps xmm1, xmm4;
		add esi, B_WIDTH;
		loop Ld3b;

		add ebx, M_WIDTH;
		movaps xmm2, xmm7;
		mov esi, 0;
		mov ecx, MAX_SIZE_B;
Ld3c:
		movaps xmm4, [eax + esi];
		mulps xmm4, [ebx + esi];
		addps xmm2, xmm4;
		add esi, B_WIDTH;
		loop Ld3c;

		add ebx, M_WIDTH;
		movaps xmm3, xmm7;
		mov esi, 0;
		mov ecx, MAX_SIZE_B;
Ld3d:
		movaps xmm4, [eax + esi];
		mulps xmm4, [ebx + esi];
		addps xmm3, xmm4;
		add esi, B_WIDTH;
		loop Ld3d;

		haddps xmm0, xmm1;
		haddps xmm2, xmm3;
		haddps xmm0, xmm2;
		addps xmm0, [edx];
		movaps [edx], xmm0;

		add ebx, M_WIDTH;
		add edx, B_WIDTH;
		pop ecx;
		dec ecx;
		jnz Ld2;

		add eax, M_WIDTH;
		pop ecx;
		dec ecx;
		jnz Ld1;


		emms;
	}
	_aligned_free(matrixBT->re);
	_aligned_free(matrixBT);
	return tmp;
}

//CPP
//
//struct cmatrix *cm_mul(struct cmatrix *matrixA, struct cmatrix *matrixB) {
//	if (matrixA->col != matrixB->row) {
//		printf("Could not multiply\n");
//		cm_print(matrixA);
//		printf("by\n");
//		cm_print(matrixB);
//		return NULL;
//	}
//	struct cmatrix *tmp = init_cmatrix(matrixA->row, matrixB->col);
//	tmp->stat = matrixA->stat & matrixB->stat;
//	int32_t i, j, k;
//	for (i = 0; i < MAX_SIZE; i++) {
//		for (j = 0; j < MAX_SIZE; j++) {
//			tmp->re[i * MAX_SIZE + j] = 0;
//			tmp->im[i * MAX_SIZE + j] = 0;
//			for (k = 0; k < MAX_SIZE; k++) {
//				tmp->re[i * MAX_SIZE + j] += matrixA->re[i * MAX_SIZE + k] * matrixB->re[k * MAX_SIZE + j] - matrixA->im[i * MAX_SIZE + k] * matrixB->im[k * MAX_SIZE + j];
//				tmp->im[i * MAX_SIZE + j] += matrixA->re[i * MAX_SIZE + k] * matrixB->im[k * MAX_SIZE + j] + matrixA->im[i * MAX_SIZE + k] * matrixB->re[k * MAX_SIZE + j];
//			}
//		}
//	}
//	return tmp;
//}
