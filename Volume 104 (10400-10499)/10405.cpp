/* @JUDGE_ID: 19899RK 10405 C++ "By Anadan" */
// Longest Common Subsequence
// Accepted (0.012 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

int main(){
	int coins[1001], tmp[1001], l1, l2, i, j, k;
	char s1[1001], s2[1001];

	while (gets(s1) && gets(s2)){
		l1 = strlen(s1); l2 = strlen(s2);
		memset(coins, 0, l1 * sizeof(int));
		for (j = 0; j < l2; ++j){
			memcpy(tmp, coins, l1 * sizeof(int));
			for (i = 0; i < l1; ++i){
				if (s1[i] == s2[j]){
					if (i == 0) tmp[i] = 1;
					else tmp[i] = coins[i - 1] + 1;
				}
			}

			for (i = k = 0; k < l1; ++k){
				if (i < tmp[k]) i = tmp[k];
				if (coins[k] < i) coins[k] = i;
			}
		}

		for (i = j = 0; i < l1; ++i){
			if (j < coins[i]) j = coins[i];
		}

		printf("%d\n", j);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
