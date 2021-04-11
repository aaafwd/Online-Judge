/* @JUDGE_ID: 19899RK 10054 C++ "By Anadan" */
// The Necklace
// Accepted (1.703 seconds using as much as 452 kbytes)

#include <stdio.h>
#include <string.h>

int map[50][50], degree[50], path[1024], sp;

void euler(int i) {
	int j;
	for (j = 0; j < 50; ++j) {
		while (map[i][j]) {
			--map[i][j];
			--map[j][i];
			euler(j);
		}
	}
	path[sp++] = i;
}

int main() {
	int set, cs = 0, N, i, j, k;

	scanf("%d", &set);
	while (set--) {
		if (cs) putchar('\n');
		printf("Case #%d\n", ++cs);

		memset(map, 0, sizeof(map));
		memset(degree, 0, sizeof(degree));
		scanf("%d", &N);
		for (k = 0; k < N; ++k) {
			scanf("%d%d", &i, &j); --i; --j;
			++map[i][j];
			++map[j][i];
			++degree[i];
			++degree[j];
		}

		for (i = 0; i < 50; ++i) {
			if (degree[i] & 1) break;
		}
		if (i < 50) {
			puts("some beads may be lost");
			continue;
		}

		for (i = 0; degree[i] == 0; ++i);
		sp = 0;
		euler(i);

		if (sp == N + 1) {
			for (i = 0; i < N; ++i) {
				printf("%d %d\n", path[i]+1, path[i+1]+1);
			}
		} else {
			puts("some beads may be lost");
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
