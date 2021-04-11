/* @JUDGE_ID: 19899RK 590 C++ "By Anadan" */
// Always on the run
// Accepted (0.020 seconds with low memory spent)

#include <stdio.h>

int main(){
	int i, j, l, n, k, set = 0, per[10][10], shed[10][10][30];
	int cur[2][10], c, tmp;

	while (scanf("%d%d", &n, &k) == 2 && n){
		for (i = 0; i < n; ++i){
			for (j = 0; j < n; ++j){
				if (i == j) continue;
				scanf("%d", &per[i][j]);
				for (l = 0; l < per[i][j]; ++l) scanf("%d", &shed[i][j][l]);
			}
		}

		cur[0][0] = 0;
		for (c = 0, i = 1; i < n; ++i) cur[0][i] = -1;
		for (i = 0; i < k; ++i){
			c ^= 1;
			for (l = 0; l < n; ++l) cur[c][l] = -1;
			for (j = 0; j < n; ++j){
				if (cur[c ^ 1][j] == -1) continue;
				for (l = 0; l < n; ++l){
					if (l == j) continue;
					tmp = shed[j][l][i % per[j][l]];
					if (tmp == 0) continue;
					tmp += cur[c ^ 1][j];
					if (cur[c][l] == -1 || cur[c][l] > tmp) cur[c][l] = tmp;
				}
			}
		}

		printf("Scenario #%d\n", ++set);
		if (cur[c][n - 1] != -1) printf("The best flight costs %d.\n\n", cur[c][n - 1]);
		else printf("No flight possible.\n\n");
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
