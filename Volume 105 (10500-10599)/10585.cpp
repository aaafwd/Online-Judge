/* @JUDGE_ID: 19899RK 10585 C++ "By Anadan" */
// Center of symmetry
// Accepted (0.160 seconds using as much as 560 kbytes)

#include <stdio.h>
#include <stdlib.h>

struct Point {
	int x, y;
} pt[10000];
int N;

int sort_function(const void *a, const void *b) {
	Point *pa = (Point*)a, *pb = (Point*)b;
	if (pa->x < pb->x) return -1;
	if (pa->x > pb->x) return  1;
	if (pa->y < pb->y) return -1;
	if (pa->y > pb->y) return  1;
	return 0;
}

int main() {
	int set, i, max, min, cx2, cy2;
	Point tmp;

	scanf("%d", &set);
	while (set--) {
		scanf("%d", &N);
		for (i = 0; i < N; ++i) scanf("%d%d", &pt[i].x, &pt[i].y);
		if (N <= 2) { puts("yes"); continue; }

		max = min = 0;
		for (i = 1; i < N; ++i) {
			if (pt[i].x < pt[min].x) min = i;
			if (pt[i].x > pt[max].x) max = i;
		}

		if (min == max) {
			max = min = 0;
			for (i = 1; i < N; ++i) {
				if (pt[i].y < pt[min].y) min = i;
				if (pt[i].y > pt[max].y) max = i;
			}
		}

		if (min == max) { puts("yes"); continue; }

		cx2 = pt[min].x + pt[max].x;
		cy2 = pt[min].y + pt[max].y;

		qsort(pt, N, sizeof(Point), sort_function);
		for (i = 0; i < N; ++i) {
			tmp.x = cx2 - pt[i].x;
			tmp.y = cy2 - pt[i].y;
			if (!bsearch(&tmp, pt, N, sizeof(Point), sort_function)) break;
		}
		puts(i < N ? "no" : "yes");
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
