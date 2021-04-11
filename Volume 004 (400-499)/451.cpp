/* @JUDGE_ID: 19899RK 451 C++ "By Anadan" */ 
// Poker Solitaire Evaluator
// Accepted (0.357 seconds using as much as 388 kbytes)

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int hands[9];

int sort_function(const void *a, const void *b){
	if (*(char *)a < *(char *)b) return -1;
	return 1;
}

void getpokerhand(char curr[5][3]){
	int i;
	char straight = 0, flush = 0, three = 0;

	for (i = 1; i < 5; ++i) if (curr[i][1] != curr[0][1]) break;
	if (i == 5) flush = 1;
	for (i = 1; i < 5; ++i) if (curr[i][0] != curr[i - 1][0] + 1) break;
	if (i == 5) straight = 1;
	else{
		for (++i; i < 5; ++i) if (curr[i][0] != curr[i - 1][0] + 1) break;
		if (i == 5 && curr[0][0] == '2' && curr[4][0] == '9' + 5) straight = 1;
	}

	if (straight && flush) { ++hands[8]; return; }

	for (i = 1; i < 4; ++i) if (curr[i][0] != curr[0][0]) break;
	if (i == 4) { ++hands[7]; return; }
	for (i = 2; i < 5; ++i) if (curr[i][0] != curr[1][0]) break;
	if (i == 5) { ++hands[7]; return; }

	for (i = 1; i < 3; ++i) if (curr[i][0] != curr[0][0]) break;
	if (i == 3){
		three = 1;
		if (curr[3][0] == curr[4][0]) { ++hands[6]; return; }
	}
	for (i = 2; i < 4; ++i) if (curr[i][0] != curr[1][0]) break;
	if (i == 4) three = 1;
	for (i = 3; i < 5; ++i) if (curr[i][0] != curr[2][0]) break;
	if (i == 5){
		three = 1;
		if (curr[0][0] == curr[1][0]) { ++hands[6]; return; }
	}

	if (flush) { ++hands[5]; return; }
	if (straight) { ++hands[4]; return; }
	if (three) { ++hands[3]; return; }

	if ((curr[0][0] == curr[1][0] && (curr[2][0] == curr[3][0] || curr[3][0] == curr[4][0])) ||
	     curr[1][0] == curr[2][0] && curr[3][0] == curr[4][0])
	{
		++hands[2]; return;
	}

	for (i = 1; i < 5; ++i) if (curr[i][0] == curr[i - 1][0]) break;
	if (i < 5) { ++hands[1]; return; }

	++hands[0];
}

int main(){
	int set, i, j;
	char map[5][5][3], curr[5][3];

	scanf("%d\n\n", &set);
	while (set--){
		for (i = 0; i < 5; ++i) for (j = 0; j < 5; ++j){
			scanf("%s", &map[i][j]);
			if (map[i][j][0] == 'X') map[i][j][0] = '9' + 1;
			else if (map[i][j][0] == 'J') map[i][j][0] = '9' + 2;
			else if (map[i][j][0] == 'Q') map[i][j][0] = '9' + 3;
			else if (map[i][j][0] == 'K') map[i][j][0] = '9' + 4;
			else if (map[i][j][0] == 'A') map[i][j][0] = '9' + 5;
		}
		for (i = 0; i < 9; ++i) hands[i] = 0;

		for (i = 0; i < 5; ++i){
			for (j = 0; j < 5; ++j) strcpy(curr[j], map[i][j]);
			qsort(curr, 5, 3, sort_function);
			getpokerhand(curr);
			for (j = 0; j < 5; ++j) strcpy(curr[j], map[j][i]);
			qsort(curr, 5, 3, sort_function);
			getpokerhand(curr);
		}

		printf("%d", hands[0]);
		for (i = 1; i < 9; ++i) printf(", %d", hands[i]);
		putchar('\n');

		if (set) putchar('\n');
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
