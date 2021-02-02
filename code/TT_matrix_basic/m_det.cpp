#include "..//TT.h"
#include "math.h"

float m_det(struct matrix *origin) {
	if (origin->row != origin->col) {
		printf("Could not find determinant for\n");
		m_print(origin);
		return(ERROR);
	}
	float det = 1;
	int32_t i = 0;
	if(origin->stat)
	{
		for(i = 0; i < origin->row; i++) {
			det *= origin->e[i * MAX_SIZE + i];
		}
		return det;
	}
	struct matrix *tmp = m_copy(origin);
	int32_t j = 0;
	int32_t k, u, max;
	while(i < tmp->row && j < tmp->col) {
		max = i;
		for(k = i + 1; k < tmp->row; k++)
			if(fabs(tmp->e[k * MAX_SIZE + j]) > fabs(tmp->e[max * MAX_SIZE + j]))
				max = k;
		if(i != max) {
			r_switch(tmp, i, max);
			det = -det;
		}
		if(tmp->e[i * MAX_SIZE + j] < TOLERANCE && tmp->e[i * MAX_SIZE + j] > -TOLERANCE)
		{
			det = 0;
			break;
		}
		det *= tmp->e[i * MAX_SIZE + j];
		r_mul(tmp, i, 1/tmp->e[i * MAX_SIZE + j]);
		for(u = i + 1; u < tmp->row; u++)
			r_add(tmp, u, i, -tmp->e[u * MAX_SIZE + j]);
		i++;
		j++;
	}
	_aligned_free(tmp);
	return det;
}
