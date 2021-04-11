/* @JUDGE_ID: 19899RK 647 C++ "By Anadan" */
// Chutes and Ladders
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

int main() {
	int dies[1000], i, j, pos[6], players;
	char map[101], skip[6];

	for (i = 0; scanf("%d", &j) == 1 && j; ++i) dies[i] = j;
	while (scanf("%d\n", &players) && players) {
		memset(map, 0, 101);
		while (scanf("%d%d\n", &i, &j) == 2 && i && j) map[i] = j + 1;
		while (scanf("%d", &i) == 1 && i) {
			if (i < 0) map[-i] = -1;
			else map[i] = -2;
		}

		for (i = 0; i < players; ++i) pos[i] = 0, skip[i] = 0;
		for (i = j = 0 ;; ++i, j = (j + 1) % players) {
			if (skip[j]) {
				skip[j] = 0;
				continue;
			}
			pos[j] += dies[i];
			if (pos[j] == 100) break;
			if (pos[j] > 100) {
				pos[j] -= dies[i];
				continue;
			}

			if (map[pos[j]] == -1) skip[j] = 1;
			else if (map[pos[j]] == -2) --j;
			else if (map[pos[j]]) pos[j] = map[pos[j]] - 1;
		}

		printf("%d\n", j + 1);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
