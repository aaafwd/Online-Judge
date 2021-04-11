/* @JUDGE_ID: 19899RK 10460 C++ "By Anadan" */ 
// Find the Permuted String
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>

int main(){
	int set,  N, i, j, k;
	char str[32], res[32];

	scanf("%d\n", &set);
	while (set--){
		for (i = 0 ;; ++i){
			res[i] = 0;
			if ((str[i] = getchar()) == '\n'){
				str[i] = 0;
				break;
			}
		}

		for (N = 0; (j = getchar()) <= '9' && '0' <= j; N = N * 10 + j - '0');
		--N;

		while (i){
			k = N % i;
			for (j = 0 ;; ++j){
				if (res[j] == 0 && --k < 0) break;
			}
			res[j] = str[i - 1];
			N /= i--;
		}

		puts(res);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
