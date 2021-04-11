/* @JUDGE_ID: 19899RK 10523 C++ "By Anadan" */ 
// VERY EASY !!!
// Accepted (0.520 seconds using as much as 392 kbytes)

#include <stdio.h>
#include <string.h>

void _reverse(char *s){
	char *p = s + strlen(s) - 1;
	while (s < p) *s++ ^= *p-- ^= *s ^= *p;
}

void mul(char *p, int num){
	int rest = 0;

	while (*p){
		rest += (*p - '0') * num;
		*p++ = (rest % 10) + '0';
		rest /= 10;
	}

	while (rest){
		*p++ = (rest % 10) + '0';
		rest /= 10;
	}

	*p = 0;
}

void add(char *p, int num){
	int rest = num;

	while (*p){
		rest += *p - '0';
		*p++ = (rest % 10) + '0';
		rest /= 10;
	}

	while (rest){
		*p++ = (rest % 10) + '0';
		rest /= 10;
	}

	*p = 0;
}

void div(char *p, int num){
	int rest = 0;

	while (*p){
		rest = 10 * rest + (*p - '0');
		*p++ = (rest / num) + '0';
		rest %= num;
	}
}

int main(){
	int a, n, i;
	char res[200], *p;

	while (scanf("%d%d", &n, &a) == 2){
		if (a == 0) puts("0");
		else if (a == 1) printf("%d\n", n * (n + 1) / 2);
		else{
			res[0] = '1'; res[1] = 0;
			for (i = 0; i < n + 1; ++i) mul(res, a);
			mul(res, (a - 1) * n - 1);
			add(res, a);

			_reverse(res);
			div(res, a - 1);
			div(res, a - 1);

			for (p = res; *p == '0'; ++p);
			puts(*p ? p : "0");
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
