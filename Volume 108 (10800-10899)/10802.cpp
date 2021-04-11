/* @JUDGE_ID: 19899RK 10802 C++ "By Anadan" */
// Lex Smallest Drive
// Accepted (0.040 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

char map[100][100], mask[100];
int N, pi[100];

void solve(int u) {
	int v, prev = u;
	char solved[100];

	memset(mask, 0, sizeof(mask));
	memset(solved, 0, sizeof(solved));
	while (1) {
		if (mask[u]++ == 2) break;
		pi[u] = prev;
		for (v = 0; v < N; ++v) {
			if (!map[u][v] || v == prev || solved[v]) continue;
			prev = u; u = v;
			break;
		}
		if (v == N) {
			solved[u] = 1;
			if (u == prev) break;
			u = pi[u];
			prev = pi[u];
			--mask[u];
		}
	}
}

void outputPath(int u, int dst) {
	int v, prev = u, path[1024], sp = 0;
	char was[100];

	memset(was, 0, sizeof(was));
	while (1) {
		path[sp++] = u;
		if (u == dst) break;
		pi[u] = prev;
		for (v = 0; v < N; ++v) {
			if (!map[u][v] || v == prev || was[v]) continue;
			prev = u; u = v;
			break;
		}
		if (v == N) {
			was[u] = 1;
			u = pi[u];
			prev = pi[u];
			sp -= 2;
		}
	}

	printf("%d", path[0]);
	for (u = 1; u < sp; ++u) printf(" %d", path[u]);
	putchar('\n');
}

int main() {
	int set, cs = 0, M, S, i, j;

	scanf("%d", &set);
	while (set--) {
		scanf("%d%d%d", &N, &M, &S);
		memset(map, 0, sizeof(map));
		while (M--) {
			scanf("%d%d", &i, &j);
			map[i][j] = map[j][i] = 1;
		}

		solve(S);

		printf("Case #%d:\n", ++cs);
		for (i = 0; i < N; ++i) {
			if (mask[i]) outputPath(S, i);
			else puts("No drive.");
		}
		putchar('\n');
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
