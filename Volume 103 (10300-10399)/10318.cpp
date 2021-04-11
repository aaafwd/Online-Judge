/* @JUDGE_ID: 19899RK 10318 C++ "By Anadan" */
// Security Panel
// Accepted (0.008 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

int rows, cols, best, b_nums[25], nums[25];
char toggle[3][4], curr[5][5];

void doxor(int r, int c){
	int i, j, x, y;

	for (i = 0; i < 3; ++i){
		x = r - 1 + i;
		if (x < 0 || x >= rows) continue;
		for (j = 0; j < 3; ++j){
			y = c - 1 + j;
			if (y < 0 || y >= cols) continue;
			if (toggle[i][j] == '*') curr[x][y] ^= 1;
		}
	}
}

void generate(int r, int c, int sp){
	int i, j, flag;

	if (sp >= best) return;
	if (c >= cols) { ++r; c = 0; }

	if (r >= rows){
		best = sp;
		for (i = 0; i < sp; ++i) b_nums[i] = nums[i];
		return;
	}

	flag = 1;
	if (r){
		if (c && curr[r - 1][c - 1] == 0) flag = 0;
		else if (c == cols - 1 && curr[r - 1][c] == 0) flag = 0;
	}
	if (r == rows - 1){
		if (c && curr[r][c - 1] == 0) flag = 0;
		else if (c == cols - 1 && curr[r][c] == 0) flag = 0;
	}
	if (flag) generate(r, c + 1, sp);

	doxor(r, c);
	flag = 1;
	if (r){
		if (c && curr[r - 1][c - 1] == 0) flag = 0;
		else if (c == cols - 1 && curr[r - 1][c] == 0) flag = 0;
	}
	if (r == rows - 1){
		if (c && curr[r][c - 1] == 0) flag = 0;
		else if (c == cols - 1 && curr[r][c] == 0) flag = 0;
	}
	if (flag){
		nums[sp] = r * cols + c + 1;
		generate(r, c + 1, sp + 1);
	}

	doxor(r, c);
}

int main(){
	int set = 0, i;

	while (scanf("%d%d", &rows, &cols) == 2 && rows){
		for (i = 0; i < 3; ++i) scanf("%s", toggle[i]);

		best = 100;
		memset(curr, 0, sizeof(curr));
		generate(0, 0, 0);

		printf("Case #%d\n", ++set);
		if (best == 100) puts("Impossible.");
		else{
			printf("%d", b_nums[0]);
			for (i = 1; i < best; ++i) printf(" %d", b_nums[i]);
			putchar('\n');
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
