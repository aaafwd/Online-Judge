/* @JUDGE_ID: 19899RK 10866 C++ "By Anadan" */
// Magic Bitstrings
// Accepted (0.109 seconds using as much as 492 kbytes)

#include <stdio.h>
#include <string.h>

typedef long long qword;

char str[110000];

int main() {
	int p, i;
	qword tmp;

	while (scanf("%d", &p) == 1 && p){
		if (p == 2) puts("Impossible");
		else {
			memset(str, '1', sizeof(str));
			str[p - 1] = 0;
			for (i = 1; i <= p-1; ++i) {
				tmp = i;
				tmp *= i;
				tmp %= p;
				--tmp;
				str[(int)tmp] = '0';
			}
			puts(str);
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
