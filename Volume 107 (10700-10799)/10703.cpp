/* @JUDGE_ID: 19899RK 10703 C++ "By Anadan" */
// Free spots
// Accepted (0.207 seconds using as much as 1368 kbytes)

#include <stdio.h>
#include <string.h>

int W, H, map[500][500];

void update(int x, int y){
	int right = map[x][y + 1];
	while (y >= 0 && map[x][y]) map[x][y--] = ++right;
}

void fill(int x, int y, int count){
	int i;
	if (map[x][y] >= count) return;
	for (i = 0; i < count; ++i){
		if (map[x][y + i] >= count - i){
			update(x, y + i - 1);
			return;
		}
		map[x][y + i] = count - i;
	}
	if (y + i < H && map[x][y + i]) update(x, y + i - 1);
}

int main(){
	int N, i, j, x1, y1, x2, y2, res;

	while (scanf("%d%d%d", &W, &H, &N) == 3 && W){
		memset(map, 0, sizeof(map));
		while (N--){
			scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
			--x1; --y1; --x2; --y2;
			if (x1 > x2) x1 ^= x2 ^= x1 ^= x2;
			if (y1 > y2) y1 ^= y2 ^= y1 ^= y2;
			for (i = x1; i <= x2; ++i){
				fill(i, y1, y2 - y1 + 1);
			}
		}

		res = 0;
		for (i = 0; i < W; ++i){
			for (j = 0; j < H; ++j) if (!map[i][j]) ++res;
		}

		if (res == 0) puts("There is no empty spots.");
		else if (res == 1) puts("There is one empty spot.");
		else printf("There are %d empty spots.\n", res);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
