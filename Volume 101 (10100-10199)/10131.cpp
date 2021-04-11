/* @JUDGE_ID: 19899RK 10131 C++ "By Anadan" */ 
// Is Bigger Smarter?
// Accepted (0.012 seconds with low memory spent)

#include <stdio.h>
#include <stdlib.h>

struct Elephant{
	int W, S, i;
}pt[1001];

int sort_function(const void *a, const void *b){
	return ((Elephant *)a)->W - ((Elephant *)b)->W;
}

int main(){
	int i, j, N = 0, res[1000], e[1000];

	while (scanf("%d%d\n", &pt[N].W, &pt[N].S) == 2) pt[N++].i = N + 1;
	qsort(pt, N, sizeof(Elephant), sort_function);

	for (i = 0; i < N; ++i){
		e[i] = i; res[i] = 1;
		for (j = i - 1; j >= 0; --j) if (pt[j].W < pt[i].W) break;
		for (; j >= 0; --j){
			if (pt[j].S > pt[i].S && res[i] < res[j] + 1){
				res[i] = res[j] + 1;
				e[i] = j;
			}
		}
	}

	for (j = i = 0; i < N; ++i) if (res[j] < res[i]) j = i;

	printf("%d\n", res[j]);
	for (N = res[j], i = 0; i < N; ++i){
		res[i] = j;
		j = e[j];
	}

	while (i--) printf("%d\n", pt[res[i]].i);

	return 0;
}
/* @END_OF_SOURCE_CODE */
