/* @JUDGE_ID: 19899RK 852 C++ "By Anadan" */ 
// Deciding victory in Go
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>

int pl, total;
char map[11][11];

void getscore(int i, int j){
	map[i][j] = 0;
	++total;

	if (pl != -2){
		if (map[i - 1][j] == 'X' || map[i + 1][j] == 'X' || map[i][j - 1] == 'X' || map[i][j + 1] == 'X'){
			if (pl != 1) pl = 0; else pl = -2;
		}
		if (map[i - 1][j] == 'O' || map[i + 1][j] == 'O' || map[i][j - 1] == 'O' || map[i][j + 1] == 'O'){
			if (pl != 0) pl = 1; else pl = -2;
		}
	}

	if (map[i - 1][j] == '.') getscore(i - 1, j);
	if (map[i + 1][j] == '.') getscore(i + 1, j);
	if (map[i][j - 1] == '.') getscore(i, j - 1);
	if (map[i][j + 1] == '.') getscore(i, j + 1);
}

int main(){
	int set, i, j, score[2];

	for (i = 0; i < 11; ++i) map[0][i] = map[i][0] = map[10][i] = 0;

	scanf("%d\n\n", &set);
	while (set--){
		for (i = 1; i <= 9; ++i) scanf("%s\n", map[i] + 1);
		score[0] = score[1] = 0;

		for (i = 1; i <= 9; ++i){
			for (j = 1; j <= 9; ++j){
				if (map[i][j] == 'X') ++score[0];
				else if (map[i][j] == 'O') ++score[1];
				else if (map[i][j] == '.'){
					pl = -1;
					total = 0;
					getscore(i, j);
					if (pl >= 0) score[pl] += total;
				}
			}
		}

		printf("Black %d White %d\n", score[0], score[1]);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
