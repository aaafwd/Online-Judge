/* @JUDGE_ID: 19899RK 748 C++ "By Anadan" */ 
// Exponentiation
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>
#include <string.h>
#include <assert.h>

void mult(char *s, long n){
	long rest = 0L;

	while (*s){
		rest += n * (*s - '0');
		*s++ = (rest % 10) + '0';
		rest /= 10;
	}
	while (rest){
		*s++ = (rest % 10) + '0';
		rest /= 10;
	}
	*s = 0;
}

void _strrev(char *p){
	char *q = p + strlen(p) - 1;
	while (p < q) { *p ^= *q; *q ^= *p; *p++ ^= *q--; }
}

int main(){
	int n, point;
	char str[7], res[256], *p, *q;
	long num;

	while (scanf("%s %d\n", str, &n) == 2){
		assert(strlen(str) == 6);
		for (num = 0L, p = str; *p; p++){
			if (*p == '.') point = 5 - int(p - str);
			else num = num * 10 + *p - '0';
		}

		point *= n;
		strcpy(res, "1");
		while (n--) mult(res, num);
		_strrev(res);
		n = strlen(res);

		if (point >= n){
			point -= n;
			putchar('.');
			while (point--) putchar('0');
			for (p = res + n - 1; *p == '0'; --p);
			*(p + 1) = 0;
			printf("%s\n", res);
		}else{
			p = res;
			while (point++ < n) putchar(*p++);
			putchar('.');
			for (q = p + strlen(p) - 1; *q == '0' && q >= p; --q);
			*(q + 1) = 0;
			if (q < p) printf("0\n");
			else printf("%s\n", p);
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
