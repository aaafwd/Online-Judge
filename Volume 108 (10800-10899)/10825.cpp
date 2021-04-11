/* @JUDGE_ID: 19899RK 10825 C++ "By Anadan" */
// Anagram and Multiplication
// Accepted (0.002 seconds with low memory spent)

#include <stdio.h>

typedef long long qword;

int main() {
	int M, N, i, j, arr[8];
	qword tmp;

	while (scanf("%d%d", &M, &N) == 2 && M) {
		tmp = N;
		for (i = 1; i < M; ++i) tmp *= N;
		if ((tmp - 1) % (M + 1)) puts("Not found.");
		else {
			tmp = (tmp - 1) / (M + 1);
			for (i = 0; i < M; ++i) {
				arr[i] = tmp % N;
				tmp /= N;
			}
			for (i = 0; i < M; ++i) {
				for (j = i + 1; j < M; ++j) {
					if (arr[i] == arr[j]) break;
				}
				if (j < M) break;
			}

			if (i < M) puts("Not found.");
			else {
				printf("%d", arr[M-1]);
				for (i = M-2; i >= 0; --i) printf(" %d", arr[i]);
				putchar('\n');
			}
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
