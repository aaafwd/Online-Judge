/* @JUDGE_ID: 19899RK 10038 C++ "By Anadan" */
// Jolly Jumpers
// Accepted (0.020 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

int main(){
	int i, j, k, N;
	char mask[3000];

	while (scanf("%d", &N) == 1){
		scanf("%d", &j);
		memset(mask, 0, N);
		for (i = 1; i < N; ++i){
			scanf("%d", &k);
			j -= k;
			if (j < 0) j = -j;
			if (j >= N) break;
			if (mask[j]) break;
			mask[j] = 1;
			j = k;
		}

		if (i < N){
			for (++i; i < N; ++i) scanf("%*d");
			printf("Not jolly\n");
		}else printf("Jolly\n");
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
