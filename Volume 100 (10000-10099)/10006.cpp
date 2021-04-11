/* @JUDGE_ID: 19899RK 10006 C++ "By Anadan" */ 
// Carmichael Numbers
// Accepted (0.870 seconds using as much as 396 kbytes)

#include <stdio.h>
#include <math.h>

typedef unsigned long dword;

dword powm(dword B, dword P, dword M){
	dword R, R1;
	B %= M;
	R1 = B;
	if (M == 1L) R = 0L; else R = 1L;
	while (P){
		while (!(P & 1L)){
			R1 = (R1 * R1) % M;
			P >>= 1;
		}
		R = (R * R1) % M;
		P--;
	}
	return R;
}

int isprime(dword a){
	dword i, toi;
	if (a == 2L) return 1;
	if (!(a & 1)) return 0;
	toi = (dword)sqrt(a);
	for (i = 3L; i <= toi; i += 2L) if (!(a % i)) return 0;
	return 1;
}

int iscarmichael(dword n){
	dword a;
	if (isprime(n)) return 0;
	for (a = 2L; a < n; a++) if (powm(a, n, n) != a) return 0;
	return 1;
}

int main(){
#ifdef ONLINE_JUDGE
// Accepted (0.111 seconds using as much as 456 kbytes)
	char mask[65001] = {0};
	const int solves[15] = { 561, 1105, 1729, 2465, 2821, 6601, 8911, 10585,
				 15841, 29341, 41041, 46657, 52633, 62745, 63973 };
	int i, n;
	for (n = 0; n < 15; ++n) mask[solves[n]] = 1;

	while (1){
		while ((n = getchar()) == ' ' || n == '\n');
		n -= '0';
		while ((i = getchar()) != ' ' && i != '\n') n = 10*n + i - '0';
		if (n == 0) break;

		if (mask[n]) printf("The number %d is a Carmichael number.\n", n);
		else printf("%d is normal.\n", n);
	}
#else
	dword n;
	while (scanf("%lu", &n) == 1 && n){
		if (iscarmichael(n)) printf("The number %lu is a Carmichael number.\n", n);
		else printf("%lu is normal.\n", n);
	}
#endif
	return 0;
}
/* @END_OF_SOURCE_CODE */
