/* @JUDGE_ID: 19899RK 10246 C++ "By Anadan" */
// Asterix and Obelix
// Accepted (0.414 seconds using as much as 440 kbytes)

#include <stdio.h>
#include <string.h>

int N, map[80][80], f[80][80];

inline int max(int a, int b) { return (a > b) ? (a) : (b); }

void floyd(){
	int i, j, k, m;

	for (k = 0; k < N; ++k){
		for (i = 0; i < N; ++i){
			if (i == k || map[i][k] == -1) continue;
			for (j = 0; j < N; ++j){
				if (j == k || map[k][j] == -1) continue;
				m = max(f[i][k], f[k][j]);
				if (map[i][j] == -1 || map[i][j] + f[i][j] > map[i][k] + map[k][j] + m){
					f[i][j] = m;
					map[i][j] = map[i][k] + map[k][j];
				}
			}
		}
	}
}

int main(){
	int set = 0, R, Q, i, j, k, feast[80];

	while (scanf("%d%d%d\n", &N, &R, &Q) == 3 && N){
		for (i = 0; i < N; ++i) scanf("%d", feast + i);
		memset(f, -1, sizeof(f));
		memset(map, -1, sizeof(map));
		while (R--){
			scanf("%d%d%d\n", &i, &j, &k); --i; --j;
			map[i][j] = map[j][i] = k;
			f[i][j] = f[j][i] = max(feast[i], feast[j]);
		}

		floyd();
		floyd();

		for (i = 0; i < N; ++i) map[i][i] = 0;

//**/		if (set) putchar('\n');
		printf("Case #%d\n", ++set);
		while (Q--){
			scanf("%d%d\n", &i, &j); --i; --j;
			if (map[i][j] == -1) printf("-1\n");
			else printf("%d\n", map[i][j] + f[i][j]);
		}

/**/		putchar('\n');
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
