/* @JUDGE_ID: 19899RK 10363 C++ "By Anadan" */ 
// Tic Tac Toe
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>

char map[3][4];

int getw(char c){
	int i;

	for (i = 0; i < 3; ++i){
		if (map[i][0] == c && map[i][1] == c && map[i][2] == c) return 1;
		if (map[0][i] == c && map[1][i] == c && map[2][i] == c) return 1;
	}

	if (map[0][0] == c && map[1][1] == c && map[2][2] == c) return 1;
	if (map[0][2] == c && map[1][1] == c && map[2][0] == c) return 1;

	return 0;
}

int main(){
	int set, i, j, x, o;

	scanf("%d\n", &set);
	while (set--){
		scanf("%s\n", map[0]);
		scanf("%s\n", map[1]);
		scanf("%s\n\n", map[2]);

		x = o = 0;
		for (i = 0; i < 3; ++i){
			for (j = 0; j < 3; ++j){
				if (map[i][j] == 'X') ++x;
				else if (map[i][j] == 'O') ++o;
			}
		}

		if (x != o && x != o + 1) printf("no\n");
		else{
			if (x == o) i = 1; else i = 0;
			if (getw('X')){
				if (x == o || getw('O')) printf("no\n");
				else printf("yes\n");
			}else if (getw('O')){
				if (x != o) printf("no\n");
				else printf("yes\n");
			}else printf("yes\n");
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
