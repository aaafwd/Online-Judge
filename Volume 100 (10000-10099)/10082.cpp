/* @JUDGE_ID: 19899RK 10082 C++ "By Anadan" */
// WERTYU
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

const char keys[] = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";

int main(){
	int c;
	char *p;

	while ((c = getchar()) != EOF){
		if ((p = strchr(keys, c)) != NULL) putchar(*(p - 1));
		else putchar(c);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
