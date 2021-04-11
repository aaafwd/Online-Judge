/* @JUDGE_ID: 19899RK 10515 C++ "By Anadan" */ 
// Powers Et Al.
// Accepted (0.332 seconds using as much as 388 kbytes)

#include <stdio.h>
#include <string.h>

int main(){
	int res, i, rest;
	char s1[256], s2[256], *p;

	while (scanf("%s%s", s1, s2) == 2){
		if (strcmp(s1, "0") == 0 && strcmp(s2, "0") == 0) break;
		res = s1[strlen(s1) - 1] - '0';

		for (p = s2; *p == '0'; ++p);
		if (!*p) puts("1");
		else if (res == 0 || res == 1 || res == 5 || res == 6) printf("%d\n", res);
		else{
			rest = 0;
			while (*p) rest = (rest + rest + *p++ - '0') & 3;
			rest += 3;
			i = res;
			while (rest--){
				i = (i * res) % 10;
			}

			printf("%d\n", i);
		}

	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
