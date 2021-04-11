/* @JUDGE_ID: 19899RK 872 C++ "By Anadan" */
// Ordering
// Accepted (0.002 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

int count, N;
char mask[26], map[26][26], curr[32];

void generate(int i) {
	int j, k;

	if (i >= N) {
		for (j = 0; j < i; ++j) {
			if (j) putchar(' ');
			putchar(curr[j]);
		}
		putchar('\n');
		++count;
		return;
	}

	for (j = 0; j < 26; ++j) {
		if (!mask[j]) continue;
		for (k = 0; k < 26; ++k) if (mask[k] && map[k][j]) break;
		if (k < 26) continue;
		mask[j] = 0;
		curr[i] = 'A' + j;
		generate(i + 1);
		mask[j] = 1;
	}
}

int main() {
	int set, i, j, k;

	scanf("%d", &set);
	while (set--) {
		memset(mask, 0, sizeof(mask));
		memset(map, 0, sizeof(map));

		while ((i = getchar()) != EOF) if ('A' <= i && i <= 'Z') break;
		mask[i - 'A'] = 1;
		while ((i = getchar()) != EOF && i != '\n') {
			if ('A' <= i && i <= 'Z') mask[i - 'A'] = 1;
		}

		while ((i = getchar()) != EOF && i != '\n') {
			if ('A' <= i && i <= 'Z') {
				getchar();
				j = getchar();
				map[i - 'A'][j - 'A'] = 1;
			}
		}

		for (k = 0; k < 26; ++k) {
			for (i = 0; i < 26; ++i) {
				if (i == k || !map[i][k]) continue;
				for (j = 0; j < 26; ++j) {
					if (j == k || !map[k][j]) continue;
					map[i][j] = 1;
				}
			}
		}

		for (N = i = 0; i < 26; ++i) {
			if (mask[i]) ++N;
		}

		count = 0;
		generate(0);
		if (!count) puts("NO");

		if (set) putchar('\n');
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
