/* @JUDGE_ID: 19899RK 10229 C++ "By Anadan" */ 
// Modular Fibonacci
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>

typedef unsigned long long _int64;

struct Matrix{
	long m;
	_int64 a, b, c, d;

	void operator *= (Matrix mtrx){
		_int64 t1 = (a*mtrx.a + b*mtrx.c) % m;
		_int64 t2 = (a*mtrx.b + b*mtrx.d) % m;
		_int64 t3 = (c*mtrx.a + d*mtrx.c) % m;
		_int64 t4 = (c*mtrx.b + d*mtrx.d) % m;
		a = t1; b = t2;
		c = t3; d = t4;
	}
};

long fibo_mod(long n, long m){
	long i = n >> 1;
	Matrix R = { m, 1L, 0L, 0L, 1L }, R1 = { m, 1L, 1L, 1L, 2L };

	while (i){
		while (!(i & 1L)){
			R1 *= R1;
			i >>= 1;
		}
		R *= R1;
		--i;
	}

	if (n & 1L) return long((R.c + R.d) % m);
	else return long((R.a + R.b) % m);
}

int main(){
	long n, m;

	while (scanf("%ld%ld", &n, &m) == 2){
		if (m == 0L || n == 0L) printf("0\n");
		else if (n <= 2L) printf("1\n");
		else{
			m = 1L << m;
			printf("%ld\n", fibo_mod(n-1, m));
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
