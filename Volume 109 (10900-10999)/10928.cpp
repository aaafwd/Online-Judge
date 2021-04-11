/* @JUDGE_ID: 19899RK 10928 C++ "By Anadan" */
// My Dear Neighbours
// Accepted (0.066 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

char str[8192];
int count[1024];

int main() {
	int set, i, N, min, out;
	char * p;

	scanf("%d", &set);
	while (set--) {
		scanf("%d", &N);
		while (getchar() != '\n');

		min = N;
		for (i = 0; i < N; ++i) {
			gets(str);
			count[i] = 1;
			for (p = str; *p; ++p) {
				if (*p == ' ') ++count[i];
			}
			if (min > count[i]) min = count[i];
		}

		out = 0;
		for (i = 0; i < N; ++i) {
			if (min == count[i]) {
				if (out) putchar(' ');
				printf("%d", i+1);
				out = 1;
			}
		}
		putchar('\n');
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
