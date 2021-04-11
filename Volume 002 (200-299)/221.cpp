/* @JUDGE_ID: 19899RK 221 C++ "By Anadan" */
// Urban Elevations
// Accepted (0.059 seconds with low memory spent)

#include <stdio.h>
#include <stdlib.h>

int N, curr;
struct Building {
	int n;
	double x, y, w, d, h;
} pt[100];

int sort_function(const void *a, const void *b) {
	Building *ba = (Building *)a, *bb = (Building *)b;
	if (ba->x < bb->x) return -1;
	if (ba->x > bb->x) return 1;
	if (ba->y < bb->y) return -1;
	return 1;
}

int visible(double x1, double x2) {
	int i;

	if (pt[curr].h == 0.0) return 0;
	for (i = 0; i < N; ++i) {
		if (i == curr || pt[curr].h > pt[i].h || pt[curr].y < pt[i].y) continue;
		if (pt[i].x <= x1) {
			if (x1 < pt[i].x + pt[i].w) {
				x1 = pt[i].x + pt[i].w;
				if (x1 >= x2) break;
			}
		}else break;
	}

	if (x1 >= x2) return 0;
	return 1;
}

int main() {
	int i, set = 0;
	char printed;
	double x, y, w, d, h;

	while (scanf("%d", &N) == 1 && N) {
		for (i = 0; i < N; ++i) {
			scanf("%lf%lf%lf%lf%lf\n", &x, &y, &w, &d, &h);
			pt[i].x = x; pt[i].y = y; pt[i].w = w;
			pt[i].d = d; pt[i].h = h;
			pt[i].n = i + 1;
		}

		qsort(pt, N, sizeof(Building), sort_function);
		if (set) putchar('\n');
		printf("For map #%d, the visible buildings are numbered as follows:\n", ++set);
		
		printed = 0;
		for (curr = 0; curr < N; ++curr) {
			if (visible(pt[curr].x, pt[curr].x + pt[curr].w)) {
				if (printed) putchar(' '); else printed = 1;
				printf("%d", pt[curr].n);
			}
		}
		putchar('\n');
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
