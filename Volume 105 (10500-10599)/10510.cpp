/* @JUDGE_ID: 19899RK 10510 C++ "By Anadan" */
// Cactus
// Accepted (0.105 seconds using as much as 1092 kbytes)

#include <stdio.h>
#include <string.h>

int N, listVertex[10000], listNext[10000], degree[10000], lowpg[10000], count;
struct Vertex {
	int st, end;
} pt[10000];

int dfs(int x, int low) {
	int i, j;

	degree[x] = lowpg[x] = ++count;
	if (pt[x].st == -1) return 1;

	for (i = pt[x].st; i != -1; i = listNext[i]) {
		j = listVertex[i];
		if (degree[j]) {
			if (degree[j] < low) return 1;
			lowpg[x] = degree[j];
			low = degree[x];
		} else {
			if (dfs(j, low)) return 1;
			if (lowpg[x] > lowpg[j]) lowpg[x] = lowpg[j];
			if (lowpg[x] < degree[x]) {
				low = degree[x] = ++count;
			}
		}
	}
	return 0;
}

int main() {
	int set, i, j, M, sp;

	scanf("%d", &set);
	while (set--) {
		sp = 0;
		scanf("%d%d", &N, &M);
		memset(degree, 0, sizeof(degree));
		memset(pt, -1, sizeof(pt));
		while (M--) {
			scanf("%d%d", &i, &j);
			++degree[i];
			--degree[j];
			listVertex[sp] = j;
			listNext[sp] = -1;
			if (pt[i].st == -1) {
				pt[i].st = pt[i].end = sp;
			} else {
				listNext[pt[i].end] = sp;
				pt[i].end = sp;
			}
			++sp;
		}

		if (N < 2) { puts("YES"); continue; }

		count = 0;
		for (i = 0; i < N; ++i) if (degree[i]) break;
		if (i < N || dfs(0, -1)) puts("NO");
		else {
			for (i = 0; i < N; ++i) if (!degree[i]) break;
			if (i < N) puts("NO"); else puts("YES");
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
