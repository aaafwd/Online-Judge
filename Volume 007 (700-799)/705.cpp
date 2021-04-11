/* @JUDGE_ID: 19899RK 705 C++ "By Anadan" */ 
// Slash Maze
// Accepted (0.012 seconds using as much as 480 kbytes)

#include <stdio.h>
#include <string.h>

int w, h, curr, cycleflag;
char map[75][76], mask[150][76];

void getcycle(int i, int j){
	int border = 0;

	if (i < 0 || j < 0 || i + 1 >= h + h || j >= w - 1 + (i & 1)){
		cycleflag = 0;
		return;
	}

	if (mask[i][j]) return;

	++curr;
	mask[i][j] = 1;
	if (i & 1){
		if (map[i / 2][j] == '/') border |= 8; else border |= 1;
		if (map[i / 2 + 1][j] == '/') border |= 2; else border |= 4;
	}else{
		if (map[i / 2][j] == '/') border |= 8; else border |= 4;
		if (map[i / 2][j + 1] == '/') border |= 2; else border |= 1;
	}

	if (!(border & 1)) getcycle(i - 1, j + 1 - (i & 1));
	if (!(border & 2)) getcycle(i + 1, j + 1 - (i & 1));
	if (!(border & 4)) getcycle(i + 1, j - (i & 1));
	if (!(border & 8)) getcycle(i - 1, j - (i & 1));
}

int main(){
	int set = 0, i, j, max, cycles;

	while (scanf("%d%d\n", &w, &h) == 2 && w){
		for (i = 0; i < h; ++i){
			scanf("%s\n", map[i]);
			memset(mask[i], 0, w);
			memset(mask[h + i], 0, w);
		}

		cycles = max = 0;
		for (i = 0; i < h + h - 1; ++i){
			for (j = 0; j < w; ++j){
				if (mask[i][j]) continue;
				curr = 0; cycleflag = 1;
				getcycle(i, j);
				if (cycleflag){
					++cycles;
					if (max < curr) max = curr;
				}
			}
		}

		printf("Maze #%d:\n", ++set);
		if (cycles) printf("%d Cycles; the longest has length %d.\n\n", cycles, max);
		else printf("There are no cycles.\n\n");
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
