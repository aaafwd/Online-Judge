/* @JUDGE_ID: 19899RK 10820 C++ "By Anadan" */
// Send a Table
// Accepted (0.014 seconds with low memory spent)

#include <stdio.h>
#define SZ 50001

int coprimes[SZ];

int main() {
	int i, j;

	for (i = 0; i < SZ; ++i) coprimes[i] = i;
	for (i = 2; i < SZ; ++i) {
		if (coprimes[i] == i) {
			for (j = i; j < SZ; j += i) {
				coprimes[j] = coprimes[j] / i * (i - 1);
			}
		}
		coprimes[i] += coprimes[i-1] + coprimes[i];
	}

	while (scanf("%d", &i) == 1 && i) {
		printf("%d\n", coprimes[i]);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
