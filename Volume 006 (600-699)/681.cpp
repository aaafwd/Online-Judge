/* @JUDGE_ID: 19899RK 681 C++ "By Anadan" */ 
// Convex Hull Finding
// Accepted (0.480 seconds using as much as 444 kbytes)

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int N;
struct Point{
	int x, y;
	double fi;
}pt[1001], chull[1001];

inline double sqr(double x) { return x * x; }

int sort_function(const void *a, const void *b){
	if (((Point *)a)->fi < ((Point *)b)->fi) return -1;
	return 1;
}

int isintriangle(int i, int j, int k){
	int det = (pt[k].x - pt[i].x) * (pt[k].y - pt[j].y) - (pt[k].x - pt[j].x) * (pt[k].y - pt[i].y);
	if (det >= 0) return 1;
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
		if (pt[i].y < pt[j].y || (pt[i].y == pt[j].y && pt[i].x < pt[j].x)) j = i;
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
	int set, i;
	double cx, cy;

	scanf("%d\n", &set);
	printf("%d\n", set);

	while (set--){
		scanf("%d\n", &N); --N;
		cx = cy = 0.0;
		for (i = 0; i < N; ++i){
			scanf("%d%d\n", &pt[i].x, &pt[i].y);
			cx += pt[i].x;
			cy += pt[i].y;
		}
		scanf("%*d%*d%*d\n");

		cx /= N; cy /= N;
		for (i = 0; i < N; ++i){
			if (pt[i].y == cy && pt[i].x == cx) pt[i].fi = -100.0;
			else pt[i].fi = atan2(pt[i].y - cy, pt[i].x - cx);
		}

		qsort(pt, N, sizeof(Point), sort_function);
		convex_hull();

		printf("%d\n", N);
		for (i = 0; i < N; ++i) printf("%d %d\n", chull[i].x, chull[i].y);
		if (set) printf("-1\n");
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
