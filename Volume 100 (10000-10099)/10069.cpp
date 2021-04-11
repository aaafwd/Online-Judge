/* @JUDGE_ID: 19899RK 10069 C++ "By Anadan" */
// Distinct Subsequences
// Accepted (0.092 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

char count[128][128];

void _reverse(char *p){
	char *q = p + strlen(p) - 1;
	while (p < q) *p++ ^= *q-- ^= *p ^= *q;
}

void add(char *p, char *q){
	int rest = 0;

	while (*p && *q){
		rest += *p - '0' + *q - '0';
		if (rest >= 10){
			*p = '0' + rest - 10;
			rest = 1;
		}else{
			*p = '0' + rest;
			rest = 0;
		}
		++p; ++q;
	}

	while (*p){
		rest += *p - '0';
		if (rest >= 10){
			*p = '0' + rest - 10;
			rest = 1;
		}else{
			*p = '0' + rest;
			rest = 0;
		}
		++p;
	}

	while (*q){
		rest += *q - '0';
		if (rest >= 10){
			*p = '0' + rest - 10;
			rest = 1;
		}else{
			*p = '0' + rest;
			rest = 0;
		}
		++p; ++q;
	}

	if (rest) *p++ = '1';
	*p = 0;
}

int main() {
	int set, len, i, j;
	char str[10010], pat[128];

	scanf("%d", &set);
	while (set--) {
		scanf("%s%s", str, pat);
		len = strlen(pat);
		for (i = 1; i <= len; ++i) strcpy(count[i], "0");
		strcpy(count[0], "1");

		for (i = 0; str[i]; ++i) {
			for (j = len-1; j >= 0; --j) {
				if (str[i] == pat[j]) {
					add(count[j+1], count[j]);
				}
			}
		}
		_reverse(count[len]);
		puts(count[len]);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
