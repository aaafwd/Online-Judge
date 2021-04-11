/* @JUDGE_ID: 19899RK 10024 C++ "By Anadan" */ 
// Curling up the cube
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>

char side[6];
int map[8][8];

const int left[6][6] = {
	{ -1, 3, 1, 4, 2, -1 },
	{ 2, -1, 5, 0, -1, 3 },
	{ 4, 0, -1, -1, 5, 1 },
	{ 1, 5, -1, -1, 0, 4 },
	{ 3, -1, 0, 5, -1, 2 },
	{ -1, 2, 4, 1, 3, -1 }
};

void roll(int i, int j, int a, int b){
	map[i][j] = 0;
	side[b] = 1;
	if (map[i - 1][j]) roll(i - 1, j, b, 5 - a);
	if (map[i + 1][j]) roll(i + 1, j, 5 - b, a);
	if (map[i][j - 1]) roll(i, j - 1, a, left[a][b]);
	if (map[i][j + 1]) roll(i, j + 1, a, 5 - left[a][b]);
}

int main(){
	int set, i, j, k;

	for (i = 0; i < 8; ++i) map[0][i] = map[i][0] = map[7][i] = map[i][7] = 0;

	scanf("%d\n\n", &set);
	while (set--){
		for (i = 0; i < 6; ++i) side[i] = 0;
		for (i = 1; i <= 6; ++i) for (j = 1; j <= 6; ++j){
			while ((k = getchar()) != '0' && k != '1');
			map[i][j] = k - '0';
		}

		for (i = 1; i <= 6; ++i){
			for (j = 1; j <= 6; ++j){
				if (map[i][j]) break;
			}
			if (j <= 6) break;
		}

		roll(i, j, 0, 1);

		for (i = 0; i < 6; ++i) if (side[i] == 0) break;
		puts((i < 6) ? ("incorrect") : ("correct"));

//**/		if (set) putchar('\n');
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
