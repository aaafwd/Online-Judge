/* @JUDGE_ID: 19899RK 858 C++ "By Anadan" */ 
// Berry Picking
// Accepted (0.057 seconds with low memory spent)

#include <stdio.h>
#include <stdlib.h>

struct Point{
	int x, y;
}pt[10000];

int sort_function(const void *a, const void *b){
	if (*(double *)a < *(double *)b) return -1;
	return 1;
}

int main(){
	int set, N, M, i, j, k, x;
	double arr[10000], threshold;

	scanf("%d\n\n", &set);
	while (set--){
		scanf("%d\n", &N);
		for (i = 0; i < N; ++i) scanf("%d%d\n", &pt[i].x, &pt[i].y);
		scanf("%lf%d\n", &threshold, &x);

		for (M = i = 0; i < N; ++i){
			j = (i == N - 1) ? (0) : (i + 1);
			k = i;

			if (pt[j].x > pt[k].x) j ^= k ^= j ^= k;
			if (pt[j].x < x && x < pt[k].x){
				arr[M++] = pt[j].y + double(x - pt[j].x) * (pt[k].y - pt[j].y) / double(pt[k].x - pt[j].x);
			}
		}

		qsort(arr, M, sizeof(double), sort_function);
		for (i = 0; i < M - 1; i += 2){
			threshold -= arr[i + 1] - arr[i];
			if (threshold < 1e-12) break;
		}

		printf((threshold < 1e-12) ? ("YES\n") : ("NO\n"));
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
