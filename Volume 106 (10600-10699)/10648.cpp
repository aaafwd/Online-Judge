/* @JUDGE_ID: 19899RK 10648 C++ "By Anadan" */
// Chocolate Box
// Accepted (0.105 seconds using as much as 392 kbytes)

#include <stdio.h>

double p[101], q[101];

int main(){
	int i, N, M, set = 0;

	while (scanf("%d%d", &N, &M) == 2 && N != -1){
		for (i = 1; i <= M; ++i) p[i] = 0;
		p[0] = 1;

		while (N--){
			for (i = 0; i <= M; ++i) q[i] = 0;
			for (i = 0; i <= M; ++i){
				if (i) q[i] += p[i] * i / M;
				if (i < M) q[i + 1] += p[i] * (M - i) / M;
			}
			for (i = 0; i <= M; ++i) p[i] = q[i];
		}

		printf("Case %d: %.7lf\n", ++set, 1 - p[M]);
	}

	return 0;
}

/* @END_OF_SOURCE_CODE */
