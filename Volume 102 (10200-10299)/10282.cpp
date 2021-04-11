/* @JUDGE_ID: 19899RK 10282 C++ "By Anadan" */
// Babelfish
// Accepted (1.178 seconds using as much as 4692 kbytes)

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXN 100000

int N;
struct Dict{
	char word[11], trans[11];
}dict[MAXN];

int sort_function(const void *a, const void *b){
	return strcmp(((Dict *)a)->trans, ((Dict *)b)->trans);
}

int main(){
	char str[100];
	Dict tmp, *p;

	N = 0;
	while (gets(str)){
		if (str[0] == 0) break;
		sscanf(str, "%s %s", dict[N].word, dict[N].trans);
		++N;
	}
	qsort(dict, N, sizeof(Dict), sort_function);

	while (scanf("%s\n", tmp.trans) > 0){
		p = (Dict *)bsearch(&tmp, dict, N, sizeof(Dict), sort_function);
		if (p) printf("%s\n", p->word); else printf("eh\n");
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
