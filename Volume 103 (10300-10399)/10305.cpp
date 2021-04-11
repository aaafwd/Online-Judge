/* @JUDGE_ID: 19899RK 10305 C++ "By Anadan" */
// Ordering Tasks
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

int main(){
	int N, m, i, j, x, y;
	char map[100][100];

	while (scanf("%d%d", &N, &m) == 2){
		if (N == 0) break;
		for (i = 0; i < N; ++i) memset(map[i], 0, N);
		for (i = 0; i < m; ++i){
			scanf("%d%d", &x, &y);
			--x; --y;
			map[y][x] = 1;
		}

		m = N;
		while (m){
			for (i = 0; i < N; ++i){
				if (memchr(map[i], 1, N) == NULL){
					for (j = 0; j < N; ++j) map[j][i] = 0;
					map[i][i] = 1;
					if (m-- == N) printf("%d", i + 1);
					else printf(" %d", i + 1);
				}
			}
		}

		printf("\n");
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
