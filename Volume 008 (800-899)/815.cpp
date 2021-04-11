/* @JUDGE_ID: 19899RK 815 C++ "By Anadan" */ 
// Flooded!
// Accepted (0.100 seconds using as much as 400 kbytes)

#include <stdio.h>
#include <stdlib.h>

int sort_function(const void *a, const void *b){
	if (*(int *)a < *(int *)b) return -1;
	return 1;
}

int main(){
	int set = 0, i, j, N, h[900], level;

	while (scanf("%d%d\n", &N, &i) == 2 && N){
		N *= i;
		for (i = 0; i < N; ++i) scanf("%d", h + i);
		qsort(h, N, sizeof(int), sort_function);

		scanf("%d\n", &level);
		for (i = 0; i < N - 1; ++i){
			j = (h[i + 1] - h[i]) * 100 * (i + 1);
			if (level < j) break;
			level -= j;
		}

		printf("Region %d\n", ++set);
		printf("Water level is %.2lf meters.\n", double(level) * 0.01 / (i + 1) + h[i]);
		if (level) ++i;
		printf("%.2lf percent of the region is under water.\n\n", double(i) / N * 100.0);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
