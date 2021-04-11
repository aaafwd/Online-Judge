/* @JUDGE_ID: 19899RK 10801 C++ "By Anadan" */
// Lift Hopping
// Accepted (0.006 seconds with low memory spent)

#include <stdio.h>
#include <string.h>
#define SZ 100

struct Lift {
	int time, len, arr[SZ];
} pt[5];
int N, dst;
char mask[SZ];

inline int abs(int x) { if (x < 0) return -x; return x; }

int solve() {
	int ro[SZ], i, j, k, f, next;

	memset(ro, -1, sizeof(ro));
	ro[0] = 0;
	for (i = 0; i < SZ; ++i) {
		if (ro[i] == -1) continue;

		next = i + 1;
		for (j = 0; j < N; ++j) {
			if (!(mask[i] & (1 << j))) continue;
			for (k = 0; k < pt[j].len; ++k) {
				f = pt[j].arr[k];
				if (ro[f] == -1 || ro[f] > ro[i] + abs(i-f)*pt[j].time + 60) {
					ro[f] = ro[i] + abs(i-f)*pt[j].time + 60;
					if (next > f) next = f;
				}
			}
		}
		i = next - 1;
	}

	return ro[dst] - 60;
}

int main() {
	int i, c, x;

	while (scanf("%d%d", &N, &dst) == 2) {
		for (i = 0; i < N; ++i) scanf("%d", &pt[i].time);

		memset(mask, 0, sizeof(mask));
		while (getchar() != '\n');
		for (i = 0; i < N; ++i) {
			pt[i].len = 0;
			while ((c = getchar()) != '\n') {
				if ('0' <= c && c <= '9') {
					x = c - '0';
					while ((c = getchar()) >= '0' && c <= '9') {
						x = x*10 + c - '0';
					}
					pt[i].arr[pt[i].len++] = x;
					mask[x] |= 1 << i;
					if (c == '\n') break;
				}
			}
		}

		i = (dst == 0) ? (0) : (solve());
		if (i < 0) puts("IMPOSSIBLE");
		else printf("%d\n", i);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
