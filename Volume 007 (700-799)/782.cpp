/* @JUDGE_ID: 19899RK 782 C++ "By Anadan" */ 
// Contour Painting
// Accepted (0.092 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

int rows, cols;
char map[32][85];

inline int alpha(int i, int j){
	return (map[i][j] != ' ' && map[i][j] != '#' && map[i][j]);
}

void fillzero(int i, int j){
	map[i][j] = 0;
	if (i && map[i - 1][j] && map[i - 1][j] == ' ') fillzero(i - 1, j);
	if (i < rows - 1 && map[i + 1][j] && map[i + 1][j] == ' ') fillzero(i + 1, j);
	if (j && map[i][j - 1] && map[i][j - 1] == ' ') fillzero(i, j - 1);
	if (j < cols - 1 && map[i][j + 1] && map[i][j + 1] == ' ') fillzero(i, j + 1);
}

int main(){
	int set, i, j;
	char *p;
	
	scanf("%d", &set); while (getchar() != '\n');
	while (set--){
		rows = cols = 0;
		while (gets(map[rows]) && map[rows][0] != '_'){
			i = strlen(map[rows]) + 1;
			if (cols < i) cols = i;
			++rows;
		}

		for (i = 0; i < rows; ++i){
			j = strlen(map[i]);
			while (j < cols) map[i][j++] = ' ';
			map[i][j] = 0;
		}

		for (i = 0; i < rows; ++i){
			if ((p = strchr(map[i], '*')) != NULL){
				j = int(p - map[i]);
				break;
			}
		}

		map[i][j] = ' ';
		fillzero(i, j);
		for (i = 0; i < rows; ++i){
			for (j = 0; j < cols; ++j){
				if (map[i][j]) continue;
				if ((i && alpha(i - 1, j)) || (j && alpha(i, j - 1)) || (i < rows - 1 && alpha(i + 1, j) || (j < cols - 1 && alpha(i, j + 1)))){
					map[i][j] = '#';
				}else map[i][j] = ' ';
			}
		}

		for (i = 0; i < rows; ++i){
			j = cols - 1;
			while (j >= 0 && map[i][j] == ' ') --j;
			map[i][j + 1] = 0;
			puts(map[i]);
		}
		puts(map[i]);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
