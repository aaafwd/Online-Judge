/* @JUDGE_ID: 19899RK 10579 C++ "By Anadan" */
// Problem E: Fibonacci Numbers
// Accepted (0.154 seconds using as much as 1960 kbytes)

#include <stdio.h>
#include <string.h>
#define SZ 5000

char * fib[SZ];

void _reverse(char *p){
	char *q = p + strlen(p) - 1;
	while (p < q) *p++ ^= *q-- ^= *p ^= *q;
}

char * add(char *s, char *p){
	int rest = 0;
	char str[1100];

	s = strcpy(str, s);
	while (*p){
		rest += *s - '0' + *p++ - '0';
		if (rest > 9){
			*s++ = rest - 10 + '0';
			rest = 1;
		}else{
			*s++ = rest + '0';
			rest = 0;
		}
	}

	while (*s){
		rest += *s - '0';
		if (rest > 9){
			*s++ = rest - 10 + '0';
			rest = 1;
		}else{
			*s++ = rest + '0';
			rest = 0;
		}
	}

	if (rest) *s++ = '1';
	*s = 0;

	return strcpy(new char [strlen(str) + 1], str);
}

int main(){
	int i;
	char str[1100];

	fib[0] = "1";
	fib[1] = "1";
	for (i = 2 ;; ++i){
		fib[i] = add(fib[i-1], fib[i-2]);
		if (strlen(fib[i]) >= 1000) break;
	}

	while (scanf("%d\n", &i) == 1){
		strcpy(str, fib[i-1]);
		_reverse(str);
		puts(str);
	}
	for (i = 2; i < SZ; ++i) delete fib[i];

	return 0;
}
/* @END_OF_SOURCE_CODE */
