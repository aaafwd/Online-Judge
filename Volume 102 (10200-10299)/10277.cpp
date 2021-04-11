/* @JUDGE_ID: 19899RK 10277 C++ "By Anadan" */ 
// Boastin' Red Socks
// Accepted (0.170 seconds using as much as 396 kbytes)

#include <stdio.h>
#include <math.h>
#define MAX 50000

typedef unsigned int qword;

qword gcd(qword p, qword q){
	while (p && q) if (p > q) p %= q; else q %= p;
	return p + q;
}

int main(){
	int r;
	qword p, q, s, k;
	long long n, m;

	while (scanf("%u%u", &p, &q) == 2 && q){
		if (p == 0) puts("0 2");
		else{
			s = gcd(p, q); p /= s; q /= s;

			for (k = 0, s = 2; s <= MAX; ++s){
				k += (s - 1) << 1;
				if (k % q) continue;
				n = k / q;
				n = ((n * p) << 2) + 1;
				m = (long long)floor(sqrt(n));
				if ((m & 1) && m * m == n){
					r = (m + 1) >> 1;
					if (r <= s) break;
				}
			}

			if (s <= MAX) printf("%d %u\n", r, s - r);
			else puts("impossible");
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
