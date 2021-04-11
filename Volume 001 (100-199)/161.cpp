/* @JUDGE_ID: 19899RK 161 C++ "By Anadan" */
// Traffic Lights
// Accepted (0.004 seconds with low memory spent)

#include <stdio.h>

int main(){
	int T[101], N, i, j, t, f;

	while (1){
		N = i = 0;
		while (scanf("%d", T + N) == 1 && T[N]){
			if (T[i] > T[N]) i = N;
			++N;
		}
		if (N == 0) break;

		for (t = 2*T[i] + 1; t <= 18001; t += 2*T[i]){
			for (f = t - 1; f < t + T[i] - 6; ++f){
				for (j = 0; j < N; ++j){
					if (i == j) continue;
					if (f > 2*T[j]*((f >> 1) / T[j]) + T[j] - 6) break;
				}

				if (j == N) break;
			}

			if (f < t + T[i] - 6) break;
		}

		if (t <= 18001 && f <= 18000){
			printf("%.2d:", f / 3600);
			f %= 3600;
			printf("%.2d:%.2d\n", f/60, f%60);
		}else printf("Signals fail to synchronise in 5 hours\n");

	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
