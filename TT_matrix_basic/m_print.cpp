#include "..//TT.h"

int32_t m_print(struct matrix *origin) {
	int32_t i, j;
	if (origin->row == 1) {
		printf("[");
		for (j = 0; j < origin->col; j++)
			printf(" %+8.3f  ", origin->e[j] + TOLERANCE);
		printf("]\n");
		return (EXIT_SUCCESS);
	}
	for (i = 0; i < origin->row; i++) {
		if (i == 0) {
			printf("/");
			for (j = 0; j < origin->col; j++)
				printf(" %+8.3f  ", origin->e[i * MAX_SIZE + j] + TOLERANCE);
			printf("\\\n");
		} else if (i == origin->row - 1) {
			printf("\\");
			for (j = 0; j < origin->col; j++)
				printf(" %+8.3f  ", origin->e[i * MAX_SIZE + j] + TOLERANCE);
			printf("/\n");
		} else {
			printf("|");
			for (j = 0; j < origin->col; j++)
				printf(" %+8.3f  ", origin->e[i * MAX_SIZE + j] + TOLERANCE);
			printf("|\n");
		}
	}
	return (EXIT_SUCCESS);
}
