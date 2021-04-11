/* @JUDGE_ID: 19899RK 10074 C++ "By Anadan" */ 
// Take the Land
// Accepted (0.050 seconds with low memory spent)

#include <stdio.h>

int main(){
	int i, j, k, l, tmp, size, M, N, S;
	char map[100][100];

	while (scanf("%d%d", &M, &N) == 2){
		if (M == 0) break;
		for (i = 0; i < M; ++i){
			for (j = 0; j < N; ++j){
				scanf("%d", &k);
				map[i][j] = (char)k;
			}
		}

		S = 0;
		for (i = 0; i < M; ++i) for (j = 0; j < N; ++j){
			for (size = 0, l = j; l < N; ++l, ++size){
				if (map[i][l]) break;
			}
			if (size > S) S = size;

			for (k = i + 1; k < M; ++k){
				for (l = j, tmp = 0; tmp < size; ++l, ++tmp){
					if (map[k][l]) break;
				}
				size = tmp;
				tmp *= k - i + 1;
				if (tmp > S) S = tmp;
			}
		}
		printf("%d\n", S);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
