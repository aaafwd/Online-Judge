/* @JUDGE_ID: 19899RK 10920 C++ "By Anadan" */
// Spiral Tap
// Accepted (0.754 seconds using as much as 384 kbytes)

#include <stdio.h>

int main() {
	int sz, p, i, j, sum, x, y;

	while (scanf("%d%d", &sz, &p) == 2 && sz) {
		sum = 1;
		for (i = 1 ;; i += 2) {
			sum += 4*(i-1);
			if (sum >= p) break;
		}

		j = (i-2)*(i-2)+1;
		if (j <= p && p < j+i-1) {
			x = sz/2 + i/2;
			y = sz/2 + i/2 - 1 - (p-j);
		}
		j += i-1;
		if (j <= p && p < j+i-1) {
			x = sz/2 + i/2 - 1 - (p-j);
			y = sz/2 - i/2;
		}
		j += i-1;
		if (j <= p && p < j+i-1) {
			x = sz/2 - i/2;
			y = sz/2 - i/2 + 1 + (p-j);
		}
		j += i-1;
		if (j <= p && p < j+i-1) {
			x = sz/2 - i/2 + 1 + (p-j);
			y = sz/2 + i/2;
		}
		if (p == 1) {
			x = sz/2;
			y = sz/2;
		}
		printf("Line = %d, column = %d.\n", x+1, y+1);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
