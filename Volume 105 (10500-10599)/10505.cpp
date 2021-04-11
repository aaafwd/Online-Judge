/* @JUDGE_ID: 19899RK 10505 C++ "By Anadan" */ 
// Montesco vs Capuleto
// Accepted (0.004 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

int N, count[2], errflag;
char map[200][200], mask[200];

void dfs(int i, int c){
	int j;

	mask[i] = c + 1;
	++count[c];

	for (j = 0; j < N; ++j){
		if (!map[i][j]) continue;
		if (mask[j] == 0) dfs(j, c ^ 1);
		else if (mask[j] != (c ^ 1) + 1) errflag = 1;
	}
}

int main(){
	int set, i, j, p;

	scanf("%d", &set);
	while (set--){
		scanf("%d", &N);
		for (i = 0; i < N; ++i) memset(map[i], 0, N);
		for (i = 0; i < N; ++i){
			scanf("%d", &p);
			while (p--){
				scanf("%d", &j); --j;
				if (j < N){
					map[i][j] = map[j][i] = 1;
				}
			}
		}

		memset(mask, 0, N);
		for (p = i = 0; i < N; ++i){
			if (mask[i]) continue;

			errflag = count[0] = count[1] = 0;
			dfs(i, 0);

			if (!errflag){
				if (count[0] < count[1]) count[0] = count[1];
				p += count[0];
			}
		}

		printf("%d\n", p);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
