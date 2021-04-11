/* @JUDGE_ID: 19899RK 380 C++ "By Anadan" */ 
// Call Forwarding
// Accepted (0.002 seconds with low memory spent)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Forwards{
	int src, dst, t, d;
}pt[100];
int N, mask[10000], sp;

int sort_function(const void *a, const void *b){
	if (((Forwards *)a)->t < ((Forwards *)b)->t) return -1;
	return 1;
}

int get_forward(int t, int src){
	int i;

	mask[src] = sp;
	while (1){
		for (i = 0; i < N && pt[i].t <= t; ++i){
			if (pt[i].src != src || pt[i].t + pt[i].d < t) continue;
			src = pt[i].dst;
			if (mask[src] == sp) return 9999;
			mask[src] = sp;
			i = -1;
			break;
		}

		if (i != -1) break;
	}

	return src;
}

int main(){
	int set, syst = 0, i, j;

	puts("CALL FORWARDING OUTPUT");
	scanf("%d", &set);
	while (set--){
		N = 0;
		sp = 1;
		memset(mask, 0, sizeof(mask));
		while (scanf("%d", &i) == 1 && i){
			pt[N].src = i;
			scanf("%d%d%d", &pt[N].t, &pt[N].d, &pt[N].dst);
			++N;
		}

		printf("SYSTEM %d\n", ++syst);
		qsort(pt, N, sizeof(Forwards), sort_function);
		while (scanf("%d", &i) == 1 && i != 9000){
			scanf("%d", &j);
			printf("AT %.4d CALL TO %.4d RINGS %.4d\n", i, j, get_forward(i, j));
			++sp;
		}
	}
	puts("END OF OUTPUT");

	return 0;
}
/* @END_OF_SOURCE_CODE */
