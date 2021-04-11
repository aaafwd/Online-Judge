/* @JUDGE_ID: 19899RK 558 C++ "By Anadan" */
// Wormholes
// Accepted (0.502 seconds using as much as 416 kbytes)

#include <stdio.h>
#include <string.h>

struct Edge {
	int src, dst, time;
} pt[2000];
int N, M;

int BellmanFord() {
	int ro[1000], i, j;

	memset(ro, -1, sizeof(ro));
	ro[0] = 0;
	for (j = 1; j < N; ++j) {
		for (i = 0; i < M; ++i) {
			if (ro[pt[i].src] == -1) continue;
			if (ro[pt[i].dst] == -1 || ro[pt[i].dst] > ro[pt[i].src] + pt[i].time) {
				ro[pt[i].dst] = ro[pt[i].src] + pt[i].time;
			}
		}
	}
	for (i = 0; i < M; ++i) {
		if (ro[pt[i].src] == -1) continue;
		if (ro[pt[i].dst] == -1 || ro[pt[i].dst] > ro[pt[i].src] + pt[i].time) {
			return 0;
		}
	}
	return 1;
}

int main() {
	int set, i;

	scanf("%d", &set);
	while (set--) {
		scanf("%d%d", &N, &M);
		for (i = 0; i < M; ++i) {
			scanf("%d%d%d", &pt[i].src, &pt[i].dst, &pt[i].time);
		}
		puts(BellmanFord() ? "not possible" : "possible");
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
