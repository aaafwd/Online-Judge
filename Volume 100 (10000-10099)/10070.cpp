/* @JUDGE_ID: 19899RK 10070 C++ "By Anadan" */
// Leap Year or Not Leap Year and ...
// Accepted (0.025 seconds with low memory spent)

#include <stdio.h>
#include <ctype.h>

int main() {
	int c, rest4 = -1, rest15, rest55, rest100, rest400;
	char leap;

	while(1) {
		while (!isdigit(c = getc(stdin))) if (c == EOF) return 0;
		if (rest4 != -1) putchar('\n');
		rest4 = rest15 = rest55 = rest100 = rest400 = c - '0';
		while (isdigit(c = getc(stdin))) {
			c -= '0';
			rest4 = (rest4 * 10 + c) % 4;
			rest15 = (rest15 * 10 + c) % 15;
			rest55 = (rest55 * 10 + c) % 55;
			rest100 = (rest100 * 10 + c) % 100;
			rest400 = (rest400 * 10 + c) % 400;
		}
		leap = 0;
		if ((!rest4) && (rest100 || (!rest400))) leap = 1;
		if (leap) puts("This is leap year.");
		if (!rest15) puts("This is huluculu festival year.");
		if (leap && (!rest55)) puts("This is bulukulu festival year.");
		if ((!leap) && rest15) puts("This is an ordinary year.");
	}
}
/* @END_OF_SOURCE_CODE */
