/* @JUDGE_ID: 19899RK 836 C++ "By Anadan" */
// Largest Submatrix
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

int main(){
	int set, N, i, j, x, y, z, max;
	char map[25][26];

	scanf("%d\n\n", &set);
	while (set--){
		scanf("%s\n", map[0]);
		N = strlen(map[0]);
		for (i = 1; i < N; ++i) scanf("%s\n", map[i]);
		scanf("\n");

		max = 0;
		for (i = 0; i < N; ++i) for (j = 0; j < N; ++j){
			if (map[i][j] == '0') continue;
			for (x = 1; j + x < N && map[i][j + x] == '1'; ++x);
			if (max < x) max = x;
			for (y = 1; i + y < N && x;){
				for (z = 0; z < x && map[i + y][j + z] == '1'; ++z);
				x = z; ++y;
				if (max < x * y) max = x * y;
			}
		}

		printf("%d\n", max);
		if (set) putchar('\n');
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
