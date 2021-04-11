/* @JUDGE_ID: 19899RK 10849 C++ "By Anadan" */
// Move the bishop
// Accepted (0.037 seconds with low memory spent)

#include <stdio.h>

inline int abs(int x) { if (x < 0) return -x; return x; }

int getMoves(int x1, int y1, int x2, int y2) {
	if (x1 == x2 && y1 == y2) return 0;
	if (((x1+y1)&1)^((x2+y2)&1)) return -1;
	if (abs(x1-x2) == abs(y1-y2)) return 1;
	return 2;
}

int main() {
	int set, Q, N, x1, y1, x2, y2;

	scanf("%d", &set);
	while (set--) {
		scanf("%d%d", &Q, &N);
		while (Q--) {
			scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
			x1 = getMoves(x1, y1, x2, y2);
			if (x1 < 0) puts("no move");
			else printf("%d\n", x1);
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
