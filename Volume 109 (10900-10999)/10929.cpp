/* @JUDGE_ID: 19899RK 10929 C++ "By Anadan" */
// You can say 11
// Accepted (0.105 seconds using as much as 388 kbytes)

#include <stdio.h>

int main() {
	int i, rest;
	char str[1024];

	while (scanf("%s", str) == 1) {
		if (str[0] == '0' && str[1] == 0) break;

		printf("%s ", str);
		rest = 0;
		for (i = 0; str[i]; ++i) {
			rest = (rest*10+str[i] - '0')%11;
		}
		if (rest) puts("is not a multiple of 11.");
		else puts("is a multiple of 11.");
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
