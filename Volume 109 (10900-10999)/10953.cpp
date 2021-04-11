/* @JUDGE_ID: 19899RK 10953 C++ "By Anadan" */
// Stochastic Digit Generator
// Accepted (0.064 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

double map[64][11], p[10];

void solve(char * str) {
	int i, j, k, r;

	for (i = 0; i < 64; ++i) {
		for (j = 0; j < 11; ++j) map[i][j] = 0;
	}
	map[0][0] = 1;

	for (i = 0; str[i]; ++i) {
		for (r = 0; r < 11; ++r) {
			for (k = 0; k < 10; ++k) {
				if (str[i] == '*') {
					map[i+1][(r*10+k)%11] += map[i][r]*p[k];
				} else if (str[i] == '0' + k) {
					map[i+1][(r*10+k)%11] += map[i][r];
				}
			}
		}
	}
}

int main() {
	int i, k, N, set = 0, rest;
	char str[64];
	double x;

	while (scanf("%d", &N) == 1 && N) {
		for (i = 0; i < 10; ++i) p[i] = 0;
		for (i = 0; i < N; ++i) {
			scanf("%d%lf", &k, &x);
			p[k] = x;
		}

		printf("Case %d:\n", ++set);
		scanf("%d", &N);
		while (N--) {
			scanf("%s%d", str, &rest);
			solve(str);
			printf("%.8lf\n", map[strlen(str)][rest]);
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
