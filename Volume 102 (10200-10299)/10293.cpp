/* @JUDGE_ID: 19899RK 10293 C++ "By Anadan" */ 
// Word Length and Frequency
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

int getlen(char *p){
	int res = 0;

	while (*p){
		if (*p != '\'' && *p != '-') ++res;
		++p;
	}

	return res;
}

int main(){
	int len[31], i, hyphen;
	char str[81], *p, endflag;

	while (1){
		hyphen = 0;
		for (i = 0; i < 31; ++i) len[i] = 0;

		endflag = 1;
		while (gets(str)){
			endflag = 0;
			if (str[0] == '#') break;

			p = strtok(str, " ?!,.");
			while (p){
				i = hyphen + getlen(p);
				if (p[strlen(p) - 1] == '-'){
					hyphen = i;
					break;
				}else hyphen = 0;
				++len[i];

				p = strtok(NULL, " ?!,.");
			}
		}

		if (endflag) break;
		for (hyphen = i = 0; i < 31; ++i) if (len[i]){
			printf("%d %d\n", i, len[i]);
			hyphen = 1;
		}

		if (hyphen) putchar('\n');
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
