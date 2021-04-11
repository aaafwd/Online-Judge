/* @JUDGE_ID: 19899RK 10667 C++ "By Anadan" */
// Largest Block
// Accepted (0.045 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

int N, arr[100][100];
char map[100][100];

int main(){
	int set, M, r1, r2, c1, c2, i, j, k, res;

	scanf("%d", &set);
	while (set--){
		scanf("%d%d", &N, &M);
		memset(map, 0, sizeof(map));
		while (M--){
			scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
			--r1; --r2; --c1; --c2;
			for (i = r1; i <= r2; ++i)
			for (j = c1; j <= c2; ++j) map[i][j] = 1;
		}

		res = 0;
		for (i = 0; i < N; ++i){
			for (j = 0; j < N; ++j){
				if (map[i][j]) { arr[i][j] = 0; continue; }
				else if (j) arr[i][j] = arr[i][j - 1] + 1;
				else arr[i][j] = 1;

				r1 = arr[i][j];
				for (k = i; k >= 0; --k){
					if (r1 > arr[k][j]) r1 = arr[k][j];
					if (res < (i-k+1) * r1) res = (i-k+1) * r1;
				}
			}
		}

		printf("%d\n", res);
	}

	return 0;
}

/* @END_OF_SOURCE_CODE */
