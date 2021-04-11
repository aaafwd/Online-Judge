/* @JUDGE_ID: 19899RK 10126 C++ "By Anadan" */ 
// Zipf's Law
// Accepted (0.150 seconds using as much as 588 kbytes)

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#define SZ 10000

inline char *_strdup(char *s){
	return strcpy((char *)malloc(strlen(s) + 1), s);
}

int sort_function(const void *a, const void *b){
	return strcmp(*(char **)a, *(char **)b);
}

int main(){
	int N, D, i, j;
	char str[256], *dict[SZ], *p, out, first = 0;

	while (scanf("%d\n", &N) == 1){
		if (first) putchar('\n'); else first = 1;
		D = 0;
		while ((i = getchar()) != EOF){
			if (isalpha(i)){
				p = str; *p++ = i;
				while ((i = getchar()) != EOF && isalpha(i)) *p++ = i;
				*p = 0;
				if (!strcmp(str, "EndOfText")) break;
				for (p = str; *p; ++p) *p = tolower(*p);
				dict[D++] = _strdup(str);
			}
		}

		out = 0;
		qsort(dict, D, sizeof(char *), sort_function);
		for (i = 0; i < D; ++i){
			for (j = i + 1; j < D && strcmp(dict[i], dict[j]) == 0; ++j);
			if (j - i == N){
				printf("%s\n", dict[i]);
				out = 1;
			}

			i = j - 1;
		}

		while (D--) free(dict[D]);
		if (!out) printf("There is no such word.\n");
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
