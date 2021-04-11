/* @JUDGE_ID: 19899RK 10144 C++ "By Anadan" */ 
// Expression
// Accepted (0.004 seconds with low memory spent)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

inline char *_strdup(char *s){
	return strcpy((char *)malloc(strlen(s) + 1), s);
}

int main(){
	int set, i;
	char str[5100], *solves[100];

	solves[0] = _strdup("((A0|B0)|(A0|B0))");
	for (i = 1; i < 100; ++i){
		sprintf(str, "((A%d|B%d)|(%s|((A%d|A%d)|(B%d|B%d))))", i, i, solves[i - 1], i, i, i, i);
		solves[i] = _strdup(str);
	}

	scanf("%d\n\n", &set);
	while (set--){
		scanf("%d\n", &i);
		printf("%s\n", solves[i - 1]);
		if (set) putchar('\n');
	}

	for (i = 0; i < 100; ++i) free(solves[i]);
	return 0;
}
/* @END_OF_SOURCE_CODE */
