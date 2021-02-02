#include "..//TT.h"

struct cmatrix *cm_rand( const int row , const int col ){
	if(row < 0 || row > MAX_SIZE || col < 0 || col > MAX_SIZE){
		puts("wrong size");
		return NULL;
	}
	struct cmatrix *tmp = init_cmatrix( row , col);
	int32_t i ,j;
	for (i = 0; i < MAX_SIZE; i++) {
		for (j = 0; j < MAX_SIZE; j++) {
			if (i < row && j < col) {
				tmp->re[i * MAX_SIZE + j] = rand()/2048.0-8;
				tmp->im[i * MAX_SIZE + j] = rand()/2048.0-8;
			} else {
				tmp->re[i * MAX_SIZE + j] = 0;
				tmp->im[i * MAX_SIZE + j] = 0;
			}
		}
	}
	return tmp;
}