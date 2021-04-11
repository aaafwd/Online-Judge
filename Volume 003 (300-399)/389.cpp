/* @JUDGE_ID: 19899RK 389 C++ "By Anadan" */
// Basically Speaking
// Accepted (0.390 seconds using as much as 392 kbytes)

#include <stdio.h>

typedef unsigned long dword;

dword getnum(char *str, int base){
	char *p, ch;
	dword res = 0L;

	for (p = str; *p; p++){
		ch = *p;
		if (('0' <= ch) && (ch <= '9')) ch -= '0';
		else ch -= 'A' - 10;
		res = res * base + ch;
	}
	return res;
}

int convertnum(char *str, int len, dword num, int base){
	char *p = str;

	if (num == 0L) *p++ = '0';
	else while (num && len--){
		*p++ = "0123456789ABCDEF"[num % base];
		num /= base;
	}
	if (num) return 1;
	*p-- = 0;

	while (str < p){
		*p ^= *str; *str ^= *p; *p-- ^= *str++;
	}

	return 0;
}

int main(){
	int b1, b2;
	dword num;
	char str[8];

	while (scanf("%s %d %d\n", str, &b1, &b2) == 3){
		num = getnum(str, b1);
		if (convertnum(str, 7, num, b2)) printf("  ERROR\n");
		else printf("%7s\n", str);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
