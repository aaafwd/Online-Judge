/* @JUDGE_ID: 19899RK 10400 C++ "By Anadan" */
// Game Show Math
// Accepted (3.861 seconds using as much as 6640 kbytes)
// Too much time !

#include <stdio.h>
#include <string.h>
#define SZ 64001
#define ZR 32000

int main(){
	int set, i, j, k, R, N, nums[100], R_sav;
	char map[100][SZ], ops[100];

	scanf("%d\n", &set);
	while (set--){
		scanf("%d", &N);
		scanf("%d", nums);
		memset(map[0], 0, SZ);
		map[0][nums[0] + ZR] = 1;
		for (i = 1; i < N; ++i){
			scanf("%d", nums + i);
			memset(map[i], 0, SZ);
			for (j = 0; j < SZ; ++j){
				if (map[i - 1][j]){
					k = j + nums[i] - ZR;
					if (-ZR < k && k < ZR) map[i][k + ZR] = 1;
					k = j - nums[i] - ZR;
					if (-ZR < k && k < ZR) map[i][k + ZR] = 1;
					k = (j  - ZR) * nums[i];
					if (-ZR < k && k < ZR) map[i][k + ZR] = 1;
					if (!((j - ZR) % nums[i])){
						k = (j  - ZR) / nums[i];
						if (-ZR < k && k < ZR) map[i][k + ZR] = 1;
					}
				}
			}
		}

		scanf("%d\n", &R);
		if (map[N - 1][R + ZR] == 0) printf("NO EXPRESSION\n");
		else{
			R_sav = R;
			for (i = N - 2; i >= 0; --i){
				for (j = 0; j < SZ; ++j){
					if (map[i][j]){
						k = j - ZR;
						if (k + nums[i + 1] == R){
							R -= nums[i + 1];
							ops[i] = '+';
							break;
						}
						if (k - nums[i + 1] == R){
							R += nums[i + 1];
							ops[i] = '-';
							break;
						}
						if (k * nums[i + 1] == R){
							R /= nums[i + 1];
							ops[i] = '*';
							break;
						}
						if (!(k % nums[i + 1]) && k / nums[i + 1] == R){
							R *= nums[i + 1];
							ops[i] = '/';
							break;
						}
					}
				}
			}

			for (i = 0; i < N - 1; ++i){
				printf("%d%c", nums[i], ops[i]);
			}
			printf("%d=%d\n", nums[i], R_sav);
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
