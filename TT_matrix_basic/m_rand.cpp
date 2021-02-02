#include "..//TT.h"

struct matrix *m_rand( const int row , const int col ){
	if(row < 0 || row > MAX_SIZE || col < 0 || col > MAX_SIZE){
		puts("wrong size");
		return NULL;
	}
	struct matrix *tmp = init_matrix( row, col);
	int32_t i ,j;
	for (i = 0; i < MAX_SIZE; i++) {
		for (j = 0; j < MAX_SIZE; j++) {
			if (i < row && j < col) {
				tmp->e[i * MAX_SIZE + j] = rand()/2048.0-8;
			} else {
				tmp->e[i * MAX_SIZE + j] = 0;
			}
		}
	}
	return tmp;
}