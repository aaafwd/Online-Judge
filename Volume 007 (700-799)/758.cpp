/* @JUDGE_ID: 19899RK 758 C++ "By Anadan" */ 
// The Same Game
// Accepted (0.904 seconds using as much as 392 kbytes)

#include <stdio.h>
#include <string.h>

int curr, score, move;
char map[12][17], ch;

void remove(int i, int j, char tmp[12][17]){
	tmp[i][j] = 0;
	++curr;
	if (tmp[i - 1][j] == ch) remove(i - 1, j, tmp);
	if (tmp[i + 1][j] == ch) remove(i + 1, j, tmp);
	if (tmp[i][j - 1] == ch) remove(i, j - 1, tmp);
	if (tmp[i][j + 1] == ch) remove(i, j + 1, tmp);
}

int trytoremove(){
	int i, j, max = -1, x, y;
	char tmp[12][17];

	memcpy(tmp, map, sizeof(map));

	for (j = 1; j <= 15; ++j){
		for (i = 10; i > 0; --i){
			if (tmp[i][j] != 0){
				curr = 0;
				ch = tmp[i][j];
				remove(i, j, tmp);
				if (max < curr){
					max = curr; x = i; y = j;
				}
			}
		}
	}

	if (max < 2) return -1;

	ch = map[x][y];
	remove(x, y, map);
	printf("Move %d at (%d,%d): removed %d balls of color %c, got %d points.\n", ++move, 11 - x, y, max, ch, (max - 2) * (max - 2));
	score += (max - 2) * (max - 2);

	for (j = 1; j <= 15; ++j){
		for (i = 2; i <= 10; ++i){
			if (map[i][j] == 0){
				for (x = i; x > 0; --x) map[x][j] = map[x - 1][j];
			}
		}
	}

	for (j = 14; j > 0; --j){
		if (map[10][j] == 0){
			for (i = j; i <= 15; ++i){
				for (x = 1; x <= 10; ++x){
					map[x][i] = map[x][i + 1];
				}
			}
		}
	}

	return max;
}

int main(){
	int mset, set, game, remain, i, j, k;

	for (i = 0; i < 17; ++i) map[0][i] = map[i][0] = map[11][i] = 0;

	scanf("%d\n", &mset);
	while (mset--){
		game = 0;
		scanf("%d\n", &set);
		while (set--){
			for (i = 1; i <= 10; ++i) scanf("%s\n", map[i] + 1);

			printf("Game %d:\n\n", ++game);
			move = score = 0;
			remain = 150;

			while (1){
				k = trytoremove();
				if (k == -1) break;
				remain -= k;
			}
			if (remain == 0) score += 1000;
			printf("Final score: %d, with %d balls remaining.\n", score, remain);

			if (set) putchar('\n');
		}

		if (mset) putchar('\n');
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
