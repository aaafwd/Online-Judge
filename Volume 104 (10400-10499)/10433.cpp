/* @JUDGE_ID: 19899RK 10433 C++ "By Anadan" */ 
// Automorphic Numbers
// Accepted (0.176 seconds using as much as 380 kbytes)

#include <stdio.h>
#include <string.h>
#define SZ 2001

char a5[SZ], a6[SZ];

void genautomorphic(){
	int i, j, rest, tmp;

	a5[0] = '5';
	for (rest = i = 0; i < SZ - 2; ++i){
		for (j = 0; j <= i; ++j){
			rest += (a5[j] - '0') * (a5[i - j] - '0');
		}
		rest /= 10;

		for (tmp = rest, j = 1; j <= i; ++j){
			tmp += (a5[j] - '0') * (a5[i - j + 1] - '0');
		}
		tmp %= 10;

		a5[i + 1] = '0' + tmp;
	}
	a5[i + 1] = 0;

	a6[0] = '6';
	for (rest = i = 0; i < SZ - 2; ++i){
		for (j = 0; j <= i; ++j){
			rest += (a6[j] - '0') * (a6[i - j] - '0');
		}
		rest /= 10;

		for (tmp = rest, j = 1; j <= i; ++j){
			tmp += (a6[j] - '0') * (a6[i - j + 1] - '0');
		}
		tmp %= 10;
		if (tmp == 0) tmp = 10;

		a6[i + 1] = '0' + 10 - tmp;
	}
	a6[i + 1] = 0;
}

int automorphic(char *s, int len){
	char *p;

	if (len == 1) return (*s == '0' || *s == '1' || *s == '5' || *s == '6');
	s += len - 1;

	if (*s == '5') p = a5;
	else if (*s == '6') p = a6;
	else return 0;

	while (len--) if (*s-- != *p++) return 0;
	return 1;
}

int main(){
	int len;
	char str[SZ];

	genautomorphic();
	while (scanf("%s\n", str) == 1){
		len = strlen(str);
		if (automorphic(str, len)) printf("Automorphic number of %d-digit.\n", len);
		else printf("Not an Automorphic number.\n");
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
