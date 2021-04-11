/* @JUDGE_ID: 19899RK 10252 C++ "By Anadan" */
// Common Permutation
// Accepted (0.010 seconds with low memory spent)

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int getcommon(char *s1, char *s2, char *res){
	char *p;
	int len = 0;

	for (; *s1; ++s1){
		if ((p = strchr(s2, *s1)) != NULL){
			++len;
			*res++ = *s1;
			*p = ' ';
		}
	}

	*res = 0;
	return len;
}

int sort_function(const void *a, const void *b){
	if (*((char *)a) < *((char *)b)) return -1;
	return 1;
}

int main(){
	int N;
	char s1[1001], s2[1001], res[1001];

	while (gets(s1) && gets(s2)){
		N = getcommon(s1, s2, res);
		qsort((void *)res, N, sizeof(char), sort_function);
		printf("%s\n", res);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
