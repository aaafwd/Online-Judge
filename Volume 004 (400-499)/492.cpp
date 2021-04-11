/* @JUDGE_ID: 19899RK 492 C++ "By Anadan" */
// Pig-Latin
// Accepted (0.160 seconds using as much as 388 kbytes)

#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(){
	int c;
	char sav = 0, flag = 0;

	while ((c = getchar()) != EOF){
		if (flag == 0 && isalpha(c)){
			flag = 1;
			if (strchr("aeiouAEIOU", c)){
				putchar(c);
				sav = 0;
			}else sav = c;
			continue;
		}
		if (flag == 1 && isalpha(c) == 0){
			flag = 0;
			if (sav) putchar(sav);
			printf("ay");
		}
		putchar(c);
	}

	if (flag){
		if (sav) putchar(sav);
		printf("ay");
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
