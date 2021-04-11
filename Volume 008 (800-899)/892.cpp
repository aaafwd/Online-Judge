/* @JUDGE_ID: 19899RK 892 C++ "By Anadan" */
// Finding words
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

int main() {
	int i, j;
	char str[128], prev[128], *p;

	prev[0] = 0;
	while (gets(str) && strcmp(str, "#")) {
		if (prev[0]) {
			for (p = str; *p == ' '; ++p);
			strcat(prev, p);
			for (i = j = 0; prev[i] != ' '; ++i) {
				if (('a' <= prev[i] && prev[i] <= 'z') ||
					('A' <= prev[i] && prev[i] <= 'Z'))
				{
					prev[j++] = prev[i];
				}
			}
			strcpy(str, prev + i);
			prev[j] = 0;
			puts(prev);
			prev[0] = 0;
		}

		for (i = j = 0; str[i]; ++i) {
			if (('a' <= str[i] && str[i] <= 'z') ||
				('A' <= str[i] && str[i] <= 'Z') || str[i] == ' ')
			{
				str[j++] = str[i];
			}
		}
		if (i && str[i-1] == '-') str[j++] = '-';
		str[j] = 0;
		if (j && str[j-1] == '-') {
			str[j-1] = 0;
			p = strrchr(str, ' ') + 1;
			strcpy(prev, p);
			*p = 0;
		}
		puts(str);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
