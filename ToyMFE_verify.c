// This file is generated from test alphabets program by code generator in alphaz
// To compile this code, use -lm option for math library.

// Includes
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <limits.h>
#include <float.h>


// Common Macros
#define max(x, y)   ((x)>(y) ? (x) : (y))
#define MAX(x, y)	((x)>(y) ? (x) : (y))
#define min(x, y)   ((x)>(y) ? (y) : (x))
#define MIN(x, y)	((x)>(y) ? (y) : (x))
#define CEILD(n,d)  (int)ceil(((double)(n))/((double)(d)))
#define ceild(n,d)  (int)ceil(((double)(n))/((double)(d)))
#define FLOORD(n,d) (int)floor(((double)(n))/((double)(d)))
#define floord(n,d) (int)floor(((double)(n))/((double)(d)))
#define CDIV(x,y)    CEILD((x),(y))
#define div(x,y)    CDIV((x),(y))
#define FDIV(x,y)    FLOORD((x),(y))
#define LB_SHIFT(b,s)  ((int)ceild(b,s) * s)
#define MOD(i,j)   ((i)%(j))
#define mallocCheck(v,s,d) if ((v) == NULL) { printf("Failed to allocate memory for %s : size=%lu\n", "sizeof(d)*(s)", sizeof(d)*(s)); exit(-1); }

// Common functions for min and max
//functions for integer max
inline int __max_int(int x, int y){
	return ((x)>(y) ? (x) : (y));
}

inline short __max_short(short x, short y){
	return ((x)>(y) ? (x) : (y));
}

inline long __max_long(long x, long y){
	return ((x)>(y) ? (x) : (y));
}

inline unsigned int __max_unsigned_int(unsigned int x, unsigned int y){
	return ((x)>(y) ? (x) : (y));
}

inline unsigned short __max_unsigned_short(unsigned short x, unsigned short y){
	return ((x)>(y) ? (x) : (y));
}

//function for float max
inline float __max_float(float x, float y){
	return ((x)>(y) ? (x) : (y));
}

//function for double max
inline double __max_double(double x, double y){
	return ((x)>(y) ? (x) : (y));
}

//function for integer min
inline int __min_int(int x, int y){
	return ((x)>(y) ? (y) : (x));
}

inline short __min_short(short x, short y){
	return ((x)>(y) ? (y) : (x));
}

inline long __min_long(long x, long y){
	return ((x)>(y) ? (y) : (x));
}

inline unsigned int __min_unsigned_int(unsigned int x, unsigned int y){
	return ((x)>(y) ? (y) : (x));
}

inline unsigned short __min_unsigned_short(unsigned short x, unsigned short y){
	return ((x)>(y) ? (y) : (x));
}

inline unsigned long __min_unsigned_long(unsigned long x, unsigned long y){
	return ((x)>(y) ? (y) : (x));
}

inline float __min_float(float x, float y){
	return ((x)>(y) ? (y) : (x));
}

inline double __min_double(double x, double y){
	return ((x)>(y) ? (y) : (x));
}



///Global Variables
static long* A;
static long* B;
static long** T;
static long last;
static char _flag_last;
static char** _flag_T;


//Local Function Declarations
long eval_T(long, long, long);
long eval_last(long);

//Memory Macros
#define A(i) A[i]
#define B(i) B[i]
#define T(i,j) T[i][j]
#define _flag_T(i,j) _flag_T[i][j]

void ToyMFE_verify(long N, long* _local_A, long* _local_B, long* _local_last){
	///Parameter checking
	if (!((N >= 1))) {
		printf("The value of parameters are not valid.\n");
		exit(-1);
	}
	//Copy to global
	A = _local_A;
	B = _local_B;
	
	
	//Memory Allocation
	long mz1, mz2;
	
	long* _lin_T = (long*)malloc(sizeof(long)*((N) * (N)));
	mallocCheck(_lin_T, ((N) * (N)), long);
	T = (long**)malloc(sizeof(long*)*(N));
	mallocCheck(T, (N), long*);
	for (mz1=0;mz1 < N; mz1++) {
		T[mz1] = &_lin_T[(mz1*(N))];
	}
	
	_flag_last = 'N';
	
	char* _lin__flag_T = (char*)malloc(sizeof(char)*((N) * (N)));
	mallocCheck(_lin__flag_T, ((N) * (N)), char);
	_flag_T = (char**)malloc(sizeof(char*)*(N));
	mallocCheck(_flag_T, (N), char*);
	for (mz1=0;mz1 < N; mz1++) {
		_flag_T[mz1] = &_lin__flag_T[(mz1*(N))];
	}
	memset(_lin__flag_T, 'N', ((N) * (N)));
	#define S0() eval_last(N)
	{
		//Domain
		//{|}
		S0();
	}
	#undef S0
	//Copy scalars to output
	*_local_last = last;
	
	//Memory Free
	free(_lin_T);
	free(T);
	
	
	free(_lin__flag_T);
	free(_flag_T);
}
long eval_T(long N, long i, long j){
	if ( _flag_T(i,j) == 'N' ) {
		_flag_T(i,j) = 'I';
	//Body for T
		T(i,j) = (((j == 0 && i == 0))?(A(i))+(B(j)):(((i == 0 && j >= 1))?(eval_T(N,i,j-1))+(B(j)):(((j == i && i >= 1))?(A(i))+(eval_T(N,i-1,j-1)):(__min_long(eval_T(N,i-1,j),__min_long(((eval_T(N,i-1,j-1))+(A(i)))+(B(j)),eval_T(N,i,j-1)))))));
		_flag_T(i,j) = 'F';
	} else if ( _flag_T(i,j) == 'I' ) {
		printf("There is a self dependence on T at (%d,%d) \n",i,j);
		exit(-1);
	}
	return T(i,j);
}
long eval_last(long N){
	if ( _flag_last == 'N' ) {
		_flag_last = 'I';
	//Body for last
		last = eval_T(N,N-2,N-1);
		_flag_last = 'F';
	} else if ( _flag_last == 'I' ) {
		printf("There is a self dependence on last at () \n");
		exit(-1);
	}
	return last;
}

//Memory Macros
#undef A
#undef B
#undef T
#undef _flag_T


//Common Macro undefs
#undef max
#undef MAX
#undef min
#undef MIN
#undef CEILD
#undef ceild
#undef FLOORD
#undef floord
#undef CDIV
#undef FDIV
#undef LB_SHIFT
#undef MOD
