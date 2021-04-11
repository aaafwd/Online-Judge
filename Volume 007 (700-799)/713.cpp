/* @JUDGE_ID: 19899RK 713 C++ "By Anadan" */
// Adding Reversed Numbers
// Accepted (0.002 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

char s1[256], s2[256], res[256];

void add(char * p, char * q){
	int rest = 0;
	char * r = res;

	while (*p && *q){
		rest += *p++ - '0' + *q++ - '0';
		if (rest > 9){
			*r++ = rest - 10 + '0';
			rest = 1;
		}else{
			*r++ = rest + '0';
			rest = 0;
		}
	}

	while (*p){
		rest += *p++ - '0';
		if (rest > 9){
			*r++ = rest - 10 + '0';
			rest = 1;
		}else{
			*r++ = rest + '0';
			rest = 0;
		}
	}

	while (*q){
		rest += *q++ - '0';
		if (rest > 9){
			*r++ = rest - 10 + '0';
			rest = 1;
		}else{
			*r++ = rest + '0';
			rest = 0;
		}
	}

	if (rest) *r++ = '1';
	*r = 0;
}

int main(){
	int set;
	char *p;

	scanf("%d", &set);
	while(set--){
		scanf("%s%s", &s1, &s2);
		add(s1, s2);
		for (p = res; *p == '0'; ++p);
		if (p) puts(p); else puts("0");
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
