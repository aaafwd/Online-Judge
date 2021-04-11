/* @JUDGE_ID: 19899RK 10057 C++ "By Anadan" */ 
// A mid-summer night's dream
// Accepted (0.932 seconds using as much as 640 kbytes)

#include <stdio.h>
#include <string.h>

int main(){
	int N, i, j, k, nums[65536];

	while (scanf("%d\n", &N) == 1){
		memset(nums, 0, sizeof(nums));
		for (i = 0; i < N; ++i){
			while ((k = getchar()) == ' ' || k == '\n');
			k -= '0';
			while ((j = getchar()) != ' ' && j != '\n'){
				k = 10 * k + j - '0';
			}
			++nums[k];
		}

		for (j = i = 0; i < 65536; ++i){
			j += nums[i];
			if (j + j >= N) break;
		}

		if (N & 1) printf("%d %d 1\n", i, nums[i]);
		else{
			if (j + j == N){
				for (k = i + 1; nums[k] == 0; ++k);
				nums[i] += nums[k];
			}else k = i;
			printf("%d %d %d\n", i, nums[i], k - i + 1);
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
