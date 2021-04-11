/* @JUDGE_ID: 19899RK 536 C++ "By Anadan" */
// Tree Recovery
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

char *getpostord(char *preord, char *inord, char *postord){
	char root = *preord, *p = strchr(inord, root); *p = 0;
	if (p != inord) postord = getpostord(preord + 1, inord, postord);
	preord += int(p - inord) + 1;
	if (*(p + 1)) postord = getpostord(preord, p + 1, postord);
	*postord++ = root;
	return postord;
}

int main(){
	char preord[27], inord[27], postord[27];

	while (scanf("%s %s\n", preord, inord) == 2){
		*getpostord(preord, inord, postord) = 0;
		printf("%s\n", postord);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
