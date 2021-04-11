/* @JUDGE_ID: 19899RK 688 C++ "By Anadan" */ 
// Mobile Phone Coverage
// Accepted (0.021 seconds with low memory spent)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Square{
	double x, y, r;
}pt[100];

int sort_function(const void *a, const void *b){
	if (*(double *)a < *(double *)b) return -1;
	if (*(double *)a > *(double *)b) return 1;
	return 0;
}

int main(){
	int N, M, i, j, k, m, set = 0;
	double xx[200], yy[200], x, y, u, v, *px, *py, S;
	char map[200][200];

	while (scanf("%d\n", &N) == 1 && N){
		for (M = i = 0; i < N; ++i){
			scanf("%lf%lf%lf\n", &pt[i].x, &pt[i].y, &pt[i].r);
			xx[M] = pt[i].x - pt[i].r; yy[M] = pt[i].y - pt[i].r; ++M;
			xx[M] = pt[i].x + pt[i].r; yy[M] = pt[i].y + pt[i].r; ++M;
		}

		qsort(xx, M, sizeof(double), sort_function);
		qsort(yy, M, sizeof(double), sort_function);

		S = 0.0;
		for (i = 0; i < M; ++i) memset(map[i], 0, M);
		for (m = 0; m < N; ++m){
			x = pt[m].x - pt[m].r; y = pt[m].y - pt[m].r;
			u = pt[m].x + pt[m].r; v = pt[m].y + pt[m].r;
			px = (double *)bsearch(&x, xx, M, sizeof(double), sort_function);
			py = (double *)bsearch(&y, yy, M, sizeof(double), sort_function);

			i = int(px - xx); j = int(py - yy);
			while (i < M - 1 && xx[i + 1] <= u){
				for (k = j; k < M - 1; ++k){
					if (yy[k + 1] > v) break;
					if (map[i][k] == 0){
						S += (xx[i + 1] - xx[i]) * (yy[k + 1] - yy[k]);
						map[i][k] = 1;
					}
				}

				++i;
			}
		}

		printf("%d %.2lf\n", ++set, S);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
