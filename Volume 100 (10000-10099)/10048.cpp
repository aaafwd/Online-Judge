/* @JUDGE_ID: 19899RK 10048 C++ "By Anadan" */ 
// Audiophobia
// Accepted (0.135 seconds using as much as 428 kbytes)

#include <stdio.h>

inline int max(int x, int y) { return (x > y) ? (x) : (y); }

int main(){
	int set = 0, N, S, Q, map[100][100], i, j, k;

	while (scanf("%d%d%d\n", &N, &S, &Q) == 3 && N){
		for (i = 0; i < N; ++i) for (j = 0; j < N; ++j) map[i][j] = -1;
		while (S--){
			scanf("%d%d%d\n", &i, &j, &k); --i; --j;
			map[i][j] = map[j][i] = k;
		}

		for (k = 0; k < N; ++k){
			for (i = 0; i < N; ++i){
				if (i == k || map[i][k] == -1) continue;
				for (j = 0; j < N; ++j){
					if (j == k || map[k][j] == -1) continue;
					if (map[i][j] == -1 || map[i][j] > max(map[i][k], map[k][j])){
						map[i][j] = max(map[i][k], map[k][j]);
					}
				}
			}
		}

		if (set) putchar('\n');
		printf("Case #%d\n", ++set);
		while (Q--){
			scanf("%d%d\n", &i, &j); --i; --j;
			if (map[i][j] == -1) printf("no path\n");
			else printf("%d\n", map[i][j]);
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
