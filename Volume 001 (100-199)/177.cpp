/* @JUDGE_ID: 19899RK 177 C++ "By Anadan" */
// Paper Folding
// Accepted (0.004 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

int main(){
	static int edges[8192], i, j, k, N, x1, x2, y1, y2;
	char map[300][300];

	edges[0] = 1;
	for (j = N = 1; N <= 13; ++N){
		for (i = j - 1; i >= 0; --i) edges[j++] = (edges[i] + 3) & 3;
	}

	while (scanf("%d\n", &N) == 1 && N){
		memset(map, ' ', sizeof(map));
		x1 = x2 = y1 = y2 = i = j = 200;
		map[i][j] = '_';
		N = 1 << N;
		for (k = 1; k < N; ++k){
			if (edges[k - 1] == 0) --i;
			else if (edges[k - 1] == 1) ++j;
			else if (edges[k - 1] == 3) --j;

			if (edges[k] == 1) { map[i][++j] = '_'; }
			else if (edges[k] == 2) { map[++i][j] = '|'; }
			else if (edges[k] == 3) { map[i][--j] = '_'; }
			else map[i][j] = '|';

			if (y1 > i) y1 = i;
			if (y2 < i) y2 = i;
			if (x1 > j) x1 = j;
			if (x2 < j) x2 = j;
		}

		for (i = y1; i <= y2; ++i){
			for (j = x2; map[i][j] == ' '; --j);
			map[i][j + 1] = 0;
			printf("%s\n", map[i] + x1);
		}

		printf("^\n");
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
