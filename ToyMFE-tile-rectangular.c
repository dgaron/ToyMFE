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
#include <omp.h>
#include <immintrin.h>
#include <malloc.h>


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
// Reduction Operators
#define RADD(x,y)    ((x)+=(y))
#define RMUL(x,y)    ((x)*=(y))
#define RMAX(x,y)    ((x)=MAX((x),(y)))
#define RMIN(x,y)    ((x)=MIN((x),(y)))

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






//Memory Macros
#define A(i) A[i]
#define B(i) B[i]
#define T(i,j) T[-(i)+(j)]

//Tiling Macros
#define BLOCK_SIZE_ii 100
#define BLOCK_SIZE_jj 4000

void ToyMFE(long N, long* A, long* B, long* last){
	///Parameter checking
	if (!((N >= 1))) {
		printf("The value of parameters are not valid.\n");
		exit(-1);
	}
	//Memory Allocation
	long* T = (long*)malloc(sizeof(long*)*(N));
	mallocCheck(T, (N), long);

	#define S0(i,j) T(i,j) = (A(i))+(B(j))
	#define S1(i,j) T(i,j) = (T(i,j-1))+(B(j))
	#define S2(i,j) T(i,j) = (A(i))+(T(i-1,j-1))
	#define S3(i,j) T(i,j) = __min_long(T(i-1,j),__min_long(((T(i-1,j-1))+(A(i)))+(B(j)),T(i,j-1)))
	#define S4(i0,i1) *last = T(N-2,N-1)
	{
		//Domain
		//{i,j|j==0 && i==0 && N>=1}
		//{i,j|i==0 && j>=1 && N>=1 && N>=j+1}
		//{i,j|j==i && i>=1 && N>=1 && N>=i+1}
		//{i,j|i>=1 && j>=i+1 && N>=1 && N>=i && j>=0 && N>=j+1}
		//{i0,i1|0==-1}
		long c1,c2;
		long ii, jj;
		S0((0),(0));

		// Tiled portion
		for (ii = 1; ii < N - 2; ii += BLOCK_SIZE_ii) {
			for (jj = ii; jj < N - 1; jj += BLOCK_SIZE_jj) {
				if (ii == 1 && (N >= 2)) {
					{
						for(c2=jj; c2 <= min(jj + BLOCK_SIZE_jj, N - 1); c2+=1)
						{
							S1((0),(c2));
						}
					}
				}
				for(c1=ii; c1 <= min(ii + BLOCK_SIZE_ii, N - 2); c1+=1)
				{
					S2((c1),(c1));
					for(c2=c1+1; c2 <= min(jj + BLOCK_SIZE_jj, N - 1); c2+=1)
					{
						S3((c1),(c2));
					}
				}
			}
		} // End tiled loops

		if ((N >= 2)) {
			{
				S2((N-1),(N-1));
			}
		}
		S4(i0,i1);
	}
	#undef S0
	#undef S1
	#undef S2
	#undef S3
	#undef S4
	
	//Memory Free
	free(T);
}

//Memory Macros
#undef A
#undef B
#undef T


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
#undef RADD
#undef RMUL
#undef RMAX
#undef RMIN
