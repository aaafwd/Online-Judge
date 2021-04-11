/* @JUDGE_ID: 19899RK 10637 C++ "By Anadan" */
// Coprimes
// Accepted (0.170 seconds using as much as 432 kbytes)

#include <stdio.h>

int S, T, curr[30], delims[101][101], sp[101];
char mask[101];

void generate(int pos, int sti, int rest){
	int i, j;

	if (pos == T - 1){
		curr[pos] = rest;
		for (i = 0; i < sp[rest]; ++i) if (mask[delims[rest][i]]) return;
		for (i = 0; i < T; ++i){
			if (i) putchar(' ');
			printf("%d", curr[i]);
		}
		putchar('\n');
		return;
	}

	if (sti == 1){
		curr[pos] = 1;
		if (rest > 1) generate(pos + 1, 1, rest - 1);
		++sti;
	}

	for (i = sti; (i+i+T-pos-1)*(T-pos)/2 <= rest; ++i){
		for (j = 0; j < sp[i]; ++j) if (mask[delims[i][j]]) break;
		if (j < sp[i]) continue;
		for (j = 0; j < sp[i]; ++j) mask[delims[i][j]] = 1;
		curr[pos] = i;
		generate(pos + 1, i, rest - i);
		for (j = 0; j < sp[i]; ++j) mask[delims[i][j]] = 0;
	}
}

int main(){
	int set, nt = 0, i, j;

	for (i = 2; i <= 100; ++i){
		sp[i] = 0;
		for (j = 2; j <= i; ++j) if (!(i % j)) delims[i][sp[i]++] = j;
	}

	scanf("%d", &set);
	while (set--){
		scanf("%d%d", &S, &T);
		printf("Case %d:\n", ++nt);
		generate(0, 1, S);
	}

	return 0;
}

/* @END_OF_SOURCE_CODE */
