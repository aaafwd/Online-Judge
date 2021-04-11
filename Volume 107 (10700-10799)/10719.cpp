/* @JUDGE_ID: 19899RK 10719 C++ "By Anadan" */
// Quotient Polynomial
// Accepted (0.357 seconds using as much as 428 kbytes)

#include <stdio.h>

int arr[10001];

int main() {
	int k, N, i, x, sgn;

	while (scanf("%d", &k) == 1) {
		while (getchar() != '\n');
		N = 0;
		while ((i = getchar()) != EOF && i != '\n') {
			if ('0' <= i && i <= '9' || i == '-') {
				if (i == '-') { x = 0; sgn = 1; }
				else { x = i - '0'; sgn = 0; }

				while ((i = getchar()) != EOF && '0' <= i && i <= '9') {
					x = x*10 + i - '0';
				}
				if (sgn) x *= -1;
				arr[N++] = x;
				if (i == EOF || i == '\n') break;
			}
		}

		printf("q(x):");
		for (i = 0; i < N-1; ++i) {
			arr[i+1] += arr[i]*k;
			printf(" %d", arr[i]);
		}
		printf("\nr = %d\n\n", arr[i]);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
