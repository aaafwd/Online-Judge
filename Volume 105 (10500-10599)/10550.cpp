/* @JUDGE_ID: 19899RK 10550 C++ "By Anadan" */
// Combination Lock
// Accepted (0.004 seconds with low memory spent)

#include <stdio.h>

int main() {
	int curr, a1, a2, a3, res;

	while (scanf("%d%d%d%d", &curr, &a1, &a2, &a3) == 4) {
		if (!curr && !a1 && !a2 && !a3) break;
		res = 1080;

		curr = curr - a1;
		if (curr < 0) curr += 40;
		res += 9 * curr;

		curr = a2 - a1;
		if (curr < 0) curr += 40;
		res += 9 * curr;

		curr = a2 - a3;
		if (curr < 0) curr += 40;
		res += 9 * curr;

		printf("%d\n", res);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
