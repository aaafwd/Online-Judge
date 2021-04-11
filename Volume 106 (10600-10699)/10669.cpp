/* @JUDGE_ID: 19899RK 10669 C++ "By Anadan" */
// Three powers
// Accepted (0.002 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

typedef unsigned long long qword;
char powers3[64][64];

void mul(char *dst, char *src, int x) {
	int rest = 0;
	while (*src) {
		rest += (*src++ - '0') * x;
		*dst++ = (rest % 10) + '0';
		rest /= 10;
	}
	while (rest) {
		*dst++ = (rest % 10) + '0';
		rest /= 10;
	}
	*dst = 0;
}

void _reverse(char * p) {
	char * q = p + strlen(p) - 1;
	while (p < q) *p++ ^= *q-- ^= *p ^= *q;
}

int main() {
	int i, flag;
	qword N;

	strcpy(powers3[0], "1");
	for (i = 1; i < 64; ++i) mul(powers3[i], powers3[i-1], 3);
	for (i = 1; i < 64; ++i) _reverse(powers3[i]);

	while (scanf("%llu", &N) == 1 && N) {
		for (flag = i = 0, N -= 1; N != 0; N >>= 1, ++i) {
			if (N & 1) {
				if (flag) printf(", ");
				else { flag = 1, printf("{ "); }
				printf("%s", powers3[i]);
			}
		}
		if (flag) printf(" }\n");
		else puts("{ }");
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
