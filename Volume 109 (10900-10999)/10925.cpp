/* @JUDGE_ID: 19899RK 10925 C++ "By Anadan" */
// Krakovia
// Accepted (0.029 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

void _reverse(char *p){
	char *q = p + strlen(p) - 1, ch;
	while (p < q) {
		ch = *p; *p = *q; *q = ch; ++p; --q;
	}
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

void div(char *p, int b, char *q){
	int rest = 0;
	char *s = p + strlen(p) - 1, *res = q;

	while (s >= p){
		rest *= 10;
		rest += *s-- - '0';
		*q++ = '0' + rest / b;
		rest %= b;
	}

	*q-- = 0;
	_reverse(res);
	while (q > res && *q == '0') *q-- = 0;
}

int main() {
	int set = 0, N, F, i;
	char str[512], sum[512];

	while (scanf("%d%d", &N, &F) == 2 && N) {
		strcpy(sum, "0");
		for (i = 0; i < N; ++i) {
			scanf("%s", str);
			_reverse(str);
			add(sum, str);
		}
		div(sum, F, str);
		_reverse(sum);
		_reverse(str);

		printf("Bill #%d costs %s: each friend should pay %s\n\n", ++set, sum, str);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
