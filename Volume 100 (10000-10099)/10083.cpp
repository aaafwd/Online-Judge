/* @JUDGE_ID: 19899RK 10083 C++ "By Anadan" */ 
// Division
// Accepted (0.020 seconds with low memory spent)

#include <math.h>
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

void mul(char *p, long long N){
	long long rest = 0;

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

int isint(int t, int b, int a){
	int i;
	char x[150], y[150];

	if (floor(log10(t)) * double(b) * double(a - 1) >= 99) return 0;
	x[0] = y[0] = '1'; x[1] = y[1] = 0;

	while (--a){
		for (i = 0; i < b; ++i) mul(x, (long long)t);
		add(y, x);
		if (strlen(y) >= 100) return 0;
	}

	if (strlen(y) >= 100) return 0;
	_reverse(y);

	printf("%s\n", y);
	return 1;
}

int main(){
	int t, a, b;

	while (scanf("%d%d%d\n", &t, &a, &b) == 3){
		printf("(%d^%d-1)/(%d^%d-1) ", t, a, t, b);
		if (t < 2 || (a % b) || isint(t, b, a / b) == 0){
			printf("is not an integer with less than 100 digits.\n");
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
