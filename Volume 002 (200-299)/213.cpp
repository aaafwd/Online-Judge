/* @JUDGE_ID: 19899RK 213 C++ "By Anadan" */
// Message Decoding
// Accepted (0.060 seconds using as much as 388 kbytes)

#include <stdio.h>
#include <ctype.h>

int getcode(int len){
	int res = 0, c;
	while (len--){
		while (!isdigit(c = getc(stdin)));
		res <<= 1;
		res += c - '0';
	}
	return res;
}

int main(){
	int len, max, c;
	char str[256], *p;

	while (scanf("\n"), gets(str)){
		while ((len = getcode(3)) != 0){
			max = (1 << len) - 1;
			p = str + max - len;
			while ((c = getcode(len)) != max){
				putchar(*(p + c));
			}
		}
		printf("\n");
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
