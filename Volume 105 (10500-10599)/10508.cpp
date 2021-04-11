/* @JUDGE_ID: 19899RK 10508 C++ "By Anadan" */
// Word Morphing
// Accepted (0.061 seconds with low memory spent)

#include <stdio.h>
#include <stdlib.h>

int N, L;
char *words[2000];

int main(){
	int i, j, order[2000];
	char *p, *q;

	order[0] = 0;

	while (scanf("%d%d\n", &N, &L) == 2){
		for (i = 0; i < N; ++i){
			words[i] = (char *)malloc(L + 1);
			gets(words[i]);
		}

		order[N - 1] = 1;
		for (i = 2; i < N; ++i){
			p = words[i];
			q = words[1];
			for (j = 0; *p; ++p, ++q) if (*p != *q) ++j;
			order[N - 1 - j] = i;
		}

		for (i = 0; i < N; ++i) puts(words[order[i]]);
		for (i = 0; i < N; ++i) free(words[i]);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
