#include "..//TT.h"

struct cnum *cm_det(struct cmatrix *origin) {
	if (origin->row != origin->col) {
		printf("Could not find determinant for\n");
		cm_print(origin);
		return NULL;
	}
	struct cmatrix *tmp = cm_copy(origin);
	cnum *det = init_cnum(1, 0);
	int32_t i = 0;
	int32_t j = 0;
	int32_t k, u, max;
	while(i < tmp->row && j < tmp->col) {
		max = i;
		for(k = i + 1; k < tmp->row; k++)
			if(c_abs2_s(tmp->re[k * MAX_SIZE + j], tmp->im[k * MAX_SIZE + j]) > c_abs2_s(tmp->re[max * MAX_SIZE + j], tmp->im[max * MAX_SIZE + j]))
				max = k;
		if(i != max) {
			cr_switch(tmp, i, max);
			det->re = -det->re; det->im = -det->im;
		}
		if(tmp->re[i * MAX_SIZE + j] < TOLERANCE && tmp->re[i * MAX_SIZE + j] > -TOLERANCE && tmp->im[i * MAX_SIZE + j] < TOLERANCE && tmp->im[i * MAX_SIZE + j] > -TOLERANCE)
		{
			det->re = 0; det->im = 0;
			break;
		}
		det = c_mul_sf(det, tmp->re[i * MAX_SIZE + j], tmp->im[i * MAX_SIZE + j]);
		cr_mul_cf(tmp, i, c_div1_s(tmp->re[i * MAX_SIZE + j], tmp->im[i * MAX_SIZE + j]));
		for(u = i + 1; u < tmp->row; u++)
			cr_add_cs(tmp, u, i, -tmp->re[u * MAX_SIZE + j], -tmp->im[u * MAX_SIZE + j]);
		i++;
		j++;
	}
	_aligned_free(tmp);
	return det;
}
