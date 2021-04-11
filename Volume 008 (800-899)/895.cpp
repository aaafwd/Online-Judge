/* @JUDGE_ID: 19899RK 895 C++ "By Anadan" */
// Word Problem
// Accepted (0.002 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

int N;
char words[1001][11], lets[26];

int main() {
	int i, res;
	char *p;

	N = 0;
	while (scanf("%s\n", words[N]) == 1 && strcmp(words[N], "#")) {
		++N;
	}

	while (1) {
		memset(lets, 0, sizeof(lets));
		while ((i = getchar()) != EOF && i != '\n' && i != '\r' && i != '#') {
			if ('a' <= i && i <= 'z') ++lets[i - 'a'];
		}
		if (i == '#') break;

		for (res = i = 0; i < N; ++i) {
			for (p = words[i]; *p; ++p) {
				if (lets[*p - 'a']-- == 0) break;
			}
			if (!*p) { ++res; --p; }
			while (p >= words[i]) ++lets[*p-- - 'a'];
		}

		printf("%d\n", res);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
