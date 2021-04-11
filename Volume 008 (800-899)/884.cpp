/* @JUDGE_ID: 19899RK 884 C++ "By Anadan" */
// Factorial Factors
// Accepted (0.713 seconds using as much as 4296 kbytes)

#include <stdio.h>
#include <string.h>
#define SZ 1000001

int res[SZ];

int main() {
	int i, j, k, tmp;

	memset(res, 0, sizeof(res));
	for (i = 2; i < SZ; ++i) {
		if (res[i]) continue;
		k = i;
		tmp = (SZ + i - 1) / i;
		while (1) {
			for (j = k; j < SZ; j += k) {
				++res[j];
			}
			if (k > tmp) break;
			k *= i;
		}
	}
	for (i = 3; i < SZ; ++i) res[i] += res[i-1];

	while (scanf("%d", &i) == 1) {
		printf("%d\n", res[i]);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
