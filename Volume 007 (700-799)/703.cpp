/* @JUDGE_ID: 19899RK 703 C++ "By Anadan" */ 
// Triple Ties: The Organizer's Nightmare
// Accepted (0.045 seconds with low memory spent)

#include <stdio.h>

int main(){
	int N, M, i, j, k, off;
	char map[100][100], out[100000], *p;

	while (scanf("%d\n", &N) == 1){
		for (i = 0; i < N; ++i) for (j = 0; j < N; ++j){
			while ((k = getchar()) != '0' && k != '1');
			map[i][j] = k - '0';
		}

		p = out;
		*p = 0;
		M = 0;

		for (i = 0; i < N; ++i){
			for (j = 0; j < i; ++j){
				if (map[i][j] == 0) continue;
				for (k = 0; k < j; ++k){
					if (map[j][k] && map[k][i]){
						++M;
						sprintf(p, "%d %d %d\n%n", i + 1, j + 1, k + 1, &off);
						p += off;
					}
				}
			}

			for (j = i + 1; j < N; ++j){
				for (k = j + 1; k < N; ++k){
					if ((map[i][j] && map[j][k] && map[k][i]) || (map[i][j] == 0 && map[j][k] == 0 && map[k][i] == 0 && map[j][i] == 0 && map[k][j] == 0 && map[i][k] == 0)){
						++M;
						sprintf(p, "%d %d %d\n%n", i + 1, j + 1, k + 1, &off);
						p += off;
					}
				}
			}
		}

		printf("%d\n%s", M, out);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
