/* @JUDGE_ID: 19899RK 10034 C++ "By Anadan" */
// Freckles
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>
#include <string.h>
#include <math.h>

struct Point{
	double x, y;
}pt[100];

inline double sqr(double x) { return x * x; }

int main(){
	int set, N, i, j, k;
	char mask[100];
	double dist[100], sum, min, tmp;

	scanf("%d\n\n", &set);
	while (set--){
		scanf("%d\n", &N);
		for (i = 0; i < N; ++i) scanf("%lf%lf", &pt[i].x, &pt[i].y);
		memset(mask, 0, N);
		mask[0] = 1;

		for (i = 1; i < N; ++i){
			dist[i] = sqr(pt[i].x - pt[0].x) + sqr(pt[i].y - pt[0].y);
		}

		for (sum = 0.0, i = 1; i < N; ++i){
			for (k = 0; mask[k]; ++k);
			min = dist[k];

			for (j = k + 1; j < N; ++j){
				if (mask[j]) continue;
				if (min > dist[j]){
					min = dist[j];
					k = j;
				}
			}

			sum += sqrt(min);
			mask[k] = 1;
			for (j = 0; j < N; ++j){
				if (mask[j]) continue;
				tmp = sqr(pt[k].x - pt[j].x) + sqr(pt[k].y - pt[j].y);
				if (dist[j] > tmp) dist[j] = tmp;
			}
		}

		printf("%.2lf\n", sum);
		if (set) putchar('\n');
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
