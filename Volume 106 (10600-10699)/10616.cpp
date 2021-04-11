/* @JUDGE_ID: 19899RK 10616 C++ "By Anadan" */
// Divisible Group Sums
// Accepted (0.059 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

int arr[200], map[20][11];

int main(){
	int set = 0, query, N, Q, D, M, i, d, m;

	while (scanf("%d%d", &N, &Q) == 2 && N){
		for (i = 0; i < N; ++i) scanf("%d", arr+i);
		printf("SET %d:\n", ++set);
		for (query = 1; query <= Q; ++query){
			scanf("%d%d", &D, &M);
			memset(map, 0, sizeof(map));
			map[0][0] = 1;

			for (i = 0; i < N; ++i){
				for (m = M-1; m >=0; --m) for (d = 0; d < D; ++d){
					if (!map[d][m]) continue;
					int k = d + arr[i];
					if (k >= 0) k %= D; else k += ((-k+D-1)/D) * D;
					map[k][m+1] += map[d][m];
				}
			}

			printf("QUERY %d: %d\n", query, map[0][M]);
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
