/* @JUDGE_ID: 19899RK 10931 C++ "By Anadan" */
// Parity
// Accepted (0.006 seconds with low memory spent)

#include <stdio.h>

int parity;

void output(int N) {
	if (N) {
		output(N >> 1);
		if (N & 1) ++parity;
		putchar((N & 1) + '0');
	}
}

int main() {
	int N;

	while (scanf("%d", &N) == 1 && N) {
		printf("The parity of ");
		parity = 0;
		output(N);
		printf(" is %d (mod 2).\n", parity);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
