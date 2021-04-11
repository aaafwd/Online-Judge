/* @JUDGE_ID: 19899RK 305 C++ "By Anadan" */
// Joseph
// ONLINE_JUDGE: Accepted (0.002 seconds with low memory spent)
// Accepted (8.110 seconds using as much as 380 kbytes)

#include <stdio.h>
#include <string.h>

int main(){
	char flags[28];
	int i, j, k, k2, m, rest, pos;
	int solves[14] = { 0, 2, 7, 5, 30, 169, 441, 1872, 7632, 1740, 93313, 459901, 1358657, 2504881 };

#ifndef ONLINE_JUDGE

	for (k = 1; k < 14; k++){
		k2 = k << 1;
		for (m = k + 1; ; m++){
			memset(flags, 0, 28);
			for (rest = k2, pos = i = 0; i < k; i++, rest--){
				j = m % rest;
				if (!j) j += rest;
				while (1){
					if (!flags[pos]) j--;
					if (!j) break;
					pos = (pos + 1) % k2;
				}
				if (pos < k) goto next_m;
				flags[pos] = 1;
			}
			break;
			next_m: continue;
		}
		solves[k] = m;
	}

#endif

	while (scanf("%d", &k) > 0){
		if (k == 0) break;
		printf("%d\n", solves[k]);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
