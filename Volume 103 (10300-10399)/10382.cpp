/* @JUDGE_ID: 19899RK 10382 C++ "By Anadan" */
// Watering Grass
// Accepted (0.061 seconds with low memory spent)

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define SZ 10000

int N;
struct Segment{
	double x1, x2;
}pt[SZ];

int sort_function(const void *a, const void *b){
	Segment *ca = (Segment *)a, *cb = (Segment *)b;
	if (ca->x1 < cb->x1) return -1;
	return 1;
}

inline double sqr(double x) { return x*x; }

int main(){
	int i, n, l, w, x, r;
	char flag;
	double tmp, curx;

	while (scanf("%d%d%d\n", &n, &l, &w) == 3){
		N = 0;
		for (i = 0; i < n; ++i){
			scanf("%d%d", &x, &r);
			if (w - r > r) continue;
			tmp = sqrt(sqr(r) - sqr(double(w) * 0.5));
			pt[N].x1 = double(x) - tmp;
			pt[N].x2 = double(x) + tmp;
			++N;
		}

		qsort(pt, N, sizeof(Segment), sort_function);

		r = 0;
		flag = 0;
		curx = 0.0;
		for (i = 0; i < N; ++i){
			if (pt[i].x1 > double(curx) + 1e-12){
				if (flag == 0) break;
				flag = 0;
				curx = tmp;
				++r;
				--i;
			}else{
				if (flag == 0){
					tmp = pt[i].x2;
				}else if (tmp < pt[i].x2) tmp = pt[i].x2;

				flag = 1;
			}
		}

		if (curx < l){
			if (flag == 1){
				curx = tmp;
				++r;
			}
		}

		if (curx < l) printf("-1\n"); else printf("%d\n", r);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
