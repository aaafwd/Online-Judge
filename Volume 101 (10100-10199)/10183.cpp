/* @JUDGE_ID: 19899RK 10183 C++ "By Anadan" */ 
// How many Fibs?
// Accepted (0.006 seconds using as much as 432 kbytes)

#include <stdio.h>
#include <string.h>
#define SZ 480

int lens[SZ];
char fibs[SZ][110];

void _reverse(char *p){
	char *q = p + strlen(p) - 1;
	while (p < q) *p++ ^= *q-- ^= *p ^= *q;
}

int getindex(char *s){
	int i = 0, j = SZ - 1, k, len = strlen(s), tmp;

	while (i < j - 1){
		k = (i + j) >> 1;
		if (len > lens[k]) i = k;
		else if (len < lens[k]) j = k;
		else{
			tmp = strcmp(s, fibs[k]);
			if (tmp == 0) return k;
			if (tmp > 0) i = k; else j = k;
		}
	}

	if (strcmp(s, fibs[j]) == 0) return j;
	return i;
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
	int i, j;
	char a[110], b[110];

	fibs[0][0] = '1'; fibs[1][0] = '2'; fibs[0][1] = fibs[1][1] = 0;
	for (i = 2; i < SZ; ++i){
		strcpy(fibs[i], fibs[i - 1]);
		add(fibs[i], fibs[i - 2]);
	}

	for (i = 0; i < SZ; ++i){
		_reverse(fibs[i]);
		lens[i] = strlen(fibs[i]);
	}

	while (scanf("%s%s\n", a, b) == 2 && b[0] != '0'){
		if (a[0] == '0') a[0] = '1';
		i = getindex(a);
		j = getindex(b) - i;
		if (!strcmp(a, fibs[i])) ++j;
		printf("%d\n", j);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
