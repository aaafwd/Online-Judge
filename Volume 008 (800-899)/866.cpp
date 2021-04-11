/* @JUDGE_ID: 19899RK 866 C++ "By Anadan" */
// Intersecting line segments
// Accepted (0.002 seconds with low memory spent)

#include <stdio.h>

struct Line {
	int x1, y1, x2, y2;
} pt[1000];

int intersect(int i, int j){
	int det = (pt[i].x2 - pt[i].x1) * (pt[j].y1 - pt[j].y2) - (pt[i].y2 - pt[i].y1) * (pt[j].x1 - pt[j].x2);
	int it1 = (pt[j].x1 - pt[i].x1) * (pt[j].y1 - pt[j].y2) - (pt[j].y1 - pt[i].y1) * (pt[j].x1 - pt[j].x2);
	int it2 = (pt[i].x2 - pt[i].x1) * (pt[j].y1 - pt[i].y1) - (pt[i].y2 - pt[i].y1) * (pt[j].x1 - pt[i].x1);

	if (det == 0) return 0;
	if (det < 0) { det = -det; it1 = -it1; it2 = -it2; }
	return (0 < it1 && it1 < det && 0 < it2 && it2 < det);
}

int main() {
	int set, N, i, j, res;

	scanf("%d", &set);
	while (set--) {
		scanf("%d", &N);
		for (res = i = 0; i < N; ++i) {
			++res;
			scanf("%d%d%d%d", &pt[i].x1, &pt[i].y1, &pt[i].x2, &pt[i].y2);
			for (j = 0; j < i; ++j) {
				if (intersect(i, j)) res += 2;
			}
		}

		printf("%d\n", res);

		if (set) putchar('\n');
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
