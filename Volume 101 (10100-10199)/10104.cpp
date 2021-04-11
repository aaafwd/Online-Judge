/* @JUDGE_ID: 19899RK 10104 C++ "By Anadan" */
// Euclid Problem
// Accepted (0.020 seconds with low memory spent)

#include <stdio.h>

long gcd(long a, long b){
	long d = 1L;

	while (a && b){
		if (a & 1L){
			if (b & 1L){
				if (a > b) a -= b;
				else b -= a;
			}else b >>= 1;
		}else{
			if (b & 1L) a >>= 1;
			else{
				d <<= 1;
				a >>= 1;
				b >>= 1;
			}
		}
	}

	if (a) d *= a; else d *= b;
	return d;
}

void euclid_alg(long a, long b, long *x, long *y, long *d){
	long q, r, A = 1L, B = 0L, C = 0L, D = 1L, tmp;
	*d = gcd(a, b);
	a /= *d;
	b /= *d;

	while (1){
		r = a % b;
		if (r == 0L){
			*x = B;
			*y = D;
			break;
		}
		q = a / b;
		tmp = A;
		A = B;
		B = tmp - B * q;
		tmp = C;
		C = D;
		D = tmp - D * q;
		a = b; b = r;
	}
}

int main(){
	long a, b, x, y, d;

	while (scanf("%ld%ld", &a, &b) == 2){
		euclid_alg(a, b, &x, &y, &d);
		printf("%ld %ld %ld\n", x, y, d);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
