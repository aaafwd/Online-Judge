/* @JUDGE_ID: 19899RK 10497 C++ "By Anadan" */ 
// Sweet Child Makes Trouble
// Accepted (0.098 seconds using as much as 948 kbytes)

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *solves[801];

void _reverse(char *p){
	char *q = p + strlen(p) - 1;
	while (p < q) *p++ ^= *q-- ^= *p ^= *q;
}

void add(char *p, char *q){
	int rest = 0;

	while (*p && *q){
		rest += (*p - '0') + (*q - '0');
		if (rest > 9){
			*p = '0' + rest - 10;
			rest = 1;
		}else{
			*p = '0' + rest;
			rest = 0;
		}

		++p; ++q;
	}

	while (*q){
		rest += *q - '0';
		if (rest > 9){
			*p = '0' + rest - 10;
			rest = 1;
		}else{
			*p = '0' + rest;
			rest = 0;
		}

		++p; ++q;
	}

	while (*p){
		rest += *p - '0';
		if (rest > 9){
			*p = '0' + rest - 10;
			rest = 1;
		}else{
			*p = '0' + rest;
			rest = 0;
		}

		++p;
	}

	if (rest) *p++ = '1';
	*p = 0;
}

void mul(char *p, int d){
	int rest = 0;

	while (*p){
		rest += d * (*p - '0');
		*p++ = '0' + (rest % 10);
		rest /= 10;
	}

	while (rest){
		*p++ = '0' + (rest % 10);
		rest /= 10;
	}

	*p = 0;
}

inline char *_strdup(char *p){
	return strcpy((char *)malloc(strlen(p) + 1), p);
}

int main(){
	int i;
	char tmp[2000];

	solves[1] = _strdup("0");
	solves[2] = _strdup("1");
	strcpy(tmp, "1");

	for (i = 3; i <= 800; ++i){
		add(tmp, solves[i - 2]);
		mul(tmp, i - 1);
		solves[i] = _strdup(tmp);
	}

	for (i = 1; i <= 800; ++i) _reverse(solves[i]);
	while (scanf("%d", &i) == 1 && i > 0) puts(solves[i]);
	for (i = 1; i <= 800; ++i) free(solves[i]);

	return 0;
}
/* @END_OF_SOURCE_CODE */
