/* @JUDGE_ID: 19899RK 445 C++ "By Anadan" */
// Marvelous Mazes
// Accepted (0.002 seconds with low memory spent)

#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main() {
	int n;
	char str[140], *p;

	while (gets(str)) {
		if (str[0] == 0) putchar('\n');
		else {
			p = strtok(str, "!");
			while (p) {
				while (*p) {
					n = 0;
					while (isdigit(*p)) n += *p++ - '0';
					if (*p == 'b') *p = ' ';
					while (n--) printf("%c", *p);
					p++;
				}
				putchar('\n');
				p = strtok(NULL, "!");
			}
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
