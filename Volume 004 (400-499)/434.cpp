/* @JUDGE_ID: 19899RK 434 C++ "By Anadan" */
// Matty's Blocks
// Accepted (0.012 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

int N, front[8], right[8], min, max;

void solve() {
	int i, j;
	char mask[8];

	min = max = 0;
	memset(mask, 0, sizeof(mask));

	for (i = 0; i < N; ++i) {
		if (right[i] == 0) continue;
		min += right[i];
		for (j = 0; j < N; ++j) {
			if (!mask[j] && front[j] == right[i]) {
				mask[j] = 1;
				break;
			}
		}
	}

	for (i = 0; i < N; ++i) {
		if (!mask[i]) min += front[i];
	}

	for (i = 0; i < N; ++i) {
		for (j = 0; j < N; ++j) {
			if (right[i] < front[j]) max += right[i];
			else max += front[j];
		}
	}
}

int main() {
	int set, i;

	scanf("%d", &set);
	while (set--) {
		scanf("%d", &N);
		for (i = 0; i < N; ++i) scanf("%d", front+i);
		for (i = 0; i < N; ++i) scanf("%d", right+i);
		solve();
		printf("Matty needs at least %d blocks, and can add at most %d extra blocks.\n", min, max-min);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
