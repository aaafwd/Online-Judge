/* @JUDGE_ID: 19899RK 218 C++ "By Anadan" */ 
// Moth Eradication
// Accepted (0.133 seconds using as much as 476 kbytes)

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int N;
struct Point{
	double x, y, fi;
}pt[1001], chull[1001];

inline double sqr(double x) { return x * x; }

int sort_function(const void *a, const void *b){
	if (((Point *)a)->fi > ((Point *)b)->fi) return -1;
	return 1;
}

int isintriangle(int i, int j, int k){
	double det = (pt[k].x - pt[i].x) * (pt[k].y - pt[j].y) - (pt[k].x - pt[j].x) * (pt[k].y - pt[i].y);
	if (det < 0) return 1;
	return 0;
}

void convex_hull(){
	int i, j, k, sp = 0, stack[1001];

	while (N > 0 && pt[N - 1].fi == -100.0) --N;
	if (N == 0){
		chull[N++] = pt[0];
		return;
	}

	for (j = 0, i = 1; i < N; ++i){
		if (pt[i].x < pt[j].x || (pt[i].x == pt[j].x && pt[i].y < pt[j].y)) j = i;
	}

	stack[sp++] = j++; j %= N; k = j;
	stack[sp++] = j++; j %= N;

	while (j != k){
		while (sp > 1 && isintriangle(stack[sp - 2], j, stack[sp - 1])) --sp;
		stack[sp++] = j++; if (j == N) j = 0;
	}

	N = sp;
	for (i = 0; i < N; ++i) chull[i] = pt[stack[i]];
}

int main(){
	int set = 0, i;
	double cx, cy;

	while (scanf("%d\n", &N) == 1 && N){
		cx = cy = 0.0;
		for (i = 0; i < N; ++i){
			scanf("%lf%lf\n", &pt[i].x, &pt[i].y);
			cx += pt[i].x;
			cy += pt[i].y;
		}

		cx /= N; cy /= N;
		for (i = 0; i < N; ++i){
			if (pt[i].y == cy && pt[i].x == cx) pt[i].fi = -100.0;
			else pt[i].fi = atan2(pt[i].y - cy, pt[i].x - cx);
		}

		qsort(pt, N, sizeof(Point), sort_function);
		convex_hull();

		cx = 0.0;
		if (set) putchar('\n');
		printf("Region #%d:\n", ++set);
		printf("(%.1lf,%.1lf)", chull[0].x, chull[0].y);
		for (i = 1; i < N; ++i){
			printf("-(%.1lf,%.1lf)", chull[i].x, chull[i].y);
			cx += sqrt(sqr(chull[i].x - chull[i - 1].x) + sqr(chull[i].y - chull[i - 1].y));
		}

		printf("\nPerimeter length = %.2lf\n", cx);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
