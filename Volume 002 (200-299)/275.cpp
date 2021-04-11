/* @JUDGE_ID: 19899RK 275 C++ "By Anadan" */ 
// Expanding Fractions
// Accepted (0.008 seconds with low memory spent)

#include <stdio.h>

int main() {
	int i, n, m, nz[1001], c;

	while (scanf("%d%d", &n, &m) == 2 && (n || m)) {
		for (i = 0; i < m; i++) nz[i] = 0;
		putchar('.');
		for (i = c = 1 ;; i++, c = (c + 1) % 50) {
			if (nz[n]) {
				printf("\nThe last %d digits repeat forever.\n", i - nz[n]);
				break;
			}
			nz[n] = i;
			if (!c) putchar('\n');
			n *= 10; printf("%d", n / m); n %= m;
			if (n == 0) {
				puts("\nThis expansion terminates.");
				break;
			}
		}
		putchar('\n');
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
