/* @JUDGE_ID: 19899RK 10832 C++ "By Anadan" */
// Yoyodyne Propulsion Systems
// Accepted (0.002 seconds with low memory spent)

#include <stdio.h>
#include <string.h>
#include <math.h>

struct Point {
	int x, y, z;
} pt[32];

inline int sqr(int x) { return x * x; }

int main() {
	int set = 0, f, b, r, N, i, j, k, min, tmp, x, y, z, success;
	double fuel, traveled, sum, dist, time, tt;
	char mask[32];

	while (scanf("%d%d%d%d", &f, &b, &r, &N) == 4 && f) {
		for (i = 0; i < N; ++i) scanf("%d%d%d", &pt[i].x, &pt[i].y, &pt[i].z);

		fuel = f;
		x = y = 0; z = 1;
		success = 1;
		traveled = sum = time = 0;
		memset(mask, 0, sizeof(mask));

		for (i = 0; i < N; ++i) {
			min = -1;
			for (j = 0; j < N; ++j) {
				if (mask[j]) continue;
				tmp = sqr(pt[j].x - x) + sqr(pt[j].y - y) + sqr(pt[j].z - z);
				if (min == -1 || min > tmp) {
					min = tmp;
					k = j;
				}
			}
			mask[k] = 1;
			dist = sqrt(min);
			tt = dist / r;
			fuel -= tt * b;

			if (success && fuel <= -1e-12) {
				success = 0;
				traveled = sum + fuel / b * r + dist;
			}

			sum += dist;
			time += tt;
			x = pt[k].x;
			y = pt[k].y;
			z = pt[k].z;
		}

		if (success) printf("Mission %d: SUCCESS!! Time: %.2lf  Traveled: %.2lf  Fuel Left: %.2lf\n", ++set, time, sum, fuel);
		else printf("Mission %d: FAILURE!! Traveled: %.2lf  From Home: %.2lf\n", ++set, traveled, sum - traveled);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
