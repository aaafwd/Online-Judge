/* @JUDGE_ID: 19899RK 707 C++ "By Anadan" */ 
// Robbery
// Accepted (0.453 seconds using as much as 1368 kbytes)

#include <stdio.h>
#include <string.h>

int W, H, T, escape;
char map[100][100][100];

inline int reachable(int t, int i, int j){
	if (map[t][i][j]) return 1;
	if (i && map[t][i - 1][j]) return 1;
	if (i < H - 1 && map[t][i + 1][j]) return 1;
	if (j && map[t][i][j - 1]) return 1;
	if (j < W - 1 && map[t][i][j + 1]) return 1;
	return 0;
}

void wave(){
	int changes, flag, t, i, j, tmp;

	for (t = 0; t < T; ++t){
		flag = 0;
		changes = 0;
		for (i = 0; i < H; ++i){
			for (j = 0; j < W; ++j){
				if (map[t][i][j]){
					tmp = 1;
					if (t < T - 1 && !reachable(t + 1, i, j)) tmp = 0;
					else if (t && !reachable(t - 1, i, j)) tmp = 0;

					if (tmp) flag = 1;
					else{
						map[t][i][j] = 0;
						changes = 1;
					}
				}
			}
		}

		if (flag == 0){
			escape = 1;
			break;
		}

		if (changes && t) t -= 2;
	}
}

int main(){
	int set = 0, N, t, left, top, right, bottom, i, j, k, count;

	while (scanf("%d%d%d", &W, &H, &T) == 3 && W){
		for (i = 0; i < T; ++i) for (j = 0; j < H; ++j){
			memset(map[i][j], 1, W);
		}

		scanf("%d", &N);
		while (N--){
			scanf("%d%d%d%d%d", &t, &left, &top, &right, &bottom);
			--t;
			for (i = top - 1; i < bottom; ++i){
				for (j = left - 1; j < right; ++j){
					map[t][i][j] = 0;
				}
			}
		}

		escape = 0;
		wave();

		printf("Robbery #%d:\n", ++set);
		if (escape) puts("The robber has escaped.");
		else{
			left = 0;
			for (t = 0; t < T; ++t){
				count = 0;
				for (i = 0; i < H; ++i) for (j = 0; j < W; ++j){
					if (map[t][i][j]){
						++count;
						k = (i << 10) + j;
					}
				}

				if (count == 1){
					left = 1;
					printf("Time step %d: The robber has been at %d,%d.\n", t + 1, (k & 1023) + 1, (k >> 10) + 1);
				}
			}

			if (left == 0) puts("Nothing known.");
		}

		putchar('\n');
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
