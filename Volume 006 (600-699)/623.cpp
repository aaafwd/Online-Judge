/* @JUDGE_ID: 19899RK 623 C++ "By Anadan" */
// 500!
// Accepted (0.111 seconds using as much as 1580 kbytes)

#include <stdio.h>
#include <string.h>

char * res[1001], buf[8192];

void _reverse(char *p){
	char *q = p + strlen(p) - 1;
	while (p < q) *p++ ^= *q-- ^= *p ^= *q;
}

void mul(char * s, int x){
	int rest = 0;
	char * p = buf;

	while (*s){
		rest += (*s++ - '0') * x;
		*p++ = rest % 10 + '0';
		rest /= 10;
	}

	while (rest){
		*p++ = rest % 10 + '0';
		rest /= 10;
	}
	*p = 0;

	res[x] = new char[int(p - buf + 1)];
	strcpy(res[x], buf);
}

int main(){
	int i;

	res[0] = res[1] = "1";
	for (i = 2; i <= 1000; ++i) mul(res[i - 1], i);
	for (i = 2; i <= 1000; ++i) _reverse(res[i]);
	while (scanf("%d", &i) == 1) printf("%d!\n%s\n", i, res[i]);
	return 0;
}
/* @END_OF_SOURCE_CODE */
