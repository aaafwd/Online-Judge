/* @JUDGE_ID: 19899RK 313 C++ "By Anadan" */
// Intervals
// Accepted (0.070 seconds using as much as 428 kbytes)

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

struct interv{
	double x1, x2;
}pt[500];

int sort_function(const void *a, const void *b){
	interv *ia = (interv *)a, *ib = (interv *)b;
	if (ia->x1 > ib->x1) return 1;
	return -1;
}

int main(){
	int i, N;
	double bx, by, x, y, r, sina, cosa;

	while (scanf("%d", &N) > 0){
		if (N == 0) break;
		scanf("%lf%lf", &bx, &by);
		for (i = 0; i < N; i++){
			scanf("%lf%lf%lf", &x, &y, &r);
			x -= bx; y -= by;
			sina = r / sqrt(x*x + y*y);
			cosa = sqrt(1.0 - sina*sina);
			pt[i].x1 = bx - by * (x*cosa + y*sina) / (-x*sina + y*cosa);
			pt[i].x2 = bx - by * (x*cosa - y*sina) / (x*sina + y*cosa);
		}
		qsort((void *)pt, N, sizeof(interv), sort_function);
		for(i = 0; i < N;){
			x = pt[i].x1; y = pt[i].x2;
			for (i++; i < N; i++){
				if (pt[i].x1 <= y){
					if (pt[i].x2 > y) y = pt[i].x2;
				}else break;
			}
			printf("%.2lf %.2lf\n", x, y);
		}
		printf("\n");
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
