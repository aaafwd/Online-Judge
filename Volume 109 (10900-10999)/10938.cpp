/* @JUDGE_ID: 19899RK 10938 C++ "By Anadan" */
// Flea circus
// Accepted (0.883 seconds using as much as 800 kbytes)

#include <stdio.h>
#include <string.h>

int begin[5000*2], next[5000*2], end[5000*2], value[5000*2], sp;
int N, path[5000];
char mask[5000];

int dfs(int x, int y, int len) {
	int i, j;
	mask[x] = 1;
	path[len++] = x;
	if (x == y) return len;
	for (i = begin[x]; i != -1; i = next[i]) {
		if (!mask[value[i]] && (j = dfs(value[i], y, len))) return j;
	}
	return 0;
}

void add(int x, int y) {
	if (begin[x] == -1) begin[x] = end[x] = sp;
	next[end[x]] = sp;
	value[sp] = y;
	next[sp] = -1;
	end[x] = sp;
	++sp;
}

int main() {
	int i, x, y;

	while (scanf("%d", &N) == 1 && N) {
		sp = 0;
		for (i = 0; i < N; ++i) begin[i] = end[i] = -1;
		for (i = 1; i < N;++i) {
			scanf("%d%d", &x, &y); --x; --y;
			add(x, y);
			add(y, x);
		}
		scanf("%d", &i);
		while (i--) {
			scanf("%d%d", &x, &y); --x; --y;
			memset(mask, 0, N);
			x = dfs(x, y, 0);
			if (x & 1) printf("The fleas meet at %d.\n", path[x/2]+1);
			else {
				y = path[x/2];
				x = path[x/2-1];
				if (x > y) { int tmp = x; x = y; y = tmp; }
				printf("The fleas jump forever between %d and %d.\n", x+1, y+1);
			}
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
