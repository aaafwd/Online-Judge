/* @JUDGE_ID: 19899RK 353 C++ "By Anadan" */ 
// Pesky Palindromes
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

int main(){
	int lens[1000], len, N, i, j, k;
	char str[128], *pl[1000];

	while (scanf("%s", str) == 1){
		N = 0;
		len = strlen(str);
		for (i = 0; i < len; ++i){
			for (j = 0; i + j < len && i >= j; ++j){
				if (str[i - j] != str[i + j]) break;
				for (k = 0; k < N; ++k){
					if (lens[k] != j + j + 1) continue;
					if (strncmp(pl[k], str + i - j, lens[k]) == 0) break;
				}

				if (k == N){
					lens[N] = j + j + 1;
					pl[N++] = str + i - j;
				}
			}

			for (j = 0; i + j + 1 < len && i >= j; ++j){
				if (str[i - j] != str[i + j + 1]) break;
				for (k = 0; k < N; ++k){
					if (lens[k] != j + j + 2) continue;
					if (strncmp(pl[k], str + i - j, lens[k]) == 0) break;
				}

				if (k == N){
					lens[N] = j + j + 2;
					pl[N++] = str + i - j;
				}
			}
		}

		printf("The string '%s' contains %d palindromes.\n", str, N);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
