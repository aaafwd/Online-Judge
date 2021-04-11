/* @JUDGE_ID: 19899RK 619 C++ "By Anadan" */ 
// Numerically Speaking
// Accepted (0.043 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

void _reverse(char *s){
	char *p = s + strlen(s) - 1;
	while (s < p) *s++ ^= *p-- ^= *s ^= *p;
}

void getword(char *p, char *res){
	int rest;
	char buf[32], num[32], *q, *sav = res;

	strcpy(num, p);
	while (num[0]){
		rest = 0;

		p = num + strlen(num) - 1;
		while (*p == '0') *p-- = '9';
		--p[0];

		for (p = buf, q = num; *q; ++q){
			rest = rest * 10 + *q - '0';
			*p++ = '0' + (rest / 26);
			rest %= 26;
		}
		*p = 0;
		*res++ = 'a' + rest;
		for (p = buf; *p == '0'; ++p);
		strcpy(num, p);
	}
	*res = 0;
	_reverse(sav);
}

void mul(char *p, int base){
	int rest = 0;

	while (*p){
		rest += (*p - '0') * base;
		*p++ = '0' + (rest % 10);
		rest /= 10;
	}

	while (rest){
		*p++ = '0' + (rest % 10);
		rest /= 10;
	}
	*p = 0;
}

void add(char *p, int rest){
	while (*p){
		rest += *p - '0';
		*p++ = '0' + (rest % 10);
		rest /= 10;
	}
	while (rest){
		*p++ = '0' + (rest % 10);
		rest /= 10;
	}
	*p = 0;
}

void getnum(char *p, char *res){
	strcpy(res, "0");
	while (*p){
		mul(res, 26);
		add(res, *p++ - 'a' + 1);
	}
	_reverse(res);
}

void outprintnum(char *p){
	int len = strlen(p) - 1;

	while (*p){
		putchar(*p++);
		if (len && !(len % 3)) putchar(',');
		--len;
	}
	putchar('\n');
}

int main(){
	char str[32], op[32];

	while (scanf("%s", str) == 1 && str[0] != '*'){
		if ('0' <= str[0] && str[0] <= '9'){
			getword(str, op);
			printf("%-22s", op);
			outprintnum(str);
		}else{
			getnum(str, op);
			printf("%-22s", str);
			outprintnum(op);
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
