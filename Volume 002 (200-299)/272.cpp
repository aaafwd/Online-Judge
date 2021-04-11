/* @JUDGE_ID: 19899RK 272 C++ "By Anadan" */ 
// TeX Quotes
// Accepted (0.010 seconds with low memory spent)

#include <stdio.h>

int main(){
	int ch, quotes = 0;
	while ((ch = getc(stdin)) != EOF){
		if (ch == '"'){
			if (quotes & 1) printf("''");
			else printf("``");
			quotes ^= 1;
		}else putc(ch, stdout);
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */
