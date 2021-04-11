/* @JUDGE_ID: 19899RK 101 C++ "By Anadan" */
// The Blocks Problem
// Accepted (0.030 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

struct Box{
	int stacked;
	int stack[25];
}pt[25];
int N;

void empty_stack(int k, int l){
	int i;
	for (i = l + 1; i < pt[k].stacked; ++i) pt[pt[k].stack[i]].stacked = 1;
	pt[k].stacked = l + 1;
}

void find(int &k, int &l, int i){
	for (k = 0; k < N; ++k){
		for (l = 0; l < pt[k].stacked; ++l)
			if (pt[k].stack[l] == i) break;
		if (l < pt[k].stacked) break;
	}
}

int main(){
	int i, j, k1, l1, k2, l2;
	char cop[5], how[5];

	scanf("%d\n", &N);
	for (i = 0; i < N; ++i){
		pt[i].stacked = 1;
		pt[i].stack[0] = i;
	}
	while (scanf("%s", cop) == 1 && strcmp(cop, "quit")){
		scanf("%d %s %d\n", &i, how, &j);
		if (i == j) continue;
		find(k1, l1, i);
		find(k2, l2, j);
		if (k1 == k2) continue;

		if (cop[0] == 'm'){
			empty_stack(k1, l1);
			if (how[1] == 'n') empty_stack(k2, l2);
			--pt[k1].stacked;
			pt[k2].stack[pt[k2].stacked++] = pt[k1].stack[l1];
		}else if (cop[0] == 'p'){
			if (how[1] == 'n') empty_stack(k2, l2);
			for (i = l1; i < pt[k1].stacked; ++i){
				pt[k2].stack[pt[k2].stacked++] = pt[k1].stack[i];
			}
			pt[k1].stacked = l1;
		}else return 1;
	}

	for (i = 0; i < N; ++i){
		printf("%d:", i);
		for (j = 0; j < pt[i].stacked; ++j) printf(" %d", pt[i].stack[j]);
		printf("\n");
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
