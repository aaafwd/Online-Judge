/* @JUDGE_ID: 19899RK 10037 C++ "By Anadan" */ 
// Bridge
// Accepted (0.021 seconds with low memory spent)

#include <stdio.h>
#include <stdlib.h>

int sort_function(const void *a, const void *b){
	if (*(int *)a < *(int *)b) return -1;
	return 1;
}

int main(){
	int set, N, i, j, t[1000], tot_time;

	scanf("%d\n\n", &set);
	while (set--){
		scanf("%d\n", &N);
		for (i = 0; i < N; ++i) scanf("%d\n", t + i);

		if (N == 1){
			printf("%d\n%d\n", t[0], t[0]);
			if (set) putchar('\n');
			continue;
		}

		qsort(t, N, sizeof(int), sort_function);

		tot_time = 0;
		j = 2 * t[1] - t[0];
		for (i = N - 1; i > 2 && t[i - 1] > j; i -= 2){
			tot_time += t[0] + 2 * t[1] + t[i];
		}

		while (i > 2){
			tot_time += 2 * t[0] + t[i - 1] + t[i];
			i -= 2;
		}

		if (i == 1) tot_time += t[1];
		else tot_time += t[0] + t[1] + t[2];

		printf("%d\n", tot_time);
		for (i = N - 1; i > 2 && t[i - 1] > j; i -= 2){
			printf("%d %d\n%d\n%d %d\n%d\n", t[0], t[1], t[0], t[i - 1], t[i], t[1]);
		}

		while (i > 2){
			printf("%d %d\n%d\n%d %d\n%d\n", t[0], t[i - 1], t[0], t[0], t[i], t[0]);
			i -= 2;
		}

		if (i == 1) printf("%d %d\n", t[0], t[1]);
		else printf("%d %d\n%d\n%d %d\n", t[0], t[1], t[0], t[0], t[2]);

		if (set) putchar('\n');
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
