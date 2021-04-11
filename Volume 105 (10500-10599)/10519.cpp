/* @JUDGE_ID: 19899RK 10519 C++ "By Anadan" */ 
// !! REALLY STRANGE !!
// Accepted (0.002 seconds with low memory spent)

#include <stdio.h>
#include <string.h>
#define SZ 1000

void _reverse(char *p){
	char *q = p + strlen(p) - 1;
	while (p < q) *p++ ^= *q-- ^= *p ^= *q;
}

int main(){
	int rest, i, j, k;
	char str[SZ], op[SZ], res[SZ], *p;

	while (scanf("%s", str) == 1){
		for (p = str; *p == '0'; ++p);
		if (!*p) --p;
		if (strcmp(p, "0") == 0) puts("1");
		else{
			_reverse(str);

			rest = -1;
			for (i = 0; str[i]; ++i){
				rest += str[i] - '0';
				if (rest < 0){
					op[i] = rest + 10 + '0';
					rest = -1;
				}else{
					op[i] = rest + '0';
					rest = 0;
				}
			}

			p = res;
			rest = 0;
			for (i = 0; str[i]; ++i){
				for (j = 0; j <= i; ++j){
					rest += (str[j] - '0') * (op[i - j] - '0');
				}

				*p++ = rest % 10 + '0';
				rest /= 10;
			}

			for (k = i - 1; k; --k){
				for (j = 0; j < k; ++j){
					rest += (str[i - 1 - j] - '0') * (op[i - k + j]  - '0');
				}

				*p++ = rest % 10 + '0';
				rest /= 10;
			}

			while (rest){
				*p++ = rest % 10 + '0';
				rest /= 10;
			}

			*p = 0;

			rest = 2;
			for (p = res; *p; ++p){
				rest += *p - '0';
				*p = rest % 10 + '0';
				rest /= 10;
			}

			if (rest) *p++ = '1';
			*p = 0;

			_reverse(res);
			for (p = res; *p == '0'; ++p);
			if (!*p) --p;
			puts(p);
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
