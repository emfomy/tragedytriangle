#include "..//TT.h"

struct cmatrix *cm_stdin() {
	int32_t row, col;
	scanf_s("%d %d", &row, &col);
	if (row <= 0 || col <= 0 || row > MAX_SIZE || col > MAX_SIZE) {
		printf("Wrong size!\n");
		return NULL;
	}
	struct cmatrix *tmp = init_cmatrix(row, col);
	int32_t i, j;
	float re, im;
	if (row == col) {
		int32_t upp = 1;
		int32_t low = 1;
		for (i = 0; i < MAX_SIZE; i++) {
			for (j = 0; j < MAX_SIZE; j++) {
				if (i < row && j < col) {
					scanf( "%f %f" , &re , &im );
					tmp->re[i * MAX_SIZE + j] = re;
					tmp->im[i * MAX_SIZE + j] = im;
					if (i < j && (tmp->re[i * MAX_SIZE + j] != 0 || tmp->im[i * MAX_SIZE + j] != 0))
						upp = 0;
					if (i > j && (tmp->re[i * MAX_SIZE + j] != 0 || tmp->im[i * MAX_SIZE + j] != 0))
						low = 0;
				} else {
					tmp->re[i * MAX_SIZE + j] = 0;
					tmp->im[i * MAX_SIZE + j] = 0;
				}
			}
		}
		if (upp == 1 && low == 1)
			tmp->stat = DIA;
		if (upp == 1 && low == 0)
			tmp->stat = UPP;
		if (upp == 0 && low == 1)
			tmp->stat = LOW;
	} else {
		for (i = 0; i < MAX_SIZE; i++) {
			for (j = 0; j < MAX_SIZE; j++) {
				if (i < row && j < col) {
					scanf( "%f %f" , &re  , &im );
					tmp->re[i * MAX_SIZE + j] = re;
					tmp->im[i * MAX_SIZE + j] = im;
				} else {
					tmp->re[i * MAX_SIZE + j] = 0;
					tmp->im[i * MAX_SIZE + j] = 0;
				}
			}
		}
	}
	return tmp;
}
