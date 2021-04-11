/* @JUDGE_ID: 19899RK 422 C++ "By Anadan" */
// Word-Search Wonder
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

int l, len;
char map[100][101];
char word[101];

int findword(int row, int col){
	int i, r, c;

	if (word[0] != map[row][col]) return 0;
	if (l - col >= len){
		for (i = 0; i < len; i++) if (word[i] != map[row][col + i]) break;
		if (i == len){
			printf("%d,%d %d,%d\n", row + 1, col + 1, row + 1, col + len);
			return 1;
		}
	}

	if (col >= len - 1){
		for (i = 0; i < len; i++) if (word[i] != map[row][col - i]) break;
		if (i == len){
			printf("%d,%d %d,%d\n", row + 1, col + 1, row + 1, col + 2 - len);
			return 1;
		}
	}

	if (l - row >= len){
		for (i = 0; i < len; i++) if (word[i] != map[row + i][col]) break;
		if (i == len){
			printf("%d,%d %d,%d\n", row + 1, col + 1, row + len, col + 1);
			return 1;
		}
	}

	if (row >= len - 1){
		for (i = 0; i < len; i++) if (word[i] != map[row - i][col]) break;
		if (i == len){
			printf("%d,%d %d,%d\n", row + 1, col + 1, row + 2 - len, col + 1);
			return 1;
		}
	}

	for (r = row, c = col, i = 0; r >= 0 && c >= 0 && i < len; i++, r--, c--)
		if (word[i] != map[r][c]) break;
	if (i == len){
		printf("%d,%d %d,%d\n", row + 1, col + 1, row + 2 - len, col + 2 - len);
		return 1;
	}

	for (r = row, c = col, i = 0; r >= 0 && c < l && i < len; i++, r--, c++)
		if (word[i] != map[r][c]) break;
	if (i == len){
		printf("%d,%d %d,%d\n", row + 1, col + 1, row + 2 - len, col + len);
		return 1;
	}

	for (r = row, c = col, i = 0; r < l && c >= 0 && i < len; i++, r++, c--)
		if (word[i] != map[r][c]) break;
	if (i == len){
		printf("%d,%d %d,%d\n", row + 1, col + 1, row + len, col + 2 - len);
		return 1;
	}

	for (r = row, c = col, i = 0; r < l && c < l && i < len; i++, r++, c++)
		if (word[i] != map[r][c]) break;
	if (i == len){
		printf("%d,%d %d,%d\n", row + 1, col + 1, row + len, col + len);
		return 1;
	}

	return 0;
}

int main(){
	int i, x, y;
	scanf("%d\n", &l);
	for (i = 0; i < l; ++i) scanf("%s\n", map[i]);

	while (scanf("%s\n", word) > 0){
		if (word[0] == '0') break;
		len = strlen(word);
		for (x = 0; x < l; x++) for (y = 0; y < l; y++){
			if (findword(x, y)) goto next_word;
		}
		printf("Not found\n");
		next_word: continue;
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
