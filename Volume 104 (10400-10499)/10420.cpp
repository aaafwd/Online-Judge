/* @JUDGE_ID: 19899RK 10420 C++ "By Anadan" */ 
// List of Conquests
// Accepted (0.023 seconds with low memory spent)

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct List{
	char country[75], name[75];
}pt[2000];

int sort_function(const void *a, const void *b){
	int i = strcmp(((List *)a)->country, ((List *)b)->country);
	if (i) return i;
	return strcmp(((List *)a)->name, ((List *)b)->name);
}

int main(){
	int N, i, off;
	char str[81], *p;

	scanf("%d\n", &N);
	for (i = 0; i < N; ++i){
		gets(str);
		sscanf(str, "%s%n", pt[i].country, &off);
		for (p = str + off; *p == ' '; ++p);
		strcpy(pt[i].name, p);
	}

	qsort(pt, N, sizeof(List), sort_function);
	for (i = 0; i < N; ++i){
		off = 1;
		for (++i; i < N; ++i){
			if (strcmp(pt[i].country, pt[i - 1].country)) break;
			if (strcmp(pt[i].name, pt[i - 1].name)) ++off;
		}
		printf("%s %d\n", pt[--i].country, off);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
