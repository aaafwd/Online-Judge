/* @JUDGE_ID: 19899RK 10596 C++ "By Anadan" */
// Morning Walk
// Accepted (0.701 seconds using as much as 396 kbytes)

#include <stdio.h>
#include <string.h>

int deg[200], rank[200], p[200];

int getp(int x){
	if (p[x] != x) p[x] = getp(p[x]);
	return p[x];
}

void link(int i, int j){
	i = getp(i);
	j = getp(j);
	if (i == j) return;

	if (rank[i] > rank[j]) p[j] = i;
	else{
		p[i] = j;
		if (rank[i] == rank[j]) ++rank[j];
	}
}

int main(){
	int N, M, i, j;

	while (scanf("%d%d", &N, &M) == 2){
		for (i = 0 ; i < N; ++i){
			p[i] = i;
			deg[i] = rank[i] = 0;
		}

		while (M--){
			scanf("%d%d", &i, &j);
			deg[i] ^= 1; deg[j] ^= 1;
			link(i, j);
		}

		for (i = 0; i < N; ++i) if (deg[i]) break;
		if (i >= N) for (i = 0; i < N; ++i) if (getp(i) != getp(0)) break;

		if (i < N) puts("Not Possible");
		else puts("Possible");
	}

	return 0;
}

/* @END_OF_SOURCE_CODE */
