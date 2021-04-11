/* @JUDGE_ID: 19899RK 10173 C++ "By Anadan" */ 
// Smallest Bounding Rectangle
// Accepted (0.223 seconds using as much as 488 kbytes)

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int N;
struct Point{
	double x, y, fi;
}pt[1000], chull[1000];

int sort_function(const void *a, const void *b){
	if (((Point *)a)->fi > ((Point *)b)->fi) return -1;
	return 1;
}

inline int isintriangle(int i, int j, int k){
	double tmp = (pt[k].x - pt[i].x) * (pt[k].y - pt[j].y) - (pt[k].x - pt[j].x) * (pt[k].y - pt[i].y);
	return (tmp < 1e-12);
}

void convex_hull(){
	int i, j, k, stack[1000], sp = 0;

	while (N > 0 && pt[N - 1].fi == -100.0) --N;
	if (N < 3) { N = 0; return; }

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

int main(){
	int set = 0, i, j, k, a, b, c, d;
	double cx, cy, mins, cosa, sina;

	while (scanf("%d\n", &N) == 1 && N){
		cx = cy = 0.0;
		for (i = 0; i < N; ++i){
			scanf("%lf%lf\n", &pt[i].x, &pt[i].y);
			cx += pt[i].x; cy += pt[i].y;
		}
		cx /= N; cy /= N;

		for (i = 0; i < N; ++i){
			if (pt[i].x == cx && pt[i].y == cy) pt[i].fi = -100.0;
			else pt[i].fi = atan2(pt[i].y - cy, pt[i].x - cx);
		}

		qsort(pt, N, sizeof(Point), sort_function);
		convex_hull();

		a = b = c = d = 0;
		for (i = 1; i < N; ++i){
			if (chull[i].x > chull[a].x) a = i;
			if (chull[i].x < chull[b].x) b = i;
			if (chull[i].y > chull[c].y) c = i;
			if (chull[i].y < chull[d].y) d = i;
		}
		mins = (chull[a].x - chull[b].x) * (chull[c].y - chull[d].y);

		for (i = 0; i < N; ++i){
			j = (i == N - 1) ? (0) : (i + 1);

			cx = chull[j].x - chull[i].x;
			cy = chull[j].y - chull[i].y;
			cosa = 1.0 / sqrt(cx * cx + cy * cy);
			sina = cy * cosa;
			cosa *= cx;

			pt[i] = chull[i];
			a = b = c = d = i;
			for (k = 0; k < N; ++k){
				if (k == i) continue;
				cx = chull[k].x - chull[i].x;
				cy = chull[k].y - chull[i].y;
				pt[k].x = cx * cosa + cy * sina + chull[i].x;
				pt[k].y = -cx * sina + cy * cosa + chull[i].y;
				if (pt[k].x > pt[a].x) a = k;
				if (pt[k].x < pt[b].x) b = k;
				if (pt[k].y > pt[c].y) c = k;
				if (pt[k].y < pt[d].y) d = k;
				cx = (pt[a].x - pt[b].x) * (pt[c].y - pt[d].y);
				if (cx >= mins) break;
			}

			if (mins > cx) mins = cx;
		}

		printf("%.4lf\n", mins);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
