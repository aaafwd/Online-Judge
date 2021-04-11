/* @JUDGE_ID: 19899RK 10295 C++ "By Anadan" */
// Hay Points
// Accepted (0.010 seconds with low memory spent)

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Dict{
	char word[17];
	long value;
}pt[1000];
int m;

int sort_function(const void *a, const void *b){
	return strcmp(((Dict *)a)->word, ((Dict *)b)->word);
}

long getsum(char *str){
	int i = 0, j = m - 1, k;

	while (j > i + 1){
		k = (i + j) >> 1;
		if (strcmp(pt[k].word, str) > 0) j = k;
		else i = k;
	}

	if (!strcmp(pt[i].word, str)) return pt[i].value;
	if (i != j && strcmp(pt[j].word, str) == 0) return pt[j].value;
	return 0;
}

int main(){
	char str[128];
	int n, i;
	long sum;

	scanf("%d%d\n", &m, &n);
	for (i = 0; i < m; ++i) scanf("%s %ld\n", pt[i].word, &pt[i].value);
	qsort((void *)pt, m, sizeof(pt[0]), sort_function);

	for (i = 0; i < n; ++i){
		sum = 0L;
		while (scanf("%s", str) && strcmp(str, ".")) sum += getsum(str);
		printf("%ld\n", sum);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
