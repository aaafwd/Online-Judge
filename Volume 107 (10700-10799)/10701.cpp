/* @JUDGE_ID: 19899RK 10701 C++ "By Anadan" */
// Pre, in and post
// Accepted (0.016 seconds with low memory spent)

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
	int set;
	char preord[64], inord[64], postord[64];

	scanf("%d", &set);
	while (set--){
		scanf("%*d%s%s", preord, inord);
		*getpostord(preord, inord, postord) = 0;
		printf("%s\n", postord);
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */
