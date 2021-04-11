/* @JUDGE_ID: 19899RK 10448 C++ "By Anadan" */ 
// Unique World
// Accepted (0.234 seconds using as much as 604 kbytes)

#include <stdio.h>
#include <string.h>

int e[50][50], map[50][50], cost[50], C;

void getcost(int i, int j){
	while (e[i][j] != -1){
		getcost(i, e[i][j]);
		i = e[i][j];
	}
	cost[C++] = map[i][j];
}

int main(){
	int set, N, Q, i, j, k, m[50001];

	scanf("%d\n", &set);
	while (set--){
		memset(map, -1, sizeof(map));
		memset(e, -1, sizeof(e));

		scanf("%d%d", &N, &Q);
		while (Q--){
			scanf("%d%d%d\n", &i, &j, &k); --i; --j;
			map[i][j] = map[j][i] = k;
		}

		for (k = 0; k < N; ++k){
			for (i = 0; i < N; ++i){
				if (i == k || map[i][k] == -1) continue;
				for (j = 0; j < N; ++j){
					if (j == k || map[k][j] == -1) continue;
					if (map[i][j] == -1 || map[i][j] > map[i][k] + map[k][j]){
						map[i][j] = map[i][k] + map[k][j];
						e[i][j] = k;
					}
				}
			}
		}

		scanf("%d\n", &Q);
		while(Q--){
			scanf("%d%d%d\n", &i, &j, &k); --i; --j;
			C = 0;
			getcost(i, j);
			if (C == 1){
				printf((cost[0] == k) ? "Yes 1\n" : "No\n");
				continue;
			}

			for (i = 0; i < C; ++i) k -= cost[i];
			if (k < 0 || (k & 1)) printf("No\n");
			else if (k == 0) printf("Yes %d\n", C);
			else{
				--C;
				k >>= 1;
				memset(m, -1, sizeof(int) * (k + 1));
				m[0] = 0;
				for (i = 0; i < C; ++i){
					for (j = 0; j <= k - cost[i]; ++j){
						if (m[j] == -1) continue;
						if (m[j + cost[i]] == -1 || m[j + cost[i]] > m[j] + 1){
							m[j + cost[i]] = m[j] + 1;
						}
					}
				}

				if (m[k] == -1) printf("No\n");
				else printf("Yes %d\n", m[k] + m[k] + C + 1);
			}
		}

		if (set) putchar('\n');
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
