/* @JUDGE_ID: 19899RK 10540 C++ "By Anadan" */
// Flowers of a Beautiful Mind
// Accepted (0.223 seconds using as much as 396 kbytes)

#include <stdio.h>
#include <math.h>

const double pi = acos(0.0) * 2.0;

int main(){
	int set = 0, i, R, N, M;
	double vi[50], a, tmp;

	while (scanf("%d%d", &R, &N) == 2 && R){
		M = (N + 1) >> 1;
		printf("Set %d:\n%d\n", ++set, M);

		a = tmp = (pi + pi) / N;
		vi[0] = pi * R * R * N;
		for (i = 1; i < M; ++i, a += tmp){
			vi[i] = (pi - a - sin(a)) * R * R * N;
		}

		tmp = vi[--M];
		printf("%.4lf %.4lf\n", vi[M], vi[M]);
		while (M--){
			printf("%.4lf %.4lf\n", vi[M], vi[M] - vi[M + 1] - tmp);
			tmp += vi[M] - vi[M + 1] - tmp;
			vi[M] = vi[M + 1] + tmp;
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
