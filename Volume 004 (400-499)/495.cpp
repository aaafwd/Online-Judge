/* @JUDGE_ID: 19899RK 495 C++ "By Anadan" */
// Fibonacci Freeze
// Accepted (0.281 seconds using as much as 3004 kbytes)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 5001

void add(char *src, char *dst){
	char rest = 0;

	while (*src){
		*dst += rest + *src++ - '0';
		if (*dst > '9'){
			*dst -= 10;
			rest = 1;
		}else rest = 0;
		++dst;
	}

	while (rest && *dst){
		++(*dst);
		if (*dst > '9'){
			*dst -= 10;
			rest = 1;
		}else rest = 0;
		++dst;
	}

	if (rest){
		*dst++ = '1';
		*dst = 0;
	}
}

void _strrev(char *p){
	char *q = p + strlen(p) - 1;
	while (p < q) *p++ ^= *q-- ^= *p ^= *q;
}

int main(){
	int i;
	char *solves[MAX], tmp[2000];

	solves[0] = (char *)malloc(2);
	solves[1] = (char *)malloc(2);
	solves[0][0] = '0';
	solves[1][0] = '1';
	solves[0][1] = solves[1][1] = 0;

	for (i = 2; i < MAX; i++){
		strcpy(tmp, solves[i - 1]);
		add(solves[i - 2], tmp);
		solves[i] = strcpy((char *)malloc(strlen(tmp) + 1), tmp);
	}

	for (i = 2; i < MAX; i++) _strrev(solves[i]);

	while (scanf("%d", &i) > 0){
		printf("The Fibonacci number for %d is %s\n", i, solves[i]);
	}

	for (i = 2; i < MAX; i++) free(solves[i]);

	return 0;
}
/* @END_OF_SOURCE_CODE */
