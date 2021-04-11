/* @JUDGE_ID: 19899RK 201 C++ "By Anadan" */
// Squares
// Accepted (0.400 seconds using as much as 392 kbytes)

#include <stdio.h>

int main(){
	int n, m, i, j, k, set = 0;
	char maph[9][9][9], mapv[9][9][9], id[2], solved;

	while (scanf("%d%d\n", &n, &m) == 2){
		for (i = 0; i < n; i++) for (j = 0; j < n; j++)
		for (k = 0; k < n; k++) maph[i][j][k] = mapv[i][j][k] = 0;
		if (set) printf("\n**********************************\n\n");
		printf("Problem #%d\n\n", ++set);
		for (i = 0; i < m; i++){
			scanf("%s %d %d\n", id, &j, &k);
			--j; --k;
			if (id[0] == 'H') maph[j][k][k + 1] = 1;
			else mapv[j][k][k + 1] = 1;
		}

		for (i = 0; i < n; ++i){
			for (j = 0; j < n; ++j){
				for (k = j + 1; k < n; ++k){
					if (maph[i][k - 1][k]) maph[i][j][k] = 1;
					else break;
				}

				for (k = j + 1; k < n; ++k){
					if (mapv[i][k - 1][k]) mapv[i][j][k] = 1;
					else break;
				}
			}
		}

		solved = 0;
		for (k = 1; k < n; ++k){
			m = 0;
			for (i = 0; i < n - k; ++i) for (j = 0; j < n - k; ++j)
				if (maph[i][j][j + k] && mapv[j][i][i + k] && maph[i + k][j][j + k] && mapv[j + k][i][i + k]) ++m;
			if (m){
				printf("%d square (s) of size %d\n", m, k);
				solved = 1;
			}
		}
		if (!solved) printf("No completed squares can be found.\n");
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
