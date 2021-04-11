/* @JUDGE_ID: 19899RK 490 C++ "By Anadan" */
// Rotating Sentences
// Accepted (0.010 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

int main(){
	int index, lens[100], maxlen, i, j;
	char str[101][101], *p;

	maxlen = index = 0;
	while (gets(str[index])){
		lens[index] = strlen(str[index]);
		if (lens[index] > maxlen) maxlen = lens[index];
		++index;
	}

	for (i = 0; i < index; i++){
		for (p=str[i]+lens[i]; lens[i]<maxlen; lens[i]++) *p++ = ' ';
		*p = 0;
	}

	for (i = 0; i < maxlen; i++){
		for (j = index-1; j >= 0; j--) putchar(str[j][i]);
		putchar('\n');
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
