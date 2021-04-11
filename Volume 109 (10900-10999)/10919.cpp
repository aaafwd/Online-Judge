/* @JUDGE_ID: 19899RK 10919 C++ "By Anadan" */
// Prerequisites?
// Accepted (0.193 seconds using as much as 392 kbytes)

#include <stdio.h>
#include <stdlib.h>

int sort_function(const void *a, const void *b) {
	if (*(int*)a < *(int*)b) return -1;
	return 1;
}

void myscanf(int &x){
	int i;
	while ((x = getchar()) < '0' || x > '9');
	x -= '0';
	while ((i = getchar()) >= '0' && i <= '9'){
		x = x * 10 + i - '0';
	}
}

int main() {
	int K, M, N, C, i, j, isGood;
	int chosen[128], category[128];

	while (scanf("%d%d", &K, &M) == 2 && K) {
		for (i = 0; i < K; ++i) myscanf(chosen[i]);
		qsort(chosen, K, sizeof(chosen[0]), sort_function);

		isGood = 1;
		while (M--) {
			myscanf(N); myscanf(C);
			for (i = 0; i < N; ++i) myscanf(category[i]);
			if (!isGood) continue;
			qsort(category, N, sizeof(category[0]), sort_function);
			i = j = 0;
			while (C && i < K && j < N) {
				if (chosen[i] == category[j]) {
					++i; ++j; --C;
				} else if (chosen[i] < category[j]) {
					++i;
					if (C > K - i) break;
				} else {
					++j;
					if (C > N - j) break;
				}
			}
			if (C) isGood = 0;
		}
		puts(isGood ? "yes" : "no");
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
