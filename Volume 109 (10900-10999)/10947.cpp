/* @JUDGE_ID: 19899RK 10947 C++ "By Anadan" */
// Bear with me, again..
// Accepted (0.127 seconds using as much as 448 kbytes)

#include <stdio.h>
#include <string.h>
#include <queue>

struct Circle {
	int x, y, r;
} pt[128];
char mask[128];

inline int sqr(int x) { return x*x; }

int main() {
	int K, M, N, i, j, tmp;

	while (scanf("%d%d", &K, &M) == 2) {
		scanf("%d%d%d", &pt[0].x, &pt[0].y, &pt[0].r);
		scanf("%d%d%d", &pt[1].x, &pt[1].y, &pt[1].r);
		scanf("%d", &N);
		N += 2;
		for (i = 2; i < N; ++i) {
			scanf("%d%d%d", &pt[i].x, &pt[i].y, &pt[i].r);
		}
		M *= K;

		std::queue<int> que;
		que.push(0);

		memset(mask, 0, sizeof(mask));
		mask[0] = 1;

		while (!que.empty()) {
			i = que.front();
			if (i == 1) break;
			que.pop();
			for (j = 0; j < N; ++j) {
				if (mask[j]) continue;
				tmp = sqr(pt[i].x - pt[j].x) + sqr(pt[i].y - pt[j].y);
				if (tmp <= sqr(M + pt[i].r + pt[j].r)) {
					que.push(j);
					mask[j] = 1;
				}
			}
		}

		if (mask[1]) puts("Larry and Ryan will escape!");
		else puts("Larry and Ryan will be eaten to death.");
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
