/* @JUDGE_ID: 19899RK 10222 C++ "By Anadan" */
// Decode the Mad man
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>
#include <ctype.h>
#include <string.h>

const char keys[] = "qwertyuiop[]asdfghjkl;'zxcvbnm,./";

int main(){
	int c;
	char *p;

	while ((c = getchar()) != EOF){
		c = tolower(c);
		if ((p = strchr(keys, c)) != NULL) putchar(*(p - 2));
		else putchar(c);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
