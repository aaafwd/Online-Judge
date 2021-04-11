/* @JUDGE_ID: 19899RK 812 C++ "By Anadan" */ 
// Trade on Verweggistan
// Accepted (0.041 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

void myscanf(int &x){
	int i;

	while ((x = getchar()) != EOF && (x < '0' || x > '9'));
	x -= '0';
	while ((i = getchar()) != EOF && '0' <= i && i <= '9'){
		x = x * 10 + i - '0';
	}
}

int main(){
	int set = 0, w, i, j, k, m, N, max, cur, totmax;
	int numpruls[50][21], dp[50];
	char mask[1001], tmp[1001];

	while (scanf("%d", &w) == 1 && w){
		totmax = 0;
		for (i = 0; i < w; ++i){
			myscanf(N);
			max = 0;
			numpruls[i][0] = 0;
			dp[i] = 1;

			for (cur = j = 0; j < N; ++j){
				myscanf(k);
				cur += 10 - k;
				if (cur > max){
					max = cur;
					numpruls[i][0] = j + 1;
					dp[i] = 1;
				}else if (cur == max){
					numpruls[i][dp[i]++] = j + 1;
				}
			}

			totmax += max;
		}

		max = 0;
		for (cur = i = 0; i < w; ++i){
			cur += numpruls[i][0];
			max += numpruls[i][dp[i] - 1] - numpruls[i][0];
		}
		memset(mask, 0, max + 1);
		mask[0] = 1;

		for (i = 0; i < w; ++i){
			if (dp[i] < 2) continue;
			memset(tmp, 0, max + 1);
			for (j = 0; j < dp[i]; ++j){
				m = numpruls[i][j] - numpruls[i][0];
				for (k = max - m; k >= 0; --k){
					if (mask[k]) tmp[k + m] = 1;
				}
			}

			memcpy(mask, tmp, max + 1);
		}

		if (set) putchar('\n');
		printf("Workyards %d\n", ++set);
		printf("Maximum profit is %d.\nNumber of pruls to buy:", totmax);
		for (i = j = 0; j < 10 && i <= max; ++i){
			if (mask[i]){
				printf(" %d", cur + i);
				++j;
			}
		}
		putchar('\n');
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
