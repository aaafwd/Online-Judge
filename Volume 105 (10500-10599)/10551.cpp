/* @JUDGE_ID: 19899RK 10551 C++ "By Anadan" */
// Basic remains
// Accepted (0.006 seconds with low memory spent)

#include <stdio.h>

int getMod(char * str, int base, int m) {
	int rest = 0, i;
	for (i = 0; str[i]; ++i) {
		rest = (rest*base + str[i] - '0') % m;
	}
	return rest;
}

void basePrint(int x, int base) {
	if (x < base) putchar(x + '0');
	else {
		basePrint(x/base, base);
		putchar(x%base + '0');
	}
}

int main() {
	int base, m, i;
	char s1[1024], s2[16];

	while (scanf("%d%s%s", &base, s1, s2) == 3 && base) {
		for (m = i = 0; s2[i]; ++i) m = m*base + s2[i] - '0';
		i = getMod(s1, base, m);
		basePrint(i, base);
		putchar('\n');
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
