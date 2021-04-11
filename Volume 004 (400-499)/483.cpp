/* @JUDGE_ID: 19899RK 483 C++ "By Anadan" */
// Word Scramble
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

char * _strrev(char *s) {
	char *p = s + strlen(s) - 1, *res = s;
	while (s < p) {
		*s ^= *p; *p ^= *s; *s ^= *p;
		++s; --p;
	}
	return res;
}

int main() {
	char str[512], *p;

	while (gets(str)) {
		p = strtok(str, " \n");
		printf("%s", _strrev(p));
		p = strtok(NULL, " \n");
		while (p) {
			printf(" %s", _strrev(p));
			p = strtok(NULL, " \n");
		}
		putchar('\n');
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
