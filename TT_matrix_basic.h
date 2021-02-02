struct matrix {
	int32_t row;
	int32_t col;
	int32_t stat;
	float *e;
};

struct matrix *init_matrix(int32_t row , int32_t col);
struct matrix *m_stdin();
struct matrix *m_rand( int32_t row , int32_t col );
struct matrix *m_copy(struct matrix *origin);
int32_t m_zero(struct matrix *origin);
int32_t m_print(struct matrix *origin);
struct matrix *m_add(struct matrix *matrixA, struct matrix *matrixB);
struct matrix *m_sub(struct matrix *matrixA, struct matrix *matrixB);
struct matrix *m_scalar(struct matrix *origin, float x);
struct matrix *m_mul(struct matrix *matrixA, struct matrix *matrixB);
struct matrix *m_trans(struct matrix *origin);
float m_det(struct matrix *origin);
struct matrix *m_inverse(struct matrix *origin);