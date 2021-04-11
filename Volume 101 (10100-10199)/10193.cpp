/* @JUDGE_ID: 19899RK 10193 C++ "By Anadan" */
// All You Need Is Love
// Accepted (0.000 seconds with low memory spent)

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

long getnum(char *s){
	long res = 0L;
	while (*s){
		res <<= 1;
		res += *s++ - '0';
	}
	return res;
}

int main(){
	int p, N;
	long a, b;
	char str[32];

	scanf("%d\n", &N);
	for (p = 1; p <= N; ++p){
		scanf("%s\n", str);
		a = getnum(str);
		scanf("%s\n", str);
		b = getnum(str);
		if (gcd(a, b) > 1L) printf("Pair #%d: All you need is love!\n", p);
		else printf("Pair #%d: Love is not all you need!\n", p);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
