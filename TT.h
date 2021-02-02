#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <emmintrin.h>
#include <time.h>
#include <string.h>
#include "TT_matrix_basic.h"
#include "TT_matrix_row.h"
#include "TT_matrix_decomposition.h"
#include "TT_cnum.h"
#include "TT_cmatrix_basic.h"
#include "TT_cmatrix_row.h"

struct matrix_list{
	struct matrix *m;
	struct cmatrix *cm;
	int FLAG_C;
};

#define MAX_SIZE 16		//
#define MAX_NUMBER 256	// = MAX * MAX
#define MAX_NUMBER2 512
#define MAX_SIZE_B 4	// = MAX / 4
#define ALL_TIMES 64	// = MAX * MAX / 4
#define ALL_TIMES2 128	// = MAX * MAX / 4
#define B_WIDTH 16		//
#define B_HEIGHT 256	// = B_W * MAX * 4
#define M_WIDTH 64		// = B_W * MAX / 4
#define M_WIDTH2 128
#define M_WIDTH3 192
#define M_WIDTH_LOG 6	// = LOD(M_W)
#define M_HEIGHT 1024	// = B_W * MAX * MAX / 4

#define EQ 1
#define NEQ 0

#define DEFAULT 0
#define UPP 1
#define LOW 2
#define DIA 3

#define TOLERANCE 0.0000152587890625 // 2^(-16)
#define ERROR 0xFFFF