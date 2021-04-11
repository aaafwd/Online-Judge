/* @JUDGE_ID: 19899RK 10520 C++ "By Anadan" */ 
// Determine it
// Accepted (0.465 seconds using as much as 392 kbytes)

#include <stdio.h>

int main(){
	int N, i, j, k;
	long long arr[20][20], max;

	while (scanf("%d%d", &N, &i) == 2){
		arr[N][0] = 0;
		arr[N][1] = i;

		for (j = 2; j <= N; ++j) arr[N][j] = arr[N][j - 1] << 1;

		for (i = N - 1; i; --i){
			for (j = 0; j <= i; ++j){
				max = arr[i + 1][1] + arr[i + 1][j];
				for (k = i + 1; k <= N; ++k){
					if (max < arr[k][1] + arr[k][j]){
						max = arr[k][1] + arr[k][j];
					}
				}
				arr[i][j] = max;

				if (j > 1){
					max = arr[i][1] + arr[N][1];
					for (k = 2; k < j; ++k){
						if (max < arr[i][k] + arr[N][k]){
							max = arr[i][k] + arr[N][k];
						}
					}
					arr[i][j] += max;
				}
			}

			for (; j <= N; ++j){
				max = arr[i][i] + arr[i + 1][j];
				for (k = i; k < j; ++k){
					if (max < arr[i][k] + arr[k + 1][j]){
						max = arr[i][k] + arr[k + 1][j];
					}
				}
				arr[i][j] = max;
			}
		}

		printf("%lld\n", arr[1][N]);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
