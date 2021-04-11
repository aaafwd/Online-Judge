/* @JUDGE_ID: 19899RK 10334 C++ "By Anadan" */
// Ray Through Glasses
// Accepted (0.010 seconds with low memory spent)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *add(char *op1, char *op2){
	int len = 0;
	char res[10000], rest = 0;

	while (*op1){
		rest += *op1 + *op2 - '0';
		if (rest > '9'){
			res[len++] = rest - 10;
			rest = 1;
		}else{
			res[len++] = rest;
			rest = 0;
		}
		++op1; ++op2;
	}

	while (*op2){
		rest += *op2;
		if (rest > '9'){
			res[len++] = rest - 10;
			rest = 1;
		}else{
			res[len++] = rest;
			rest = 0;
		}
		++op2;
	}

	if (rest) res[len++] = '1';
	res[len++] = 0;

	return strcpy((char *)malloc(len), res);
}

void _strrev(char *p){
	char *q = p + strlen(p) - 1;
	while (p < q) *p++ ^= *q-- ^= *p ^= *q;
}

int main(){
	int i;
	char *solve[1001];

	strcpy(solve[0] = (char *)malloc(2), "1");
	strcpy(solve[1] = (char *)malloc(2), "2");

	for (i = 2; i <= 1000; ++i){
		solve[i] = add(solve[i-2], solve[i-1]);
	}

	for (i = 2; i <= 1000; ++i) _strrev(solve[i]);

	while (scanf("%d\n", &i) == 1){
		printf("%s\n", solve[i]);
	}

	for (i = 0; i <= 1000; ++i) free(solve[i]);

	return 0;
}
/* @END_OF_SOURCE_CODE */
