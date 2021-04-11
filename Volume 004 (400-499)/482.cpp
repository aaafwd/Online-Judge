/* @JUDGE_ID: 19899RK 482 C++ "By Anadan" */
// Permutation Arrays
// Accepted (0.010 seconds with low memory spent)

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#define SZ 100000

struct PArray{
	char *s;
	int n;
}pt[SZ];

int sort_function(const void *a, const void *b){
	if (((PArray *)a)->n < ((PArray *)b)->n) return -1;
	return 1;
}

int main(){
	int set, i, c, N;
	char str[1024], *p;

	scanf("%d\n\n", &set);
	while (set--){
		N = 0;
		while ((i = getchar()) != '\n'){
			if (!isdigit(i)) continue;
			i -= '0';
			while (isdigit(c = getchar())) { i *= 10; i += c; }
			pt[N++].n = i;
			if (c == '\n') break;
		}

		N = 0;
		while ((c = getchar()) != '\n'){
			if (isspace(c)) continue;
			i = 2; p = str; *p++ = c;
			while (isspace(c = getchar()) == 0) *p++ = c, ++i;
			*p = 0;
			pt[N++].s = strcpy((char *)malloc(i), str);
			if (c == '\n') break;
		}

		qsort(pt, N, sizeof(PArray), sort_function);
		for (i = 0; i < N; ++i){
			printf("%s\n", pt[i].s);
			free(pt[i].s);
		}

		if (set) putchar('\n'), scanf("\n");
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
