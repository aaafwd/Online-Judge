/* @JUDGE_ID: 19899RK 435 C++ "By Anadan" */ 
// Block Voting
// Accepted (0.008 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

int main(){
	int set, N, i, j, k, party[20], sum, votes[20001], ctrl;

	scanf("%d\n", &set);
	while (set--){
		scanf("%d", &N);
		for (sum = i = 0; i < N; ++i){
			scanf("%d", party + i);
			sum += party[i];
		}

		memset(votes, 0, sizeof(int) * (sum + 1));
		votes[0] = 1;
		for (i = 0; i < N; ++i){
			for (j = sum; j >= party[i] ; --j){
				votes[j] += votes[j - party[i]];
			}
		}

		ctrl = sum / 2 + 1;
		for (i = 0; i < N; ++i){
			if (party[i]){
				for (j = 0; j <= sum - party[i]; ++j) votes[j + party[i]] -= votes[j];
				for (k = j = 0; j < ctrl; ++j) if (j + party[i] >= ctrl) k += votes[j];
				for (j = sum; j >= party[i] ; --j) votes[j] += votes[j - party[i]];
			}else k = 0;
			printf("party %d has power index %d\n", i + 1, k);
		}

		putchar('\n');
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
