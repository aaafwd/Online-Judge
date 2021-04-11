/* @JUDGE_ID: 19899RK 10260 C++ "By Anadan" */
// Soundex
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

int main(){
	char str[21], prev, *p;
	const char nosoundex[] = "AEIOUHWY", *q;
	const char mapfr[] = "BFPVCGJKQSXZDTLMNR";
	const char mapto[] = "111122222222334556";

	while (scanf("%s\n", str) == 1){
		prev = 0;
		for (p = str; *p; ++p){
			if (strchr(nosoundex, *p)){
				prev = -1;
			}else{
				q = strchr(mapfr, *p);
				if (prev == mapto[int(q - mapfr)]) continue;
				prev = mapto[int(q - mapfr)];
				putchar(prev);
			}
		}
		putchar('\n');
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
