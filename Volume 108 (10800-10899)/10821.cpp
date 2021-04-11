/* @JUDGE_ID: 19899RK 10821 C++ "By Anadan" */
// Constructing BST
// Accepted (0.025 seconds with low memory spent)

#include <stdio.h>

void generate(int a, int b, int H) {
	if (a > b) return;
	else if (a == b) printf(" %d", a);
	else if (a+1 == b) printf(" %d %d", a, b);
	else {
		int c = b + 1 - (1<<(H-1));
		if (c < a) c = a;
		printf(" %d", c);
		generate(a, c-1, H-1);
		generate(c+1, b, H-1);
	}
}

int main() {
	int set = 0, N, H;

	while (scanf("%d%d", &N, &H) == 2 && N) {
		printf("Case %d:", ++set);
		if (1<<H <= N) {
			puts(" Impossible.");
		} else {
			generate(1, N, H);
			putchar('\n');
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
