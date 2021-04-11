/* @JUDGE_ID: 19899RK 612 C++ "By Anadan" */
// DNA Sorting
// Accepted (0.010 seconds with low memory spent)

#include <stdio.h>
#include <stdlib.h>

struct DNA{
	char str[51];
	int measure;
	int i;
}pt[100];

void setMeasure(int n){
	int res = 0;
	char *p, *q;

	for (p = pt[n].str; *p; p++) for (q = p + 1; *q; q++)
		if (*p > *q) res++;

	pt[n].measure = res;
}

int sort_function(const void *a, const void *b){
	DNA *p1 = (DNA *)a, *p2 = (DNA *)b;
	if (p1->measure > p2->measure) return 1;
	if ((p1->measure == p2->measure) && (p1->i > p2->i)) return 1;
	return -1;
}

int main(){
	int i, m;
	long N;
	scanf("%ld", &N);

	while (N--){
		scanf("%*d%d\n", &m);
		for (i = 0; i < m; i++){
			scanf("%s\n", pt[i].str);
			pt[i].i = i;
			setMeasure(i);
		}
		qsort((void *)pt, m, sizeof(DNA), sort_function);
		for (i = 0; i < m; i++){
			printf("%s\n", pt[i].str);
		}
		if (N) printf("\n");
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
