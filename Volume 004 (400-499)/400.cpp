/* @JUDGE_ID: 19899RK 400 C++ "By Anadan" */
// Unix ls
// Accepted (0.066 seconds with low memory spent)

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int sort_function(const void *a, const void *b) {
	return (strcmp((char *)a, (char *)b));
}

int main() {
	int i, j, N, L, C, R, off;
	char str[100][61], *p;

	while (scanf("%d", &N) == 1) {
		for (i = L = 0; i < N; ++i) {
			scanf("%s", str[i]);
			off = strlen(str[i]);
			if (off > L) L = off;
		}
		qsort((void *)str, N, 61, sort_function);
		for (i = 0; i < N; ++i) {
			off = strlen(str[i]);
			j = L - off;
			p = str[i] + off;
			while(j--) *p++ = ' ';
			*p = 0;
		}
		for (i = 0; i < 60; ++i) putchar('-');
		putchar('\n');
		C = 62 / (L + 2);
		R = (N + C - 1) / C;
		for (i = 0; i < R; ++i) {
			printf("%s", str[i]);
			for (off = i + R, j = 1; j < C; j++, off += R) {
				if (off >= N) break;
				printf("  %s", str[off]);
			}
			putchar('\n');
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
