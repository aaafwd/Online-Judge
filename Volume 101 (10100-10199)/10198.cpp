/* @JUDGE_ID: 19899RK 10198 C++ "By Anadan" */ 
// Counting
// Accepted (0.045 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

void _reverse(char *p){
	char *q = p + strlen(p) - 1;
	while (p < q) *p++ ^= *q-- ^= *p ^= *q;
}

void add(char *p, char *q){
	int rest = 0;

	while (*q){
		rest += *p - '0' + *q - '0';
		if (rest >= 10){
			*p = '0' + rest - 10;
			rest = 1;
		}else{
			*p = '0' + rest;
			rest = 0;
		}
		++p; ++q;
	}

	while (*p && rest){
		rest += *p - '0';
		if (rest >= 10){
			*p = '0' + rest - 10;
			rest = 1;
		}else{
			*p = '0' + rest;
			rest = 0;
		}
		++p;
	}

	if (rest){
		*p++ = '1';
		*p = 0;
	}
}

int main(){
	int i;
	char solves[1001][410];

	solves[0][0] = '1'; solves[1][0] = '2'; solves[2][0] = '5';
	solves[0][1] = solves[1][1] = solves[2][1] = 0;
	for (i = 3; i <= 1000; ++i){
		strcpy(solves[i], solves[i - 1]);
		add(solves[i], solves[i - 1]);
		add(solves[i], solves[i - 2]);
		add(solves[i], solves[i - 3]);
	}

	for (i = 1; i <= 1000; ++i) _reverse(solves[i]);
	while (scanf("%d\n", &i) == 1) printf("%s\n", solves[i]);

	return 0;
}
/* @END_OF_SOURCE_CODE */
