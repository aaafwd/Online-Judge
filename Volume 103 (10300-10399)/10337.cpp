/* @JUDGE_ID: 19899RK 10337 C++ "By Anadan" */ 
// Flight Planner
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>

int main(){
	int N, i, j, set, tmp;
	int flying[2][10], c;
	char wind[10][1000];

	scanf("%d\n", &set);
	while (set--){
		scanf("%d\n", &N); N /= 100;
		for (i = 9; i >= 0; --i){
			for (j = 0; j < N; ++j){
				scanf("%d", &tmp);
				wind[i][j] = tmp;
			}
		}

		if (N == 1){
			printf("%d\n\n", 30 - wind[0][0]);
			continue;
		}

		c = 0;
		flying[0][0] = 0;
		for (i = 1; i < N; ++i){
			for (j = 0; j < 10; ++j){
				if (j > i) continue;
				if (j) flying[c ^ 1][j] = flying[c][j - 1] + 60 - wind[j - 1][i - 1];

				if (j != i){
					tmp = flying[c][j] + 30 - wind[j][i - 1];
					if (j == 0 || flying[c ^ 1][j] > tmp) flying[c ^ 1][j] = tmp;
				}

				if (j < 9 && j < i - 1){
					tmp = flying[c][j + 1] + 20 - wind[j + 1][i - 1];
					if (flying[c ^ 1][j] > tmp) flying[c ^ 1][j] = tmp;
				}
			}

			c ^= 1;
		}

		tmp = flying[c][0] + 30 - wind[0][i - 1];
		if (tmp > flying[c][1] + 20 - wind[1][i - 1]) tmp = flying[c][1] + 20 - wind[1][i - 1];
		printf("%d\n\n", tmp);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
