/* @JUDGE_ID: 19899RK 469 C++ "By Anadan" */
// Wetlands of Florida
// Accepted (0.170 seconds using as much as 868 kbytes)

#include <stdio.h>
#include <string.h>

char map[100][100];

int getwater(int i, int j){
	int res = 1;
	map[i][j] = 0;

	if (i){
		if (map[i-1][j] == 'W') res += getwater(i-1, j);
		if (map[i-1][j+1] == 'W') res += getwater(i-1, j+1);
		if (j && map[i-1][j-1] == 'W') res += getwater(i-1, j-1);
	}
	if (j && map[i][j-1] == 'W') res += getwater(i, j-1);
	if (map[i][j+1] == 'W') res += getwater(i, j+1);

	if (j && map[i+1][j-1] == 'W') res += getwater(i+1, j-1);
	if (map[i+1][j] == 'W') res += getwater(i+1, j);
	if (map[i+1][j+1] == 'W') res += getwater(i+1, j+1);

	return res;
}

int main(){
	long set;
	char origin[100][100];
	int index, c, row, col;
	scanf("%ld\n\n", &set);

	while (set--){
		index = 0;
		while (1){
			c = getchar();
			if (c == 'L' || c == 'W'){
				origin[index][0] = c;
				scanf("%s\n", origin[index] + 1);
				++index;
			}else{
				ungetc(c, stdin);
				break;
			}
		}

		while (scanf("%d %d\n", &row, &col) == 2){
			--row; --col;
			for (c = 0; c < index; c++) strcpy(map[c], origin[c]);
			memset(map[index], 0, 100);
			printf("%d\n", getwater(row, col));
		}

		if (set) printf("\n");
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */
