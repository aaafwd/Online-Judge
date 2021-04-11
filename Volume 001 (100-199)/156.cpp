/* @JUDGE_ID: 19899RK 156 C++ "By Anadan" */
// Ananagrams
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int N;
struct Words{
	char str[21];
	char letters[26];
	char ananagram;
}pt[1001];

int sort_function(const void *a, const void *b){
	return strcmp(((Words *)a)->str, ((Words *)b)->str);
}

int main(){
	int i;
	char *p, c;

	N = 0;
	while (scanf("%s", pt[N].str) == 1 && pt[N].str[0] != '#'){
		pt[N].ananagram = 1;
		memset(pt[N].letters, 0, 26);
		for (p = pt[N].str; *p; ++p){
			if ('a' <= *p && *p <= 'z') c = *p - 'a';
			else c = *p - 'A';
			++pt[N].letters[c];
		}

		for (i = 0; i < N; ++i){
			if (memcmp(pt[i].letters, pt[N].letters, 26) == 0){
				pt[i].ananagram = pt[N].ananagram = 0;
				break;
			}
		}

		++N;
	}

	qsort(pt, N, sizeof(Words), sort_function);
	for (i = 0; i < N; ++i){
		if (pt[i].ananagram) printf("%s\n", pt[i].str);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
