/* @JUDGE_ID: 19899RK 10417 C++ "By Anadan" */ 
// Gift Exchanging
// Accepted (0.834 seconds using as much as 392 kbytes)

#include <stdio.h>
#include <math.h>

int N, first, gifts[5], sav[5];
double p[12][5], w[5], sum;

void doit(int n, double cur){
	int i, j;

	if (n == N){
		w[first] += cur / sav[first];
		sum += cur;
		return;
	}

	if (n == 0){
		for (i = 0; i < 5; ++i){
			first = i;
			if (gifts[i] && p[n][i] > 1e-10){
				--gifts[i];
				doit(n + 1, cur * p[n][i] * (gifts[i] + 1));
				++gifts[i];
			}
		}
		return;
	}

	for (i = 0; i < 5; ++i){
		if (gifts[i] == 0 || p[n][i] < 1e-10) continue;
		--gifts[i];
		doit(n + 1, cur * p[n][i] * (gifts[i] + 1));
		++gifts[i];
	}
}

int main(){
	int set, i, j;
	double tmp, max;

	scanf("%d\n", &set);
	while (set--){
		scanf("%d\n", &N);
		for (i = 0; i < 5; ++i){
			scanf("%d", gifts + i);
			w[i] = 0.0;
			sav[i] = gifts[i];
		}
		for (i = 0; i < N; ++i){
			for (j = 0; j < 5; ++j){
				scanf("%lf", &tmp);
				p[i][j] = tmp * 10.0;
			}
		}

		sum = 0.0;
		doit(0, 1.0);

		max = -1.0;

		for (i = 0; i < 5; ++i){
			if (max < w[i] / sum){
				max = w[i] / sum;
				j = i;
			}
		}

		printf("%d %.3lf\n", j + 1, max);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
