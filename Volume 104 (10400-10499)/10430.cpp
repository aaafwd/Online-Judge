/* @JUDGE_ID: 19899RK 10430 C++ "By Anadan" */ 
// Dear GOD, Pardon Me
// Accepted (0.027 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

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

void mul(char *p, int N){
	int rest = 0;

	while (*p){
		rest += N * (*p - '0');
		*p++ = '0' + (rest % 10);
		rest /= 10;
	}

	while (rest){
		*p++ = '0' + (rest % 10);
		rest /= 10;
	}

	*p = 0;
}

int main(){
	int T, N, i, out = 0;
	char x[250], k[250];

	printf("Dear GOD, Pardon Me\n");
	while (scanf("%d%d\n", &T, &N) == 2){
		if (T < 0 && N < 0) break;
		if (out) putchar('\n'); else out = 1;
		if (T == 0 || N == 0){
			printf("No escape from hell.\n");
			continue;
		}

		x[0] = '0'; k[0] = '1'; x[1] = k[1] = 0;
		for (i = 0; i < N; ++i){
			add(x, k);
			mul(k, T);
		}

		_reverse(x); _reverse(k);
		printf("X = %s\nK = %s\n", x, k);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
