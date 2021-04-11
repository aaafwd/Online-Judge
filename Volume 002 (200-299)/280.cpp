/* @JUDGE_ID: 19899RK 280 C++ "By Anadan" */
// Vertex
// Accepted (2.402 seconds using as much as 396 kbytes)

#include <stdio.h>
#include <string.h>

int main(){
	int N, i, j, k, stack[100], sp;
	char map[100][100];

	while (scanf("%d", &N) == 1 && N){
		for (i = 0; i < N; ++i) memset(map[i], 0, N);
		while (scanf("%d", &i) == 1 && i){
			--i;
			while (scanf("%d", &j) == 1 && j){
				--j;
				map[i][j] = 1;
			}
		}

		for (k = 0; k < N; ++k){
			for (i = 0; i < N; ++i){
				if (map[i][k] == 0) continue;
				for (j = 0; j < N; ++j){
					if (map[k][j]) map[i][j] = 1;
				}
			}
		}

		scanf("%d", &k);
		while (k--){
			scanf("%d", &j); --j;
			for (sp = i = 0; i < N; ++i){
				if (map[j][i] == 0){
					stack[sp++] = i + 1;
				}
			}

			printf("%d", sp);
			for (i = 0; i < sp; ++i) printf(" %d", stack[i]);
			putchar('\n');
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
