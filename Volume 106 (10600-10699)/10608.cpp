/* @JUDGE_ID: 19899RK 10608 C++ "By Anadan" */
// Friends
// Accepted (0.172 seconds using as much as 740 kbytes)

#include <stdio.h>

int N, M;
int rank[30000], p[30000], tot[30000];

int getp(int i){
	if (p[i] != i) p[i] = getp(p[i]);
	return p[i];
}

void link(int i, int j){
	if (rank[i] > rank[j]){
		p[j] = i;
		tot[i] += tot[j];
	}else{
		p[i] = j;
		if (rank[i] == rank[j]) ++rank[j];
		tot[j] += tot[i];
	}
}

int main(){
	int set, i, j;

	scanf("%d", &set);
	while (set--){
		scanf("%d%d", &N, &M);
		for (i = 0; i < N; ++i){
			rank[i] = 0;
			p[i] = i;
			tot[i] = 1;
		}

		while (M--){
			scanf("%d%d", &i, &j); --i; --j;
			i = getp(i);
			j = getp(j);
			if (i != j) link(i, j);
		}

		for (i = j = 0; i < N; ++i) if (tot[i] > tot[j]) j = i;
		printf("%d\n", tot[j]);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
