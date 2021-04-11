/* @JUDGE_ID: 19899RK 10714 C++ "By Anadan" */
// Ants
// Accepted (0.219 seconds using as much as 388 kbytes)

#include <stdio.h>

int main() {
	int set, L, N, i, x, min, max, tmin;

	scanf("%d", &set);
	while (set--) {
		scanf("%d%d", &L, &N);
		if (N-- == 0) { puts("0 0"); continue; }

		scanf("%d", &x);
		min = max = x;
		tmin = (x <= L - x) ? (x) : (L - x);

		while (N--) {
			while ((x = getchar()) < '0' || x > '9');
			x -= '0';
			while ((i = getchar()) != EOF && '0' <= i && i <= '9'){
				x = x * 10 + i - '0';
			}

			if (x <= L - x) {
				if (tmin < x) tmin = x;
				if (min > x) min = x;
			} else {
				if (max < x) max = x;
				x = L - x;
				if (tmin < x) tmin = x;
			}
		}

		if (max < L - min) max = L - min;
		printf("%d %d\n", tmin, max);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
