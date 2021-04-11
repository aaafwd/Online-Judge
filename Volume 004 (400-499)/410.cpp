/* @JUDGE_ID: 19899RK 410 C++ "By Anadan" */ 
// Station Balance
// Accepted (0.187 seconds using as much as 396 kbytes)

#include <stdio.h>
#include <string.h>
#include <math.h>

int N, M, mass[10];
char mask[10], best[10];
double avg, imb, tmp, addmin;

void generate(int g, int rest, double curr){
	int i, j;

	if (imb <= curr + addmin * (N - g) || rest > (N - g) * 2) return;

	if (rest == 0){
		curr += avg * (N - g);
		if (imb > curr){
			imb = curr;
			memcpy(best, mask, M);
		}

		return;
	}

	if (g == N - 1){
		tmp = 0.0;
		for (i = 0; i < M; ++i){
			if (mask[i] == 0) tmp += mass[i];
		}

		curr += fabs(tmp - avg);
		if (imb > curr){
			imb = curr;
			memcpy(best, mask, M);
		}

		return;
	}

	for (i = g; i < M; ++i) if (mask[i] == 0) break;
	mask[i] = ++g;

	generate(g, rest - 1, curr + fabs(avg - mass[i]));

	if (rest - 2 <= (N - g) * 2){
		for (j = i + 1; j < M; ++j){
			if (mask[j]) continue;
			mask[j] = g;
			generate(g, rest - 2, curr + fabs(avg - mass[i] - mass[j]));
			mask[j] = 0;
		}
	}

	mask[i] = 0;
}

int main(){
	int set = 0, i, j;

	while (scanf("%d%d", &N, &M) == 2){
		imb = 1e+8;
		avg = 0.0;
		for (i = 0; i < M; ++i){
			scanf("%d", mass + i);
			avg += mass[i];
		}
		avg /= N;
		addmin = avg;

		for (i = 0; i < M; ++i){
			if (addmin > fabs(avg - mass[i])) addmin = fabs(avg - mass[i]);
			for (j = i + 1; j < M; ++j){
				if (addmin > fabs(avg - mass[i] - mass[j])) addmin = fabs(avg - mass[i] - mass[j]);
			}
		}

		memset(mask, 0, M);
		generate(0, M, 0.0);

		printf("Set #%d\n", ++set);
		for (j = 0; j < M; ++j) if (best[j] == 0) best[j] = N;
		for (i = 0; i < N; ++i){
			printf(" %d:", i);
			for (j = 0; j < M; ++j) if (best[j] == i + 1) printf(" %d", mass[j]);
			putchar('\n');
		}
		printf("IMBALANCE = %.5lf\n\n", imb);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */

