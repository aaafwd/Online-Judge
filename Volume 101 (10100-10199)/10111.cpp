/* @JUDGE_ID: 19899RK 10111 C++ "By Anadan" */
// Find the Winning Move
// Accepted (0.092 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

char map[4][5], cur[4][5];
char win[531441];

int iswin(int r, int c, int step){
	int i, j, k = 0;

	cur[r][c] = (step == 0 ? 'x' : 'o');
	for (i = 0; i < 4; ++i){
		for (j = 0; j < 4; ++j){
			if (map[i][j] != '.') continue;
			k *= 3;
			if (cur[i][j] == 'x') ++k;
			else if (cur[i][j] == 'o') k += 2;
		}
	}

	if (win[k] != -1) goto exit;

	for (i = 0; i < 4; ++i){
		for (j = 1; j < 4; ++j) if (cur[i][j] != cur[i][0]) break;
		if (j == 4 && cur[i][0] != '.'){
			win[k] = 1;
			goto exit;
		}

		for (j = 1; j < 4; ++j) if (cur[j][i] != cur[0][i]) break;
		if (j == 4 && cur[0][i] != '.'){
			win[k] = 1;
			goto exit;
		}
	}

	for (i = 1; i < 4; ++i) if (cur[i][i] != cur[0][0]) break;
	if (i == 4 && cur[0][0] != '.'){
		win[k] = 1;
		goto exit;
	}

	for (i = 1; i < 4; ++i) if (cur[i][3 - i] != cur[0][3]) break;
	if (i == 4 && cur[0][3] != '.'){
		win[k] = 1;
		goto exit;
	}
	
	for (i = 0; i < 4; ++i){
		for (j = 0; j < 4; ++j){
			if (cur[i][j] == '.' && iswin(i, j, step ^ 1)){
				win[k] = 0;
				goto exit;
			}
		}
	}

	win[k] = 1;

exit:	cur[r][c] = '.';
	return win[k];
}

int main(){
	int i, j, k;
	char str[2];

	while (scanf("%s", str) == 1 && str[0] != '$'){
		for (k = 1, i = 0; i < 4; ++i){
			scanf("%s", map[i]);
			for (j = 0; j < 4; ++j) if (map[i][j] == '.') k *= 3;
		}
		memset(win, -1, k);

		for (i = 0; i < 4; ++i){
			for (j = 0; j < 4; ++j){
				if (map[i][j] == '.'){
					memcpy(cur, map, sizeof(map));
					if (iswin(i, j, 0)){
						printf("(%d,%d)\n", i, j);
						break;
					}
				}
			}

			if (j < 4) break;
		}

		if (i == 4) puts("#####");
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
