/* @JUDGE_ID: 19899RK 10192 C++ "By Anadan" */ 
// Vacation
// Accepted (0.004 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

int main(){
	int coins[101], tmp[101], l1, l2, i, j, k, set = 0;
	char s1[101], s2[101];

	while (gets(s1)){
		if (s1[0] == '#' && s1[1] == 0) break;
		gets(s2);
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

		printf("Case #%d: you can visit at most %d cities.\n", ++set, j);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
