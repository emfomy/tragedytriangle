#include "TT.h"

int32_t main(int32_t argc, int32_t** argv) {
	srand(1);
	char cmd[64];
	char c , d , e;
	int i , j;
	float f , g;
	struct matrix *mtmp;
	struct cmatrix *cmtmp;
	struct cnum *ctmp;
	struct matrix_list user[26];
	for(i=0;i<26;i++){
		user[i].m = NULL;
		user[i].cm = NULL;
		user[i].FLAG_C = -1;
	}
	puts("enter help to get information");
	while( scanf( "%s" , cmd ) != EOF ){
		if( !strcmp( cmd , "create") ){
			scanf( "%s" , cmd );
			c = cmd[0];
			if( c - 'A' < 0 || c - 'A' > 25 ){
				printf("illegal matrix name :%c\n" , c);
				continue ;
			}
			mtmp = user[c-'A'].m;
			if( ( user[c-'A'].m = m_stdin() ) == NULL ){
				user[c-'A'].m = mtmp;
				continue ;
			}
			_aligned_free( mtmp );
			_aligned_free( user[c-'A'].cm );
			user[c-'A'].FLAG_C = 0;
		}
		else if( !strcmp( cmd , "print") ){
			scanf( "%s" , cmd );
			c = cmd[0];
			if( c - 'A' < 0 || c - 'A' > 25 ){
				printf("illegal matrix name :%c\n" , c);
				continue ;
			}
			if( user[c-'A'].FLAG_C == -1 ){
				printf("matrix %c doesn't exist\n" , c);
				continue ;
			}
			if( user[c-'A'].FLAG_C == 1 )cm_print( user[c-'A'].cm );
			else m_print( user[c-'A'].m );
		}
		else if( !strcmp( cmd , "ccreate") ){
			scanf( "%s" , cmd );
			c = cmd[0];
			if( c - 'A' < 0 || c - 'A' > 25 ){
				printf("illegal matrix name :%c\n" , c);
				continue ;
			}
			cmtmp = user[c-'A'].cm;
			if( ( user[c-'A'].cm = cm_stdin() ) == NULL ){
				user[c-'A'].cm = cmtmp;
				continue ;
			}
			_aligned_free( cmtmp );
			_aligned_free( user[c-'A'].m );
			user[c-'A'].FLAG_C = 1;
		}
		else if( !strcmp( cmd , "seed") ){
			scanf( "%s" , cmd );
			i = atoi( cmd );
			if( i<0 )i=i*-1;
			if( i==0 ){
				srand( (unsigned int)time(NULL) );
				continue ;
				}
			srand( i );
			continue ;
		}
		else if( !strcmp( cmd , "rand") ){
			scanf( "%s" , cmd );
			c = cmd[0];
			scanf( "%s" , cmd );
			i = atoi( cmd );
			scanf( "%s" , cmd );
			j = atoi( cmd );
			if( c - 'A' < 0 || c - 'A' > 25 ){
				printf("illegal matrix name :%c\n" , c);
				continue ;
			}
			mtmp = user[c-'A'].m;
			if( ( user[c-'A'].m = m_rand( i , j ) ) == NULL ){
				user[c-'A'].m = mtmp;
				continue ;
			}
			_aligned_free( mtmp );
			_aligned_free( user[c-'A'].cm );
			user[c-'A'].FLAG_C = 0;
		}
		else if( !strcmp( cmd , "crand") ){
			scanf( "%s" , cmd );
			c = cmd[0];
			scanf( "%s" , cmd );
			i = atoi( cmd );
			scanf( "%s" , cmd );
			j = atoi( cmd );
			if( c - 'A' < 0 || c - 'A' > 25 ){
				printf("illegal matrix name :%c\n" , c);
				continue ;
			}
			cmtmp = user[c-'A'].cm;
			if( ( user[c-'A'].cm = cm_rand( i , j ) ) == NULL ){
				user[c-'A'].cm = cmtmp;
				continue ;
			}
			_aligned_free( cmtmp );
			_aligned_free( user[c-'A'].m );
			user[c-'A'].FLAG_C = 1;
		}
		else if( !strcmp( cmd , "copy") ){
			scanf( "%s" , cmd );
			c = cmd[0];
			scanf( "%s" , cmd );
			d = cmd[0];
			if( c - 'A' < 0 || c - 'A' > 25 ){
				printf("illegal matrix name :%c\n" , c);
				continue ;
			}
			if( d - 'A' < 0 || d - 'A' > 25 ){
				printf("illegal matrix name :%c\n" , d);
				continue ;
			}
			if( user[d-'A'].FLAG_C == -1 ){
				printf("matrix %c doesn't exist\n" , d);
				continue ;
			}
			if( user[d-'A'].FLAG_C == 0 ){
				mtmp = user[c-'A'].m;
				if( ( user[c-'A'].m = m_copy( user[d-'A'].m ) ) == NULL ){
					user[c -'A'].m = mtmp;
					continue ;
				}
				_aligned_free( mtmp );
				_aligned_free( user[c-'A'].cm );
				user[c-'A'].FLAG_C = 0;
			}
			if( user[d-'A'].FLAG_C == 1 ){
				cmtmp = user[c-'A'].cm;
				if( ( user[c-'A'].cm = cm_copy( user[d-'A'].cm ) ) == NULL ){
					user[c -'A'].cm = cmtmp;
					continue ;
				}
				_aligned_free( cmtmp );
				_aligned_free( user[c -'A'].m );
				user[c-'A'].FLAG_C = 1;
			}
		}
		else if( !strcmp( cmd , "add") ){
			scanf( "%s" , cmd );
			c = cmd[0];
			scanf( "%s" , cmd );
			d = cmd[0];
			scanf( "%s" , cmd );
			e = cmd[0];
			if( c - 'A' < 0 || c - 'A' > 25 ){
				printf("illegal matrix name :%c\n" , c);
				continue ;
			}
			if( d - 'A' < 0 || d - 'A' > 25 ){
				printf("illegal matrix name :%c\n" , d);
				continue ;
			}
			if( user[d-'A'].FLAG_C == -1 ){
				printf("matrix %c doesn't exist\n" , d);
				continue ;
			}
			if( e - 'A' < 0 || e - 'A' > 25 ){
				printf("illegal matrix name :%c\n" , e);
				continue ;
			}
			if( user[e-'A'].FLAG_C == -1 ){
				printf("matrix %c doesn't exist\n" , e);
				continue ;
			}
			if( user[d-'A'].FLAG_C == 1 || user[e-'A'].FLAG_C == 1 ){
				if( user[d-'A'].FLAG_C != 1 ){
					cmtmp = user[d-'A'].cm;
					if( ( user[d-'A'].cm = m_to_cm( user[d-'A'].m ) ) == NULL ){
					user[d-'A'].cm = cmtmp;
					continue ;
					}
					_aligned_free( cmtmp );
					_aligned_free( user[d -'A'].m );
					user[d-'A'].FLAG_C = 1;
				}
				if( user[e-'A'].FLAG_C != 1 ){
					cmtmp = user[e-'A'].cm;
					if( ( user[e-'A'].cm = m_to_cm( user[e-'A'].m ) ) == NULL ){
					user[e-'A'].cm = cmtmp;
					continue ;
					}
					_aligned_free( cmtmp );
					_aligned_free( user[e -'A'].m );
					user[e-'A'].FLAG_C = 1;
				}
				cmtmp = user[c-'A'].cm;
				if( ( user[c-'A'].cm = cm_add( user[d-'A'].cm , user[e-'A'].cm ) ) == NULL ){
					user[c-'A'].cm = cmtmp;
					continue ;
				}
				_aligned_free( cmtmp );
				_aligned_free( user[c-'A'].m );
				user[c-'A'].FLAG_C = 1;
			}
			else {
				mtmp = user[c-'A'].m;
				if( ( user[c-'A'].m = m_add( user[d-'A'].m , user[e-'A'].m ) ) == NULL ){
					user[c-'A'].m = mtmp;
					continue ;
				}
				_aligned_free( mtmp );
				_aligned_free( user[c-'A'].cm );
				user[c-'A'].FLAG_C = 0;
			}
		}
		else if( !strcmp( cmd , "sub") ){
			scanf( "%s" , cmd );
			c = cmd[0];
			scanf( "%s" , cmd );
			d = cmd[0];
			scanf( "%s" , cmd );
			e = cmd[0];
			if( c - 'A' < 0 || c - 'A' > 25 ){
				printf("illegal matrix name :%c\n" , c);
				continue ;
			}
			if( d - 'A' < 0 || d - 'A' > 25 ){
				printf("illegal matrix name :%c\n" , d);
				continue ;
			}
			if( user[d-'A'].FLAG_C == -1 ){
				printf("matrix %c doesn't exist\n" , d);
				continue ;
			}
			if( e - 'A' < 0 || e - 'A' > 25 ){
				printf("illegal matrix name :%c\n" , e);
				continue ;
			}
			if( user[e-'A'].FLAG_C == -1 ){
				printf("matrix %c doesn't exist\n" , e);
				continue ;
			}
			if( user[d-'A'].FLAG_C == 1 || user[e-'A'].FLAG_C == 1 ){
				if( user[d-'A'].FLAG_C != 1 ){
					cmtmp = user[d-'A'].cm;
					if( ( user[d-'A'].cm = m_to_cm( user[d-'A'].m ) ) == NULL ){
					user[d-'A'].cm = cmtmp;
					continue ;
					}
					_aligned_free( cmtmp );
					_aligned_free( user[d -'A'].m );
					user[d-'A'].FLAG_C = 1;
				}
				if( user[e-'A'].FLAG_C != 1 ){
					cmtmp = user[e-'A'].cm;
					if( ( user[e-'A'].cm = m_to_cm( user[e-'A'].m ) ) == NULL ){
					user[e-'A'].cm = cmtmp;
					continue ;
					}
					_aligned_free( cmtmp );
					_aligned_free( user[e -'A'].m );
					user[e-'A'].FLAG_C = 1;
				}
				cmtmp = user[c-'A'].cm;
				if( ( user[c-'A'].cm = cm_sub( user[d-'A'].cm , user[e-'A'].cm ) ) == NULL ){
					user[c-'A'].cm = cmtmp;
					continue ;
				}
				_aligned_free( cmtmp );
				_aligned_free( user[c-'A'].m );
				user[c-'A'].FLAG_C = 1;
			}
			else {
				mtmp = user[c-'A'].m;
				if( ( user[c-'A'].m = m_sub( user[d-'A'].m , user[e-'A'].m ) ) == NULL ){
					user[c-'A'].m = mtmp;
					continue ;
				}
				_aligned_free( mtmp );
				_aligned_free( user[c-'A'].cm );
				user[c-'A'].FLAG_C = 0;
			}
		}
		else if( !strcmp( cmd , "mul") ){
			scanf( "%s" , cmd );
			c = cmd[0];
			scanf( "%s" , cmd );
			d = cmd[0];
			scanf( "%s" , cmd );
			e = cmd[0];
			if( c - 'A' < 0 || c - 'A' > 25 ){
				printf("illegal matrix name :%c\n" , c);
				continue ;
			}
			if( d - 'A' < 0 || d - 'A' > 25 ){
				printf("illegal matrix name :%c\n" , d);
				continue ;
			}
			if( user[d-'A'].FLAG_C == -1 ){
				printf("matrix %c doesn't exist\n" , d);
				continue ;
			}
			if( e - 'A' < 0 || e - 'A' > 25 ){
				printf("illegal matrix name :%c\n" , e);
				continue ;
			}
			if( user[e-'A'].FLAG_C == -1 ){
				printf("matrix %c doesn't exist\n" , e);
				continue ;
			}
			if( user[d-'A'].FLAG_C == 1 || user[e-'A'].FLAG_C == 1 ){
				if( user[d-'A'].FLAG_C != 1 ){
					cmtmp = user[d-'A'].cm;
					if( ( user[d-'A'].cm = m_to_cm( user[d-'A'].m ) ) == NULL ){
					user[d-'A'].cm = cmtmp;
					continue ;
					}
					_aligned_free( cmtmp );
					_aligned_free( user[d -'A'].m );
					user[d-'A'].FLAG_C = 1;
				}
				if( user[e-'A'].FLAG_C != 1 ){
					cmtmp = user[e-'A'].cm;
					if( ( user[e-'A'].cm = m_to_cm( user[e-'A'].m ) ) == NULL ){
					user[e-'A'].cm = cmtmp;
					continue ;
					}
					_aligned_free( cmtmp );
					_aligned_free( user[e -'A'].m );
					user[e-'A'].FLAG_C = 1;
				}
				cmtmp = user[c-'A'].cm;
				if( ( user[c-'A'].cm = cm_mul( user[d-'A'].cm , user[e-'A'].cm ) ) == NULL ){
					user[c-'A'].cm = cmtmp;
					continue ;
				}
				_aligned_free( cmtmp );
				_aligned_free( user[c-'A'].m );
				user[c-'A'].FLAG_C = 1;
			}
			else {
				mtmp = user[c-'A'].m;
				if( ( user[c-'A'].m = m_mul( user[d-'A'].m , user[e-'A'].m ) ) == NULL ){
					user[c-'A'].m = mtmp;
					continue ;
				}
				_aligned_free( mtmp );
				_aligned_free( user[c-'A'].cm );
				user[c-'A'].FLAG_C = 0;
			}
		}
		else if( !strcmp( cmd , "scalar") ){
			scanf( "%s" , cmd );
			c = cmd[0];
			scanf( "%s" , cmd );
			d = cmd[0];
			scanf( "%s" , cmd );
			f = (float)atof( cmd );
			if( c - 'A' < 0 || c - 'A' > 25 ){
				printf("illegal matrix name :%c\n" , c);
				continue ;
			}
			if( d - 'A' < 0 || d - 'A' > 25 ){
				printf("illegal matrix name :%c\n" , d);
				continue ;
			}
			if( user[d-'A'].FLAG_C == -1 ){
				printf("matrix %c doesn't exist\n" , d);
				continue ;
			}
			if( user[d-'A'].FLAG_C == 1 ){
				scanf( "%s" , cmd );
				g = (float)atof( cmd );
				if( g == 0 ){
					cmtmp = user[c-'A'].cm;
					if( ( user[c-'A'].cm = cm_scalar( user[d-'A'].cm , f ) ) == NULL ){
					user[c-'A'].m = mtmp;
					continue ;
					}
					_aligned_free( cmtmp );
					_aligned_free( user[c-'A'].m );
					user[c-'A'].FLAG_C = 1;
				}
				else{
					cmtmp = user[c-'A'].cm;
					if( ( user[c-'A'].cm = cm_scalar_c( user[d-'A'].cm , init_cnum(f , g ) ) ) == NULL ){
					user[c-'A'].m = mtmp;
					continue ;
					}
					_aligned_free( cmtmp );
					_aligned_free( user[c-'A'].m );
					user[c-'A'].FLAG_C = 1;
				}
			}
			else{
				mtmp = user[c-'A'].m;
				if( ( user[c-'A'].m = m_scalar( user[d-'A'].m , f ) ) == NULL ){
					user[c-'A'].m = mtmp;
					continue ;
				}
				_aligned_free( mtmp );
				_aligned_free( user[c-'A'].cm );
				user[c-'A'].FLAG_C = 0;
			}
		}
		else if( !strcmp( cmd , "trans") ){
			scanf( "%s" , cmd );
			c = cmd[0];
			scanf( "%s" , cmd );
			d = cmd[0];
			if( c - 'A' < 0 || c - 'A' > 25 ){
				printf("illegal matrix name :%c\n" , c);
				continue ;
			}
			if( d - 'A' < 0 || d - 'A' > 25 ){
				printf("illegal matrix name :%c\n" , d);
				continue ;
			}
			if( user[d-'A'].FLAG_C == -1 ){
				printf("matrix %c doesn't exist\n" , d);
				continue ;
			}
			if( user[d-'A'].FLAG_C == 0 ){
				mtmp = user[c-'A'].m;
				if( ( user[c-'A'].m = m_trans( user[d-'A'].m ) ) == NULL ){
					user[c-'A'].m = mtmp;
					continue ;
				}
				_aligned_free( mtmp );
				_aligned_free( user[c-'A'].cm );
				user[c-'A'].FLAG_C = 0;
			}
			if( user[d-'A'].FLAG_C == 1 ){
				cmtmp = user[c-'A'].cm;
				if( ( user[c-'A'].cm = cm_trans( user[d-'A'].cm ) ) == NULL ){
					user[c-'A'].cm = cmtmp;
					continue ;
				}
				_aligned_free( cmtmp );
				_aligned_free( user[c-'A'].m );
				user[c-'A'].FLAG_C = 1;
			}
		}
		else if( !strcmp( cmd , "det") ){
			scanf( "%s" , cmd );
			c = cmd[0];
			if( c - 'A' < 0 || c - 'A' > 25 ){
				printf("illegal matrix name :%c\n" , c);
				continue ;
			}
			if( user[c-'A'].FLAG_C == -1 ){
				printf("matrix %c doesn't exist\n" , c);
				continue ;
			}
			if( user[c-'A'].FLAG_C == 1 ){
				if((ctmp = cm_det( user[c-'A'].cm )) != NULL ){
					c_print(ctmp);
					puts("");
				}
			}
			else {
				if( ( f = m_det( user[c-'A'].m ) ) != ERROR ){
					printf("%f\n" , f );
				}
			}
		}
		else if( !strcmp( cmd , "inverse") ){
			scanf( "%s" , cmd );
			c = cmd[0];
			scanf( "%s" , cmd );
			d = cmd[0];
			if( c - 'A' < 0 || c - 'A' > 25 ){
				printf("illegal matrix name :%c\n" , c);
				continue ;
			}
			if( d - 'A' < 0 || d - 'A' > 25 ){
				printf("illegal matrix name :%c\n" , d);
				continue ;
			}
			if( user[d-'A'].FLAG_C == -1 ){
				printf("matrix %c doesn't exist\n" , d);
				continue ;
			}
			if( user[d-'A'].FLAG_C == 0 ){
				mtmp = user[c-'A'].m;
				if( ( user[c-'A'].m = m_inverse( user[d-'A'].m ) ) == NULL ){
					user[c-'A'].m = mtmp;
					continue ;
				}
				_aligned_free( mtmp );
				_aligned_free( user[c-'A'].cm );
				user[c-'A'].FLAG_C = 0;
			}
			if( user[d-'A'].FLAG_C == 1 ){
				cmtmp = user[c-'A'].cm;
				if( ( user[c-'A'].cm = cm_inverse( user[d-'A'].cm ) ) == NULL ){
					user[c-'A'].cm = cmtmp;
					continue ;
				}
				_aligned_free( cmtmp );
				_aligned_free( user[c-'A'].m );
				user[c-'A'].FLAG_C = 1;
			}
		}
		else if( !strcmp( cmd , "lu") ){}
		else if( !strcmp( cmd , "ldu") ){}
		else if( !strcmp( cmd , "cholesky") ){}
		else if( !strcmp( cmd , "qr") ){}
		else if( !strcmp( cmd , "svd") ){}
		else if( !strcmp( cmd , "jordan") ){}
		else if( !strcmp( cmd , "schur") ){}
		else if( !strcmp( cmd , "help") ){
		puts("Here support 26 matrix correspond to A-Z");
		puts("seed [int] : Assign a random seed, if [int] == 0 , time( NULL ) will be set");
		puts("rand  [matrix] [row] [col] : Random create a matrix with [row] and [col] at [matrix] ");
		puts("crand [matrix] [row] [col] : Random create a complex matrix with [row] and [col] at [matrix] ");
		puts("create  [matrix] [row] [col] [e00] [e01] e[02]... : create a new matrix at [matrix]");
		puts("ccreate [matrix] [row] [col] [re00] [im00] [re01] [im01] [re02] [im02]... : create a new complex matrix at [matrix]");
		puts("print [matrix] : Print [matrix]");
		puts("copy [matrixA] [matrixB] : [matrixA] := [matrixB]");
		puts("scalar [matrixA] [number.re] [number.im] : [matrixA] *= [number]");
		puts("add/sub/mul [matrixA] [matrixB] [matrixC] : [matrixA] := [matrixB] (operator) [matrixC]");
		puts("trans/inverse [matrixA] [matrixB] :[matrixA] := (operator)[matrixB]");
		puts("exit : End the process");
		}
		else if( !strcmp( cmd , "exit") )return 0;
		else puts("Command not exist.");
	}
	return (EXIT_SUCCESS);
}
