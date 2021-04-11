/* @JUDGE_ID: 19899RK 332 C++ "By Anadan" */
// Rational Numbers from Repeating Fractions
// Accepted (0.390 seconds using as much as 400 kbytes)

#include <stdio.h>
#include <math.h>

long getNOD(long a, long b){
	long i, res = 1;
	for (i = 2; i <= sqrt(a); i++){
		while (!(a % i)){
			if (!(b % i)){
				b /= i;
				res *= i;
			}
			a /= i;
		}
	}
	if ((a > 1) && (!(b % a))) res *= a;
	return res;
}

int main(){
	int j, k, set = 0, o1, o2;
	long d, tmp, n, m;

	while (scanf("%d 0.%n%ld%n\n", &j, &o1, &d, &o2) > 0){
		if (j == -1) break;
		printf("Case %d: ", ++set);
		k = o2 - o1 - j;
		n = 1L;
		while (k--) n *= 10;
		m = n;
		k = j;
		while (k--) m *= 10;
		if (n == m){
			n = d;
		}else{
			m -= n;
			n = d;
			while (j--) d /= 10;
			n -= d;
		}
		tmp = getNOD(n, m);
		if (tmp) { n /= tmp; m /= tmp; }
		if (n) printf("%ld/%ld\n", n, m);
		else printf("0/1\n");
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
