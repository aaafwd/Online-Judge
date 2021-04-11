/* @JUDGE_ID: 19899RK 192 C++ "By Anadan" */
// Synchronous Design
// Accepted (0.002 seconds with low memory spent)

#include <stdio.h>
#include <string.h>
#define SZ 128

int N, T;
char map[SZ][SZ], mask[SZ], dfsMask[SZ];
struct Vertex {
	char sync;
	int delay;
} pt[SZ];

int dfs(int x) {
	int i;
	mask[x] = dfsMask[x] = 1;
	for (i = 0; i < N; ++i) {
		if (!map[x][i] || pt[i].sync) continue;
		if (dfsMask[i]) return 1;
		if (!mask[i] && dfs(i)) return 1;
	}
	dfsMask[x] = 0;
	return 0;
}

int isLoopExists() {
	int i;

	memset(mask, 0, sizeof(mask));
	for (i = 0; i < N; ++i) {
		if (!pt[i].sync && !mask[i]) {
			memset(dfsMask, 0, sizeof(dfsMask));
			if (dfs(i)) return 1;
		}
	}
	return 0;
}

int calcMaxDelay() {
	int delay[SZ], i, j, res, next;

	memset(delay, 0, sizeof(delay));
	memset(mask, 0, sizeof(mask));
	memset(dfsMask, 0, sizeof(dfsMask));

	for (i = 0; i < N; ++i) {
		if (pt[i].sync) mask[i] = 1;
	}

	for (i = 0; i < N; ++i) {
		if (!mask[i] || dfsMask[i]) continue;
		mask[i] = 0;
		if (pt[i].sync) dfsMask[i] = 1;
		next = i + 1;
		for (j = 0; j < N; ++j) {
			if (!map[i][j]) continue;
			if (delay[j] < delay[i] + pt[j].delay) {
				delay[j] = delay[i] + pt[j].delay;
				mask[j] = 1;
				if (next > j) next = j;
			}
		}
		i = next - 1;
	}

	res = 0;
	for (i = 0; i < N; ++i) {
		if (pt[i].sync && res < delay[i]) res = delay[i];
	}
	return res;
}

int main() {
	int set, i, j, M;
	char ch[2];

	scanf("%d", &set);
	while (set--) {
		memset(map, 0, sizeof(map));

		scanf("%d%d", &T, &N);
		for (i = 0; i < N; ++i) {
			scanf("%s%d", ch, &M);
			pt[i].sync = (ch[0] != 'a');
			pt[i].delay = M;
			if (pt[i].sync) pt[i].delay = 0;
		}

		scanf("%d", &M);
		while (M--) {
			scanf("%d%d", &i, &j);
			map[i][j] = 1;
		}

		if (isLoopExists()) {
			puts("Circuit contains cycle.");
		} else {
			i = calcMaxDelay();
			if (i > T) puts("Clock period exceeded.");
			else printf("Synchronous design. Maximum delay: %d.\n", i);
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
