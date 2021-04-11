/* @JUDGE_ID: 19899RK 10494 C++ "By Anadan" */ 
// If We Were a Child Again
// Accepted (0.002 seconds with low memory spent)

#include <stdio.h>
#define SZ 5000

char num[SZ];

void doop(int d, char *op){
	char *p = num;
	long long rest = 0;

	while (*p){
		rest = rest * 10 + (*p - '0');
		*p++ = (rest / d) + '0';
		rest %= d;
	}

	if (*op == '%') printf("%lld\n", rest);
	else{
		*p = 0;
		for (p = num; *p == '0'; ++p);
		if (*p) puts(p); else puts("0");
	}
}

int main(){
	int d;
	char op[2];

	while (scanf("%s%s%d", num, op, &d) == 3){
		doop(d, op);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
