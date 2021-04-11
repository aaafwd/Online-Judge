/* @JUDGE_ID: 19899RK 10012 C++ "By Anadan" */ 
// How Big Is It?
// Accepted (1.254 seconds using as much as 392 kbytes)

#include <stdio.h>
#include <math.h>

int N, cur[8];
char mask[8];
double R[8], x[8], min, tmp;

void generate(int n, double minimax){
	int i;

	if (minimax >= min) return;

	if (n == N){
		min = minimax;
		return;
	}

	for (cur[n] = 0; cur[n] < N; ++cur[n]){
		if (mask[cur[n]]) continue;
		x[n] = R[cur[n]];

		for (i = n - 1; i >= 0; --i){
			tmp = x[i] + 2.0 * sqrt(R[cur[i]] * R[cur[n]]);
			if (x[n] < tmp) x[n] = tmp;
		}

		tmp = x[n] + R[cur[n]];
		if (tmp < minimax) tmp = minimax;

		mask[cur[n]] = 1;
		generate(n + 1, tmp);
		mask[cur[n]] = 0;
	}
}

int main(){
	int set, i;

	scanf("%d\n\n", &set);
	while (set--){
		scanf("%d", &N);
		min = 0.0;
		for (i = 0; i < N; ++i){
			scanf("%lf", R + i);
			min += R[i];
			mask[i] = 0;
		}
		min *= 2.0;

		generate(0, 0.0);
		printf("%.3lf\n", min);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
