/* @JUDGE_ID: 19899RK 837 C++ "By Anadan" */ 
// Light and Transparencies
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>
#include <stdlib.h>
#define NL 100

struct Line{
	double x1, x2, r;
}pt[NL];

int sort_function(const void *a, const void *b){
	if (*(double *)a < *(double *)b) return -1;
	if (*(double *)a > *(double *)b) return 1;
	return 0;
}

int main(){
	int set, i, j, N, P;
	double points[NL * 2], trans[NL * 2], *ptr;

	scanf("%d\n\n", &set);
	while (set--){
		scanf("%d\n", &N);
		for (P = i = 0; i < N; ++i){
			scanf("%lf%*s%lf%*s%lf\n", &pt[i].x1, &pt[i].x2, &pt[i].r);
			if (pt[i].x1 > pt[i].x2){
				points[P] = pt[i].x1;
				pt[i].x1 = pt[i].x2;
				pt[i].x2 = points[P];
			}
			points[P] = pt[i].x1; trans[P++] = 1.0;
			points[P] = pt[i].x2; trans[P++] = 1.0;
		}

		qsort(points, P, sizeof(double), sort_function);
		for (i = 0; i < N; ++i){
			ptr = (double *)bsearch(&pt[i].x1, points, P, sizeof(double), sort_function);
			j = int(ptr - points);
			while (j < P - 1 && points[j + 1] <= pt[i].x2 + 1e-12) trans[j++] *= pt[i].r;
		}

		printf("%d\n-inf %.3lf 1.000\n", P + 1, points[0]);
		for (i = 0; i < P - 1; ++i){
			printf("%.3lf %.3lf %.3lf\n", points[i], points[i + 1], trans[i]);
		}
		printf("%.3lf +inf 1.000\n", points[i]);

		if (set) putchar('\n');
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
