struct cmatrix {
	int32_t row;
	int32_t col;
	int32_t stat;
	float *re;
	float *im;
};

struct cmatrix *init_cmatrix(int32_t row , int32_t col);
struct cmatrix *m_to_cm(struct matrix *origin);
struct cmatrix *cm_stdin();
struct cmatrix *cm_rand( int32_t row , int32_t col );
struct cmatrix *cm_copy(struct cmatrix *origin);
int32_t cm_zero(struct cmatrix *origin);
int32_t cm_print(struct cmatrix *origin);
struct cmatrix *cm_add(struct cmatrix *matrixA, struct cmatrix *matrixB);
struct cmatrix *cm_sub(struct cmatrix *matrixA, struct cmatrix *matrixB);
struct cmatrix *cm_scalar(struct cmatrix *origin, float x);
struct cmatrix *cm_scalar_c(struct cmatrix *origin, struct cnum* x);
struct cmatrix *cm_scalar_cf(struct cmatrix *origin, struct cnum* x);
struct cmatrix *cm_mul(struct cmatrix *matrixA, struct cmatrix *matrixB);
struct cmatrix *cm_trans(struct cmatrix *origin);
struct cnum *cm_det(struct cmatrix *origin);
struct cmatrix *cm_inverse(struct cmatrix *origin);
