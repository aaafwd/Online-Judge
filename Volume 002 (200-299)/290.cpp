/* @JUDGE_ID: 19899RK 290 C++ "By Anadan" */
// Palindroms <--> smordnilaP
// Accepted  (0.440 seconds using as much as 388 kbytes)

#include <stdio.h>
#include <string.h>

int palindrome(char *s){
	char *p = s + strlen(s) - 1;
	while (p > s) if (*p-- != *s++) return 0;
	return 1;
}

int getsteps(char *s, int base){
	char str[80], buf[80], *p, *q;
	int res = 0, rest, num;

	strcpy(str, s);
	while (!palindrome(str)){
		q = buf;
		p = str + strlen(str) - 1;
		while (p >= str) *q++ = *p--;
		*q = 0;

		for (rest = 0, p = str, q = buf; *p; p++, q++){
			if (('0' <= *p) && (*p <= '9')) num = *p - '0';
			else num = *p - 'A' + 10;
			if (('0' <= *q) && (*q <= '9')) num += *q - '0';
			else num += *q - 'A' + 10;
			rest += num;
			*p = "0123456789ABCDE"[rest % base];
			rest /= base;
		}
		if (rest) *p++ = "0123456789ABCDE"[rest];
		*p = 0;

		res++;
	}

	return res;
}

int main(){
	int i, minbase;
	char str[80], *p;

	while(scanf("%s\n", str) > 0){
		for (p = str, minbase = 2; *p; p++){
			if (('0' <= *p) && (*p <= '9')){
				if (*p - '0' >= minbase) minbase = *p - '0' + 1;
			}else{
				if (*p - 'A' + 10 >= minbase) minbase = *p - 'A' + 11;
			}
		}
		if (minbase < 16) printf("%d", getsteps(str, 15));
		else printf("?");
		for (i = 14; i >= minbase; i--) printf(" %d", getsteps(str, i));
		while (--i > 0) printf(" ?");
		printf("\n");
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
