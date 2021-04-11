/* @JUDGE_ID: 19899RK 440 C++ "By Anadan" */
// Eeny Meeny Moo
// Accepted (1.970 seconds using as much as 384 kbytes)

#include <stdio.h>
#include <string.h>

int main(){
	int solves[150], n, pos, k, dk;
	char flags[150];

	for (n = 3; n < 150; n++){
		for (solves[n] = 2; ;solves[n]++){
			memset(flags, 0, n);
			pos = 0;
			k = n - 2;
			flags[0] = 1;
			while (k--){
				dk = solves[n] % (k + 2);
				if (!dk) dk = solves[n];
				while (dk){
					pos = (pos + 1) % n;
					if (!flags[pos]) dk--;
				}
				if (pos == 1) goto next_n;
				flags[pos] = 1;
			}
			break;
			next_n: continue;
		}
	}

	while (scanf("%d", &n) > 0){
		if (n == 0) break;
		printf("%d\n", solves[n]);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
