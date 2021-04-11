/* @JUDGE_ID: 19899RK 10296 C++ "By Anadan" */ 
// Jogging Trails
// Accepted (0.076 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

int map[15][15], odd[15], N;
int minpath[16384];

int getminpath(int k){
	int i, j, min = -1, tmp;

	if (minpath[k] != -1) return minpath[k];
	if (k == 0) return 0;

	for (i = 0; i < N; ++i){
		if (!(k & (1 << i))) continue;
		k ^= (1 << i);
		for (j = i + 1; j < N; ++j){
			if (!(k & (1 << j))) continue;
			k ^= (1 << j);
			
			if (min == -1) min = getminpath(k) + map[odd[i]][odd[j]];
			else if (min > map[odd[i]][odd[j]]){
				tmp = getminpath(k) + map[odd[i]][odd[j]];
				if (min > tmp) min = tmp;
			}

			k ^= (1 << j);
		}
		k ^= (1 << i);
	}

	minpath[k] = min;
	return min;
}

int main(){
	int n, m, i, j, k, sum, dv[15];

	while (scanf("%d%d\n", &n, &m) == 2 && n){
		sum = 0;
		memset(map, -1, sizeof(map));
		memset(dv, 0, sizeof(dv));
		while (m--){
			scanf("%d%d%d\n", &i, &j, &k); --i; --j;
			sum += k; ++dv[i]; ++dv[j];
			if (map[i][j] == -1 || map[i][j] > k){
				map[i][j] = map[j][i] = k;
			}
		}

		for (N = i = 0; i < n; ++i) if (dv[i] & 1) odd[N++] = i;
		if (N){
			for (k = 0; k < n; ++k){
				for (i = 0; i < n; ++i){
					if (i == k || map[i][k] == -1) continue;
					for (j = 0; j < n; ++j){
						if (j == k || map[k][j] == -1) continue;
						if (map[i][j] == -1 || map[i][j] > map[i][k] + map[k][j]){
							map[i][j] = map[i][k] + map[k][j];
						}
					}
				}
			}

			k = 1 << N;
			memset(minpath, -1, sizeof(int) * k);
			sum += getminpath(k - 1);
		}

		printf("%d\n", sum);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
