/* @JUDGE_ID: 19899RK 10527 C++ "By Anadan" */ 
// Persistent Numbers
// Accepted (0.199 seconds using as much as 396 kbytes)

#include <stdio.h>
#include <string.h>

char str[1100], res[1100];

int divisible(int x){
	int rest = 0;
	char *p, *r = res;

	for (p = str; *p == '0'; ++p);
	if (!*p) return 0;

	while (*p){
		rest = rest * 10 + *p++ - '0';
		*r++ = rest / x + '0';
		rest %= x;
	}

	if (rest) return 0;

	*r = 0;
	strcpy(str, res);
	return 1;
}

int main(){
	int powers[10], i;
	char *p;

	while (scanf("%s", str) == 1){
		for (p = str; *p == '0'; ++p);
		if (*p == '-') break;
		if (!*p) --p;
		if (!p[1]){
			printf("1%c\n", *p);
			continue;
		}

		for (i = 0; i < 10; ++i) powers[i] = 0;
		for (i = 9; i > 1; --i){
			while (divisible(i)) ++powers[i];
		}

		for (p = str; *p == '0'; ++p);
		if (strcmp(p, "1")) puts("There is no such number.");
		else{
			for (i = 1; i < 10; ++i){
				while (powers[i]--) putchar('0' + i);
			}

			putchar('\n');
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
