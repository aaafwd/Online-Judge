/* @JUDGE_ID: 19899RK 10050 C++ "By Anadan" */
// Hartals
// Accepted (0.010 seconds with low memory spent)

#include <stdio.h>

int main(){
	int set, N, P, i, j, h[100], res;

	scanf("%d", &set);
	while (set--){
		scanf("%d%d", &N, &P);
		for (i = 0; i < P; ++i) scanf("%d", h + i);
		for (res = i = 0; i < N; ++i){
			if (i % 7 == 5 || i % 7 == 6) continue;
			for (j = 0; j < P; ++j) if (!((i + 1) % h[j])) break;
			if (j < P) ++res;
		}

		printf("%d\n", res);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
