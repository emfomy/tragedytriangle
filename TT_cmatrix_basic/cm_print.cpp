#include "..//TT.h"

int32_t cm_print(struct cmatrix *origin) {
	int32_t i, j;
	if (origin->row == 1) {
		printf("[");
		for (j = 0; j < origin->col; j++) {
			printf(" ");
			c_print_s(origin->re[j], origin->im[j]);
			printf(" ");
		}
		printf("]\n");
		return (EXIT_SUCCESS);
	}
	for (i = 0; i < origin->row; i++) {
		if (i == 0) {
			printf("/");
			for (j = 0; j < origin->col; j++) {
				printf(" ");
				c_print_s(origin->re[i * MAX_SIZE + j], origin->im[i * MAX_SIZE + j]);
				printf(" ");
			}
			printf("\\\n");
		} else if (i == origin->row - 1) {
			printf("\\");
			for (j = 0; j < origin->col; j++) {
				printf(" ");
				c_print_s(origin->re[i * MAX_SIZE + j], origin->im[i * MAX_SIZE + j]);
				printf(" ");
			}
			printf("/\n");
		} else {
			printf("|");
			for (j = 0; j < origin->col; j++) {
				printf(" ");
				c_print_s(origin->re[i * MAX_SIZE + j], origin->im[i * MAX_SIZE + j]);
				printf(" ");
			}
			printf("|\n");
		}
	}
	return (EXIT_SUCCESS);
}
