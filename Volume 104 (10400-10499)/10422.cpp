/* @JUDGE_ID: 19899RK 10422 C++ "By Anadan" */ 
// Knights in FEN
// Accepted (0.313 seconds using as much as 388 kbytes)

#include <stdio.h>

int best;
char map[5][6];

void generate(int i, int j, int px, int py, int n){
	int x, y;
	if (n >= best) return;

	if (i == 2 && j == 2){
		for (x = 1; x < 5; ++x){
			for (y = 0; y < x; ++y) if (map[x][y] != '0') break;
			if (y < x) break;
		}
		if (x == 5 && map[3][3] == '0' && map[4][4] == '0'){
			best = n;
			return;
		}
	}

	x = i - 2; y = j - 1;
	if (0 <= x && x < 5 && 0 <= y && y < 5 && (x != px || y != py)){
		map[i][j] = map[x][y]; map[x][y] = ' ';
		generate(x, y, i, j, n + 1);
		map[x][y] = map[i][j]; map[i][j] = ' ';
	}
	x = i - 2; y = j + 1;
	if (0 <= x && x < 5 && 0 <= y && y < 5 && (x != px || y != py)){
		map[i][j] = map[x][y]; map[x][y] = ' ';
		generate(x, y, i, j, n + 1);
		map[x][y] = map[i][j]; map[i][j] = ' ';
	}
	x = i + 2; y = j - 1;
	if (0 <= x && x < 5 && 0 <= y && y < 5 && (x != px || y != py)){
		map[i][j] = map[x][y]; map[x][y] = ' ';
		generate(x, y, i, j, n + 1);
		map[x][y] = map[i][j]; map[i][j] = ' ';
	}
	x = i + 2; y = j + 1;
	if (0 <= x && x < 5 && 0 <= y && y < 5 && (x != px || y != py)){
		map[i][j] = map[x][y]; map[x][y] = ' ';
		generate(x, y, i, j, n + 1);
		map[x][y] = map[i][j]; map[i][j] = ' ';
	}
	x = i - 1; y = j - 2;
	if (0 <= x && x < 5 && 0 <= y && y < 5 && (x != px || y != py)){
		map[i][j] = map[x][y]; map[x][y] = ' ';
		generate(x, y, i, j, n + 1);
		map[x][y] = map[i][j]; map[i][j] = ' ';
	}
	x = i - 1; y = j + 2;
	if (0 <= x && x < 5 && 0 <= y && y < 5 && (x != px || y != py)){
		map[i][j] = map[x][y]; map[x][y] = ' ';
		generate(x, y, i, j, n + 1);
		map[x][y] = map[i][j]; map[i][j] = ' ';
	}
	x = i + 1; y = j - 2;
	if (0 <= x && x < 5 && 0 <= y && y < 5 && (x != px || y != py)){
		map[i][j] = map[x][y]; map[x][y] = ' ';
		generate(x, y, i, j, n + 1);
		map[x][y] = map[i][j]; map[i][j] = ' ';
	}
	x = i + 1; y = j + 2;
	if (0 <= x && x < 5 && 0 <= y && y < 5 && (x != px || y != py)){
		map[i][j] = map[x][y]; map[x][y] = ' ';
		generate(x, y, i, j, n + 1);
		map[x][y] = map[i][j]; map[i][j] = ' ';
	}
}

int main(){
	int set, i, j, x, y;

	scanf("%d", &set); gets(map[0]);
	while (set--){
		for (i = 0; i < 5; ++i){
			gets(map[i]);
			for (j = 0; j < 5; ++j) if (map[i][j] == ' ')
				{ x = i; y = j; }
		}

		best = 11;
		generate(x, y, -1, -1, 0);
		if (best < 11) printf("Solvable in %d move(s).\n", best);
		else printf("Unsolvable in less than 11 move(s).\n");
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
