/* @JUDGE_ID: 19899RK 10503 C++ "By Anadan" */ 
// The dominoes solitaire
// Accepted (0.025 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

int n, m, l, r, x[14], y[14];
char mask[14];

int solved(int left, int sp){
	int i;

	if (sp == 0) return (left == r);
	for (i = 0; i < m; ++i){
		if (mask[i]) continue;
		mask[i] = 1;
		if (x[i] == left){
			if (solved(y[i], sp - 1)) return 1;

		}else if (y[i] == left){
			if (solved(x[i], sp - 1)) return 1;

		}
		mask[i] = 0;
	}

	return 0;
}

int main(){
	int i;

	while (scanf("%d%d", &n, &m) == 2 && n){
		scanf("%*d%d%d%*d", &l, &r);
		for (i = 0; i < m; ++i) scanf("%d%d", x + i, y + i);
		memset(mask, 0, m);

		if (solved(l, n)) puts("YES");
		else puts("NO");
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
