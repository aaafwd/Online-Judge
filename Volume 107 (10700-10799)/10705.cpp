/* @JUDGE_ID: 19899RK 10705 C++ "By Anadan" */
// The Fun Number System
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>

typedef long long qword;

int main() {
	int set, k, i;
	char str[128], res[128];
	qword N, tmp;

	scanf("%d", &set);
	while (set--) {
		scanf("%d%s%lld", &k, str, &N);

		res[k] = 0;
		tmp = 1;
		for (i = 0; i < k; ++i, tmp <<= 1) {
			if (N & tmp) {
				if (str[k-1-i] == 'p') N -= tmp;
				else N += tmp;
				res[k-1-i] = '1';
			} else {
				res[k-1-i] = '0';
			}
		}
		puts(N ? "Impossible" : res);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
