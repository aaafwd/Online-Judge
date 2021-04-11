/* @JUDGE_ID: 19899RK 10110 C++ "By Anadan" */
// Light, more light
// Accepted (9.630 seconds using as much as 396 kbytes)
// Too much time !

#include <stdio.h>
#include <math.h>

typedef unsigned long dword;

int main(){
	char res;
	dword i, toi, n;

	while (scanf("%lu", &n) > 0){
		if (n == 0L) break;
		res = 0;

		while (!(n & 1)){
			n >>= 1;
			res ^= 1;
		}

		if (res == 0){
			toi = (dword)sqrt(n);
			for (i = 3L; i <= toi; i += 2L){
				if (!(n % i)){
					while (!(n % i)){
						n /= i;
						res ^= 1;
					}
					if (res) break;
					toi = (dword)sqrt(n);
				}
			}

			if (n > 1) res = 1;
		}

		if (res) printf("no\n"); else printf("yes\n");
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
