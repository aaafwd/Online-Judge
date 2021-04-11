/* @JUDGE_ID: 19899RK 10583 C++ "By Anadan" */
// Ubiquitous Religions
// Accepted (0.916 seconds using as much as 784 kbytes)

#include <stdio.h>

int p[50001], rank[50001];

int getp(int i) {
	if (p[i] != i) p[i] = getp(p[i]);
	return p[i];
}

void link(int i, int j) {
	if (rank[i] < rank[j]) {
		p[i] = j;
	} else {
		p[j] = i;
		if (rank[i] == rank[j]) ++rank[i];
	}
}

int main() {
	int N, M, i, j, set = 0, res;

	while (scanf("%d%d", &N, &M) == 2 && N) {
		for (i = 0; i < N; ++i) {
			p[i] = i;
			rank[i] = 1;
		}
		res = N;
		while (M--) {
			scanf("%d%d", &i, &j);
			i = getp(i-1);
			j = getp(j-1);
			if (i != j) {
				--res;
				link(i, j);
			}
		}
		printf("Case %d: %d\n", ++set, res);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
