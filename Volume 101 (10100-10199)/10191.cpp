/* @JUDGE_ID: 19899RK 10191 C++ "By Anadan" */ 
// Longest Nap
// Accepted (0.002 seconds with low memory spent)

#include <stdio.h>
#include <stdlib.h>

struct Period{
	int t1, t2;
}pt[102];

int sort_function(const void *a, const void *b){
	if (((Period *)a)->t1 < ((Period *)b)->t2) return -1;
	return 1;
}

int main(){
	int set = 0, N, i, h1, h2, max;

	while (scanf("%d\n", &N) == 1){
		for (i = 0; i < N; ++i){
			scanf("%d:%d %d:%d", &h1, &pt[i].t1, &h2, &pt[i].t2);
			pt[i].t1 += h1 * 60; pt[i].t2 += h2 * 60;
			while ((h1 = getchar()) != '\n' && h1 != EOF);
		}

		pt[N].t1 = pt[N].t2 = 600; ++N;
		pt[N].t1 = pt[N].t2 = 1080; ++N;
		qsort(pt, N, sizeof(Period), sort_function);

		for (max = -1, i = 0; i < N - 1; ++i){
			h2 = pt[i + 1].t1 - pt[i].t2;
			if (max < h2){
				max = h2;
				h1 = pt[i].t2;
			}
		}

		printf("Day #%d: the longest nap starts at %d:%.2d and will last for ", ++set, h1 / 60, h1 % 60);
		if (max < 60) printf("%d minutes.\n", max);
		else printf("%d hours and %d minutes.\n", max / 60, max % 60);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
