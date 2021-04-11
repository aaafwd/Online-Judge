/* @JUDGE_ID: 19899RK 10065 C++ "By Anadan" */ 
// Useless Tile Packers
// Accepted (0.002 seconds with low memory spent)

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int N;
struct Point{
	int x, y;
	double fi;
}pt[100], chull[100];

int sort_function(const void *a, const void *b){
	if (((Point *)a)->fi > ((Point *)b)->fi) return -1;
	return 1;
}

inline int isintriangle(int i, int j, int k){
	int tmp = (pt[k].x - pt[i].x) * (pt[k].y - pt[j].y) - (pt[k].x - pt[j].x) * (pt[k].y - pt[i].y);
	return (tmp <= 0);
}

void convex_hull(){
	int i, j, k, stack[100], sp = 0;

	while (N > 0 && pt[N - 1].fi == -100.0) --N;

	for (j = i = 0; i < N; ++i){
		if (pt[i].x < pt[j].x || (pt[i].x == pt[j].x && pt[i].y < pt[j].y)) j = i;
	}

	stack[sp++] = j++; j %= N; k = j;
	stack[sp++] = j++; j %= N;
	while (j != k){
		while (sp > 1 && isintriangle(stack[sp - 2], j, stack[sp - 1])) --sp;
		stack[sp++] = j++; j %= N;
	}

	N = sp - 1;
	for (i = 0; i < N; ++i) chull[i] = pt[stack[i]];
}

int getarea(Point *p){
	int i, s = 0;

	for (i = 1; i < N - 1; ++i){
		s += (p[i].x - p[0].x) * (p[i + 1].y - p[0].y) - (p[i].y - p[0].y) * (p[i + 1].x - p[0].x);
	}

	return (s < 0) ? (-s) : (s);
}

int main(){
	int set = 0, i, s1, s2;
	double cx, cy;

	while (scanf("%d\n", &N) == 1 && N){
		cx = cy = 0.0;
		for (i = 0; i < N; ++i){
			scanf("%d%d\n", &pt[i].x, &pt[i].y);
			cx += pt[i].x; cy += pt[i].y;
		}
		cx /= N; cy /= N;
		s1 = getarea(pt);

		for (i = 0; i < N; ++i){
			if (pt[i].x == cx && pt[i].y == cy) pt[i].fi = -100.0;
			else pt[i].fi = atan2(pt[i].y - cy, pt[i].x - cx);
		}

		qsort(pt, N, sizeof(Point), sort_function);
		convex_hull();
		s2 = getarea(chull);

		printf("Tile #%d\nWasted Space = %.2lf %%\n\n", ++set, double(s2 - s1) / s2 * 100.0);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
