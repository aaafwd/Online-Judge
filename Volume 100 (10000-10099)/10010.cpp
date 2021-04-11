/* @JUDGE_ID: 19899RK 10010 C++ "By Anadan" */
// Where's Waldorf?
// Accepted (0.010 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

int m, n, len;
char map[50][51];
char word[51];

void _strlwr(char *s){
	for (; *s; s++) if (('A' <= *s) && (*s <= 'Z')) *s += 'a' - 'A';
}

int findword(int row, int col){
	int i, r, c;

	if (word[0] != map[row][col]) return 0;
	if (n - col >= len){
		for (i = 0; i < len; i++) if (word[i] != map[row][col + i]) break;
		if (i == len) return 1;
	}

	if (col >= len - 1){
		for (i = 0; i < len; i++) if (word[i] != map[row][col - i]) break;
		if (i == len) return 1;
	}

	if (m - row >= len){
		for (i = 0; i < len; i++) if (word[i] != map[row + i][col]) break;
		if (i == len) return 1;
	}

	if (row >= len - 1){
		for (i = 0; i < len; i++) if (word[i] != map[row - i][col]) break;
		if (i == len) return 1;
	}

	for (r = row, c = col, i = 0; r >= 0 && c >= 0 && i < len; i++, r--, c--)
		if (word[i] != map[r][c]) break;
	if (i == len) return 1;

	for (r = row, c = col, i = 0; r >= 0 && c < n && i < len; i++, r--, c++)
		if (word[i] != map[r][c]) break;
	if (i == len) return 1;

	for (r = row, c = col, i = 0; r < m && c >= 0 && i < len; i++, r++, c--)
		if (word[i] != map[r][c]) break;
	if (i == len) return 1;

	for (r = row, c = col, i = 0; r < m && c < n && i < len; i++, r++, c++)
		if (word[i] != map[r][c]) break;
	if (i == len) return 1;

	return 0;
}

int main(){
	int set, i, x, y;
	scanf("%d\n\n", &set);

	while(set--){
		scanf("%d%d\n", &m, &n);
		for (i = 0; i < m; i++){
			scanf("%s\n", map[i]);
			_strlwr(map[i]);
		}
		scanf("%d\n", &i);
		while (i--){
			scanf("%s\n", word);
			_strlwr(word);
			len = strlen(word);
			for (x = 0; x < m; x++) for (y = 0; y < n; y++){
				if (findword(x, y)){
					printf("%d %d\n", x + 1, y + 1);
					x = m;
					break;
				}
			}
		}
		if (set) putchar('\n');
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
