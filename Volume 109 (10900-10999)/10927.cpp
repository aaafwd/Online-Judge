/* @JUDGE_ID: 19899RK 10927 C++ "By Anadan" */
// Bright lights
// Accepted (1.381 seconds using as much as 4380 kbytes)

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define SZ 100000

struct Point {
	int x, y, z;
	double a;
	char visible;
} *pt[SZ];

int sortf1(const void * a, const void * b) {
	Point *pa = *(Point**)a, *pb = *(Point**)b;
	if (pa->a < pb->a - 1e-12) return -1;
	else if (pa->a > pb->a + 1e-12) return 1;

	if (pa->x > 0) {
		if (pa->x < pb->x) return -1;
	} else if (pa->x < 0) {
		if (-pa->x < -pb->x) return -1;
	} else {
		if (pa->y < pb->y) return -1;
	}
	return 1;
}

int sortf2(const void * a, const void * b) {
	Point *pa = *(Point**)a, *pb = *(Point**)b;
	if (pa->x < pb->x) return -1;
	if (pa->x > pb->x) return 1;
	if (pa->y < pb->y) return -1;
	return 1;
}

int main() {
	int set = 0, i, N, M;

	for (i = 0; i < SZ; ++i) pt[i] = new Point;

	while (scanf("%d", &N) == 1 && N) {
		for (i = 0; i < N; ++i) {
			scanf("%d%d%d", &pt[i]->x, &pt[i]->y, &pt[i]->z);
			pt[i]->a = atan2(pt[i]->y, pt[i]->x);
			pt[i]->visible = 1;
		}
		qsort(pt, N, sizeof(pt[0]), sortf1);

		for (i = 1; i < N; ++i) {
			if (fabs(pt[i]->a - pt[i-1]->a) < 1e-12) {
				if (pt[i]->z <= pt[i-1]->z) {
					pt[i]->visible = 0;
					pt[i]->z = pt[i-1]->z;
				}
			}
		}

		M = 0;
		for (i = 0; i < N; ++i) {
			if (!pt[i]->visible) {
				*pt[M++] = *pt[i];
			}
		}

		printf("Data set %d:\n", ++set);
		if (M == 0) puts("All the lights are visible.");
		else {
			puts("Some lights are not visible:");
			qsort(pt, M, sizeof(pt[0]), sortf2);
			for (i = 0; i < M; ++i) {
				printf("x = %d, y = %d", pt[i]->x, pt[i]->y);
				if (i < M - 1) puts(";");
				else puts(".");
			}
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
