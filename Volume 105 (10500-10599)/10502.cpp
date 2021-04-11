/* @JUDGE_ID: 19899RK 10502 C++ "By Anadan" */ 
// Counting Rectangles
// Accepted (0.008 seconds with low memory spent)

#include <stdio.h>

int main(){
	int row, col, i, j, k, l, x, map[100][100], res;

	while (scanf("%d%d", &row, &col) == 2 && row){
		for (i = 0; i < row; ++i) for (j = 0; j < col; ++j){
			while ((k = getchar()) != '0' && k != '1');
			map[i][j] = k - '0';
		}

		res = 0;
		for (i = 0; i < row; ++i){
			for (j = 0; j < col; ++j){
				if (map[i][j] == 0) continue;
				for (k = j; k < col; ++k){
					if (map[i][k] == 1) ++res;
					else break;
				}

				for (l = i + 1; l < row; ++l){
					if (map[l][j] != 1) break;
					for (x = j; x < k; ++x){
						if (map[l][x] == 1) ++res;
						else break;
					}
					k = x;
				}
			}
		}

		printf("%d\n", res);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
