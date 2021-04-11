/* @JUDGE_ID: 19899RK 10098 C++ "By Anadan" */
// Generating Fast, Sorted Permutation
// Accepted (0.850 seconds using as much as 396 kbytes)

#include <stdio.h>
#include <string.h>

int len, A[100];
char str[12];

void func(int n) {
	int i;

	if (n == len) {
		str[n] = 0;
		puts(str);
		return;
	}

	for (i = 0; i < 100; i++) {
		if (A[i]) {
			A[i]--;
			str[n] = i + 32;
			func(n + 1);
			A[i]++;
		}
	}
}

int main() {
	int set;
	char *p;

	scanf("%d", &set);
	while(set--) {
		scanf("%s", str);
		memset(A, 0, sizeof(A));
		for (p = str; *p; ++p) {
			++A[*p - 32];
		}
		len = strlen(str);
		func(0);
		putchar('\n');
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
