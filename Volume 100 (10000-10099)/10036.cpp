/* @JUDGE_ID: 19899RK 10036 C++ "By Anadan" */
// Divisibility
// Accepted (0.676 seconds using as much as 388 kbytes)

#include <stdio.h>
#include <string.h>

int main(){
	int N, K, i, j, x, set;
	char rest[100], restnew[100];

	scanf("%d", &set);

	while (set--){
		scanf("%d%d", &N, &K);
		memset(rest, 0, K);
		rest[0] = 1;
		for (i = 0; i < N; ++i){
			scanf("%d", &x);
			if (x < 0) x = -x;
			x %= K;
			memset(restnew, 0, K);
			for (j = 0; j < K; ++j){
				if (rest[j]){
					restnew[(j + x) % K] = 1;
					restnew[(j + K - x) % K] = 1;
				}
			}
			memcpy(rest, restnew, K);
		}

		if (rest[0]) printf("Divisible\n");
		else printf("Not divisible\n");
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
