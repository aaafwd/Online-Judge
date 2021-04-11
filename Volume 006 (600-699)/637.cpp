/* @JUDGE_ID: 19899RK 637 C++ "By Anadan" */
// Booklet Printing
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>

int main() {
	int i, N, sheets, l, r;

	while (scanf("%d", &N) > 0) {
		if (N == 0) break;
		printf("Printing order for %d pages:\n", N);
		if (N == 1) printf("Sheet 1, front: Blank, 1\n");
		else {
			sheets = (N + 3) >> 2;
			r = sheets << 2;
			for (i = l = 1; i <= sheets; i++) {
				printf("Sheet %d, front: ", i);
				if (r > N) printf("Blank, "); else printf("%d, ", r);
				printf("%d\n", l++);
				printf("Sheet %d, back : %d, ", i, l++);
				if (--r > N) printf("Blank\n"); else printf("%d\n", r);
				--r;
			}
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
