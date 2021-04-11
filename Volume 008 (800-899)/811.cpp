/* @JUDGE_ID: 19899RK 811 C++ "By Anadan" */ 
// The Fortified Forest
// Accepted (0.227 seconds using as much as 400 kbytes)

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Tree{
	int x, y, v, l;
	double fi;
}pt[15], arr[15];
double rest;

inline double sqr(double x) { return x * x; }

int sort_function(const void *a, const void *b){
	if (((Tree *)a)->fi > ((Tree *)b)->fi) return -1;
	return 1;
}

int isintriangle(int i, int j, int k){
	int det = (arr[k].x - arr[i].x) * (arr[k].y - arr[j].y) - (arr[k].x - arr[j].x) * (arr[k].y - arr[i].y);
	if (det < 0) return 1;
	return 0;
}

int enclosed(int N, int len){
	int i, j, k, stack[15], sp = 0;
	double cx = 0, cy = 0;

	if (N < 2){
		rest = len;
		return 1;
	}

	for (i = 0; i < N; ++i){
		cx += arr[i].x;
		cy += arr[i].y;
	}
	cx /= N; cy /= N;

	for (i = 0; i < N; ++i){
		if (fabs(arr[i].x - cx) < 1e-12 && fabs(arr[i].y - cy) < 1e-12){
			arr[i].fi = -100;
		}else arr[i].fi = atan2(arr[i].y - cy, arr[i].x - cx);
	}

	qsort(arr, N, sizeof(Tree), sort_function);
	while (N > 1 && fabs(arr[i].fi + 100) < 1e-12) --N;
	if (N < 2){
		rest = len;
		return 1;
	}

	for (i = j = 0; i < N; ++i) if (arr[i].x < arr[j].x || (arr[i].x == arr[j].x && arr[i].y < arr[j].y)) j = i;

	stack[sp++] = j++; j %= N; k = j;
	stack[sp++] = j++; j %= N;

	while (j != k){
		while (sp > 1 && isintriangle(stack[sp - 2], j, stack[sp - 1])) --sp;
		stack[sp++] = j++; j %= N;
	}

	cx = len;
	N = sp;
	for (i = 0; i < N - 1; ++i){
		j = i + 1;
		cx -= sqrt(sqr(arr[stack[i]].x - arr[stack[j]].x) + sqr(arr[stack[i]].y - arr[stack[j]].y));
		if (cx < 0) return 0;
	}

	rest = cx;
	return (cx >= 0);
}

int main(){
	int set = 0, N, i, j, k, cur, len, tr, tot, min, trees, best[15];
	double extra;

	while (scanf("%d", &N) == 1 && N){
		trees = N;
		for (min = i = 0; i < N; ++i){
			scanf("%d%d%d%d", &pt[i].x, &pt[i].y, &pt[i].v, &pt[i].l);
			min += pt[i].v;
		}

		for (i = 1; i < (1 << N); ++i){
			tot = cur = len = tr = 0;
			for (k = 0, j = i; k < N; j >>= 1, ++k){
				if (j & 1){
					cur += pt[k].v;
					len += pt[k].l;
					++tr;
				}else{
					arr[tot++] = pt[k];
				}
			}

			if (cur > min) continue;
			if (cur == min && tot >= trees) continue;

			if (enclosed(tot, len)){
				min = cur;
				trees = tr;
				tot = 0;
				extra = rest;
				for (k = 0, j = i; j; j >>= 1, ++k){
					if (j & 1) best[tot++] = k;
				}
			}
		}

		if (set) putchar('\n');
		printf("Forest %d\n", ++set);
		fputs("Cut these trees:", stdout);
		for (i = 0; i < trees; ++i) printf(" %d", best[i] + 1);
		printf("\nExtra wood: %.2lf\n", extra);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
