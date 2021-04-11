/* @JUDGE_ID: 19899RK 559 C++ "By Anadan" */
// Squares (II)
// Accepted (0.439 seconds using as much as 1380 kbytes)

#include <stdio.h>
#include <string.h>

char map[1000][1000];
int maxup[1000], maxsq[1000], tmp[1000], rows, cols, count;

void makemove(int r, int c){
	int i, j;

	++count;
	map[r][c] = 1;
	for (i = 1; r + i < rows && c + i < cols; ++i){
		for (j = 0; j < i; ++j) if (map[r + i][c + j]) break;
		if (j < i) break;
		for (j = 0; j <= i; ++j) if (map[r + j][c + i]) break;
		if (j <= i) break;
		for (j = 0; j < i; ++j) map[r + i][c + j] = 1;
		for (j = 0; j <= i; ++j) map[r + j][c + i] = 1;
		count += i + i + 1;
	}
}

void printmove(){
	int i, j, x, y, right, maxsz = 0;

	for (j = cols - 1; j >= 0; --j){
		maxup[j] = maxsq[j] = map[rows - 1][j] ^ 1;
		if (maxsz <= maxsq[j]){
			maxsz = maxsq[j];
			x = rows - 1; y = j;
		}
	}

	for (i = rows - 2; i >= 0; --i){
		right = 0;
		j = cols - 1;

		if (map[i][j]){
			right = maxup[j] = tmp[j] = 0;
		}else{
			++maxup[j];
			tmp[j] = ++right;
			if (tmp[j] > maxup[j]) tmp[j] = maxup[j];

			if (maxsz <= tmp[j]){
				maxsz = tmp[j];
				x = i; y = j;
			}
		}

		for (--j; j >= 0; --j){
			if (map[i][j]){
				right = maxup[j] = tmp[j] = 0;
				continue;
			}

			++maxup[j];
			tmp[j] = ++right;
			if (tmp[j] > maxup[j]) tmp[j] = maxup[j];
			if (tmp[j] > maxsq[j + 1] + 1) tmp[j] = maxsq[j + 1] + 1;

			if (maxsz <= tmp[j]){
				maxsz = tmp[j];
				x = i; y = j;
			}
		}

		memcpy(maxsq, tmp, sizeof(tmp));
	}

	printf("%d %d %d\n", x + 1, y + 1, maxsz);
}

int main(){
	int set, M, i, j;

	scanf("%d", &set);
	while (set--){
		scanf("%d%d%d", &rows, &cols, &M);
		memset(map, 0, sizeof(map));
		count = 0;
		while (M--){
			scanf("%d%d", &i, &j); --i; --j;
			makemove(i, j);
		}

		if (count == rows * cols) puts("game over");
		else printmove();
	}

	return 0;
}

/* @END_OF_SOURCE_CODE */
