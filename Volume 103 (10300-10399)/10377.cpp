/* @JUDGE_ID: 19899RK 10377 C++ "By Anadan" */
// Maze Traversal
// Accepted (0.002 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

int main(){
	int set, rows, cols, i, j, di, dj;
	char map[62][62], dir[2];

	for (i = 0; i < 62; ++i) map[0][i] = map[0][i] = 0;
	scanf("%d\n\n", &set);
	while (set--){
		scanf("%d%d\n", &rows, &cols);
		for (i = 1; i <= rows; ++i) gets(map[i] + 1);
		memset(map[i], 0, cols + 2);
		scanf("%d%d\n", &i, &j);
		di = -1; dj = 0;

		while (scanf("%1s", dir) == 1 && dir[0] != 'Q'){
			if (dir[0] == 'F'){
				if (map[i + di][j + dj] == ' '){
					i += di; j += dj;
				}
			}else{
				di ^= dj ^= di ^= dj;
				if (dir[0] == 'R') dj = -dj; else di = -di;
			}
		}

		printf("%d %d %c\n", i, j, "NW ES"[2*di + dj + 2]);

		if (set) putchar('\n');
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
