/* @JUDGE_ID: 19899RK 10130 C++ "By Anadan" */ 
// SuperSale
// Accepted (0.088 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

int main(){
	int set, N, P, W, i, j, maxprice[31];

	scanf("%d\n", &set);
	while (set--){
		memset(maxprice, 0, sizeof(maxprice));
		scanf("%d\n", &N);
		for (i = 0; i < N; ++i){
			scanf("%d%d\n", &P, &W);
			for (j = 30 - W; j >= 0; --j){
				if (maxprice[j + W] < maxprice[j] + P){
					maxprice[j + W] = maxprice[j] + P;
				}
			}
		}

		for (i = 1; i < 31; ++i) if (maxprice[i] < maxprice[i - 1]){
			maxprice[i] = maxprice[i - 1];
		}

		P = 0;
		scanf("%d\n", &N);
		while (N--){
			scanf("%d\n", &W);
			P += maxprice[W];
		}

		printf("%d\n", P);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
