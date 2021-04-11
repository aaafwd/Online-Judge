/* @JUDGE_ID: 19899RK 394 C++ "By Anadan" */
// Mapmaker
// Accepted (0.002 seconds with low memory spent)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int N;
struct Array{
	char name[11];
	int D, C0, C[10];
}pt[100];

int sort_function(const void *a, const void *b){
	return strcmp(((Array *)a)->name, ((Array *)b)->name);
}

int main(){
	int R, i, j, res;
	int B, L[10], U[10];
	Array arr, *p;

	scanf("%d%d\n", &N, &R);
	for (i = 0; i < N; ++i){
		scanf("%s %d %d %d", pt[i].name, &B, &j, &pt[i].D);
		pt[i].C[pt[i].D - 1] = j;
		for (j = 0; j < pt[i].D; ++j) scanf("%d%d", L + j, U + j);
		for (j = pt[i].D - 2; j >= 0; --j) pt[i].C[j] = pt[i].C[j + 1] * (U[j + 1] - L[j + 1] + 1);
		for (j = 0; j < pt[i].D; ++j) B -= pt[i].C[j] * L[j];
		pt[i].C0 = B;
	}

	qsort(pt, N, sizeof(Array), sort_function);

	for (i = 0; i < R; ++i){
		scanf("%s%d", arr.name, &B);
		p = (Array *)bsearch(&arr, pt, N, sizeof(Array), sort_function);
		printf("%s[%d", p->name, B);
		res = p->C0 + B * p->C[0];
		for (j = 1; j < p->D; ++j){
			scanf("%d", &B);
			res += B * p->C[j];
			printf(", %d", B);
		}

		printf("] = %d\n", res);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
