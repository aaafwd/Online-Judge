/* @JUDGE_ID: 19899RK 642 C++ "By Anadan" */
// Word Amalgamation
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int N;
char dict[101][7];

int sort_function(const void *a, const void *b){
	return (strcmp((char *)a, (char *)b));
}

int anagrams(const char *s1, const char *s2){
	char *p, str[7];
	strcpy(str, s1);

	for(; *s2; s2++){
		if ((p = strchr(str, *s2)) == NULL) return 0;
		*p = ' ';
	}
	for (p = str; *p; p++) if (*p != ' ') return 0;
	return 1;
}

int main(){
	int i;
	char str[7], solved;

	for (N = 0; N < 101; N++){
		scanf("%s\n", dict[N]);
		if (dict[N][0] == 'X') break;
	}

	qsort((void *)dict, N, sizeof(dict[0]), sort_function);
	while (scanf("%s\n", str) > 0){
		if (str[0] == 'X') break;
		solved = 0;
		for (i = 0; i < N; i++){
			if (anagrams(str, dict[i])){
				printf("%s\n", dict[i]);
				solved = 1;
			}
		}
		if (!solved) printf("NOT A VALID WORD\n");
		printf("******\n");
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
