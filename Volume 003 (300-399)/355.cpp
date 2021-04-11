/* @JUDGE_ID: 19899RK 355 C++ "By Anadan" */
// The Bases Are Loaded
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>

typedef unsigned long long dword;

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
	int b1, b2, minbase;
	dword num;
	char str[80], *p;

	while (scanf("%d %d %s\n", &b1, &b2, str) == 3){
		for (minbase = 2, p = str; *p; p++){
			if (('0' <= *p) && (*p <= '9')){
				if (*p - '0' >= minbase) minbase = *p - '0' + 1;
			}else{
				if (*p - 'A' + 10 >= minbase) minbase = *p - 'A' + 11;
			}
		}
		if (b1 < minbase){
			printf("%s is an illegal base %d number\n", str, b1);
		}else{
			printf("%s base %d = ", str, b1);
			num = getnum(str, b1);
			convertnum(str, 79, num, b2);
			printf("%s base %d\n", str, b2);
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
