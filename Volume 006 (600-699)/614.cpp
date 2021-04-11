/* @JUDGE_ID: 19899RK 614 C++ "By Anadan" */ 
// Mapping the Route
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

int rows, cols, mask[12][12];
struct Point{
	int x, y;
}p0, p1;
char map[12][12];

int fillmaze(int i, int j, int step){
	++step;

	if (i == p1.x && j == p1.y){
		mask[i][j] = step;
		return 1;
	}

	mask[i][j] = -1;
	if (!(map[i][j] & 4) && mask[i][j - 1] == 0 && fillmaze(i, j - 1, step))
		{ mask[i][j] = step; return 1; }

	if (!(map[i][j] & 8) && mask[i - 1][j] == 0 && fillmaze(i - 1, j, step))
		{ mask[i][j] = step; return 1; }

	if (!(map[i][j] & 1) && mask[i][j + 1] == 0 && fillmaze(i, j + 1, step))
		{ mask[i][j] = step; return 1; }

	if (!(map[i][j] & 2) && mask[i + 1][j] == 0 && fillmaze(i + 1, j, step))
		{ mask[i][j] = step; return 1; }

	return 0;
}

int main(){
	int set = 0, i, j, k;

	while (scanf("%d%d%d%d%d%d", &rows, &cols, &p0.x, &p0.y, &p1.x, &p1.y) == 6 && rows){
		--p0.x; --p0.y; --p1.x; --p1.y;
		memset(map, 0, sizeof(map));
		for (i = 0; i < cols; ++i){
			map[0][i] |= 8;
			map[rows - 1][i] |= 2;
		}

		for (i = 0; i < rows; ++i){
			map[i][0] |= 4;
			map[i][cols - 1] |= 1;
		}

		for (i = 0; i < rows; ++i){
			for (j = 0; j < cols; ++j){
				while ((k = getchar()) < '0' || k > '9');
				k -= '0';
				map[i][j] |= k;
				if (k & 1) map[i][j + 1] |= 4;
				if (k & 2) map[i + 1][j] |= 8;
			}
		}

		memset(mask, 0, sizeof(mask));
		fillmaze(p0.x, p0.y, 0);

		printf("Maze %d\n\n", ++set);

		for (i = 0; i < rows; ++i){
			for (j = 0; j < cols; ++j){
				putchar('+');
				if (map[i][j] & 8){
					putchar('-'); putchar('-'); putchar('-');
				}else{
					putchar(' '); putchar(' '); putchar(' ');
				}
			}
			puts("+");

			for (j = 0; j < cols; ++j){
				if (map[i][j] & 4) putchar('|'); else putchar(' ');
				if (mask[i][j] == -1){
					putchar('?'); putchar('?'); putchar('?');
				}else if (mask[i][j]){
					printf("%3d", mask[i][j]);
				}else{
					putchar(' '); putchar(' '); putchar(' ');
				}
			}
			puts("|");
		}

		for (j = 0; j < cols; ++j){
			putchar('+'); putchar('-'); putchar('-'); putchar('-');
		}
		puts("+\n\n");
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
