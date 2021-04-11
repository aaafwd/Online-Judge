/* @JUDGE_ID: 19899RK 314 C++ "By Anadan" */ 
// Robot
// Accepted (0.086 seconds with low memory spent)

#include <stdio.h>

char map[50][50];
int row, col, x1, y1, x2, y2, dir;
char mint[50][50][4];

const int dx[4] = { 1,  0, -1, 0 };
const int dy[4] = { 0, -1,  0, 1 };

int getmintime(){
	int i, j, k, que[10000], step = 0, count;

	for (i = 0; i < row; ++i) for (j = 0; j < col; ++j){
		for (k = 0; k < 4; ++k) mint[i][j][k] = 0;
	}

	mint[x1][y1][dir] = 1;
	que[0] = (x1 << 8) | (y1 << 2) | dir;

	i = 0; j = 1;
	while (i < j){
		count = 0;
		while (i < j){
			x1 = que[i] >> 8;
			y1 = (que[i] >> 2) & 63;
			dir = que[i] & 3;
			++i;

			if (x1 == x2 && y1 == y2) return step;
			dir = (dir + 1) & 3;

			if (!mint[x1][y1][dir]){
				mint[x1][y1][dir] = 1;
				que[j + count++] = (x1 << 8) | (y1 << 2) | dir;
			}

			if (!mint[x1][y1][dir ^ 2]){
				mint[x1][y1][dir ^ 2] = 1;
				que[j + count++] = (x1 << 8) | (y1 << 2) | (dir ^ 2);
			}

			dir = (dir + 3) & 3;
			for (k = 0; k < 3; ++k){
				x1 += dx[dir];
				y1 += dy[dir];
				if (x1 < 0 || x1 >= row - 1 || y1 < 0 || y1 >= col - 1) break;
				if (map[x1][y1] || map[x1 + 1][y1] || map[x1][y1 + 1] || map[x1 + 1][y1 + 1]) break;
				if (!mint[x1][y1][dir]){
					mint[x1][y1][dir] = 1;
					que[j + count++] = (x1 << 8) | (y1 << 2) | dir;
				}
			}
		}

		j += count;
		++step;
	}

	return -1;
}

int main(){
	int i, j, k;
	char str[10];

	while (scanf("%d%d", &row, &col) == 2 && (row || col)){
		for (i = 0; i < row; ++i) for (j = 0; j < col; ++j){
			while ((k = getchar()) != '0' && k != '1');
			map[i][j] = k - '0';
		}

		scanf("%d%d%d%d%s", &x1, &y1, &x2, &y2, str);
		--x1; --y1; --x2; --y2;
		if (str[0] == 's') dir = 0;
		else if (str[0] == 'w') dir = 1;
		else if (str[0] == 'n') dir = 2;
		else if (str[0] == 'e') dir = 3;

		printf("%d\n", getmintime());
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
