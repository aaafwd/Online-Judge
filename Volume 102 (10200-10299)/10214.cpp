/* @JUDGE_ID: 19899RK 10214 C++ "By Anadan" */ 
// Trees in a Wood.
// Accepted (2.426 seconds using as much as 396 kbytes)

#include <stdio.h>

int gcd(int a, int b){
	while (a && b) if (a > b) a %= b; else b %= a;
	return a + b;
}

int main(){
	int a, b, c, i, fi[2001];
	double res, tmp;

	for (a = 1; a < 2001; ++a){
		fi[a] = b = a;
		for (i = 2; i * i <= b; ++i){
			if (!(b % i)){
				fi[a] = fi[a] / i * (i - 1);
				while (!(b % i)) b /= i;
			}
		}

		if (b != 1) fi[a] = fi[a] / b * (b - 1);
	}

	while (scanf("%d%d\n", &a, &b) == 2 && a){
		res = 1.0;
		for (i = 1; i <= a; ++i){
			c = b / i;
			res += c * fi[i];
			c = c * i + 1;
			while (c <= b){
				if (gcd(c++, i) == 1) ++res;
			}
		}

		tmp = 2.0 * double(a) * b + a + b;
		res = 2.0 * res / tmp;
		printf("%.7lf\n", res);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
