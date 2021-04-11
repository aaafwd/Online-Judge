/* @JUDGE_ID: 19899RK 430 C++ "By Anadan" */ 
// Swamp County Supervisors
// Accepted (0.066 seconds with low memory spent)

#include <stdio.h>
#include <string.h>
#define SZ 30000

int main(){
	int N, i, j, k, bog[27], sum, votes[SZ], ctrl;
	char str[256], *p;

	while (gets(str)){
		N = sum = 0;
		p = strtok(str, " ");
		sscanf(p, "%d", &ctrl);
		p = strtok(NULL, " ");
		while (p){
			sscanf(p, "%d", bog + N);
			sum += bog[N++];
			p = strtok(NULL, " ");
		}

		memset(votes, 0, sizeof(int) * (sum + 1));
		votes[0] = 1;
		for (i = 0; i < N; ++i){
			for (j = sum; j >= bog[i] ; --j){
				votes[j] += votes[j - bog[i]];
			}
		}

		for (i = 0; i < N; ++i){
			if (bog[i]){
				for (j = 0; j <= sum - bog[i]; ++j) votes[j + bog[i]] -= votes[j];
				for (k = j = 0; j < ctrl; ++j) if (j + bog[i] >= ctrl) k += votes[j];
				for (j = sum; j >= bog[i] ; --j) votes[j] += votes[j - bog[i]];
			}else k = 0;

			if (i) putchar(' ');
			printf("%d", k);
		}

		putchar('\n');
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
