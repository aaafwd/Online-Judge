/* @JUDGE_ID: 19899RK 735 C++ "By Anadan" */
// Dart-a-Mania
// Accepted (0.040 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

int main(){
	int i, j, k, N, c, p;
	char flags[61];

	memset(flags, 1, 21);
	memset(flags + 21, 0, 40);
	for (i = 7; i <= 20; i++) flags[i + i] = flags[i + i + i] = 1;
	flags[50] = 1;

	while (scanf("%d", &N) > 0){
		if (N <= 0) break;
		c = p = 0;
		for (i = 60; i >= 0; i--){
			if (flags[i] == 0 || i > N) continue;
			for (j = i; j >= 0; j--){
				if (flags[j] == 0 || i + j > N) continue;
				k = N - i - j;
				if (k > j) break;
				if (flags[k]){
					++c;
					if (i == j){
						if (j == k) ++p;
						else p += 3;
					}else if (j == k) p += 3;
					else p += 6;
				}
			}
		}
		if (c){
			printf("NUMBER OF COMBINATIONS THAT SCORES %d IS %d.\n", N, c);
			printf("NUMBER OF PERMUTATIONS THAT SCORES %d IS %d.\n", N, p);
		}else printf("THE SCORE OF %d CANNOT BE MADE WITH THREE DARTS.\n", N);
		printf("**********************************************************************\n");
	}

	printf("END OF OUTPUT\n");
	return 0;
}
/* @END_OF_SOURCE_CODE */
