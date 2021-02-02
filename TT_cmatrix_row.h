int32_t cr_switch(struct cmatrix* origin, int32_t i, int32_t j);
int32_t cr_mul(struct cmatrix *origin, int32_t i, float x);
int32_t cr_mul_c(struct cmatrix *origin, int32_t i, struct cnum *x);
int32_t cr_mul_cf(struct cmatrix *origin, int32_t i, struct cnum *x);
int32_t cr_mul_cs(struct cmatrix *origin, int32_t i, float re, float im);
int32_t cr_add(struct cmatrix* origin, int32_t i, int32_t j, float x);
int32_t cr_add_c(struct cmatrix* origin, int32_t i, int32_t j, struct cnum *x);
int32_t cr_add_cf(struct cmatrix* origin, int32_t i, int32_t j, struct cnum *x);
int32_t cr_add_cs(struct cmatrix* origin, int32_t i, int32_t j, float re, float im);
