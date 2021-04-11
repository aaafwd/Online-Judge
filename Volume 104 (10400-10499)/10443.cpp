/* @JUDGE_ID: 19899RK 10443 C++ "By Anadan" */ 
// Rock, Scissors, Paper
// Accepted (3.809 seconds using as much as 404 kbytes)

#include <stdio.h>
#include <string.h>

int r, c;
char map1[100][101], map2[100][101];

void wagewar(int i, int j, int x, int y){
	if (x < 0 || x == r || y < 0 || y == c) return;
	if (map1[i][j] == 'R' && map1[x][y] == 'S') map2[x][y] = 'R';
	if (map1[i][j] == 'S' && map1[x][y] == 'P') map2[x][y] = 'S';
	if (map1[i][j] == 'P' && map1[x][y] == 'R') map2[x][y] = 'P';
}

int main(){
	int set, i, j, N;

	scanf("%d\n", &set);
	while (set--){
		scanf("%d%d%d\n", &r, &c, &N);
		for (i = 0; i < r; ++i) scanf("%s\n", map1[i]);

		while (N--){
			memcpy(map2, map1, sizeof(map1));
			for (i = 0; i < r; ++i){
				for (j = 0; j < c; ++j){
					wagewar(i, j, i - 1, j);
					wagewar(i, j, i + 1, j);
					wagewar(i, j, i, j - 1);
					wagewar(i, j, i, j + 1);
				}
			}
			memcpy(map1, map2, sizeof(map1));
		}

		for (i = 0; i < r; ++i) printf("%s\n", map1[i]);
		if (set) putchar('\n');
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
