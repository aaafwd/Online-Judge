/* @JUDGE_ID: 19899RK 10878 C++ "By Anadan" */
// Decode the tape
// Accepted (0.004 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

int main() {
	int i, code;
	char str[16];

	gets(str);
	while (gets(str) && strcmp(str, "___________")) {
		code = 0;
		for (i = 1; i < 10; ++i) {
			if (i == 6) continue;
			code <<= 1;
			if (str[i] == 'o') code |= 1;
		}
		putchar(code);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
