/* @JUDGE_ID: 19899RK 215 C++ "By Anadan" */ 
// Spreadsheet Calculator
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>

struct Cell{
	char str[80];
	int value, flag;
}map[20][10];
int row, col, isgood;

void calc(int i, int j){
	int res = 0, cur = 0, sgn = 0;
	char *p = map[i][j].str;

	map[i][j].flag = -1;

	while (*p){
		if (*p == '-'){
			if (sgn) res -= cur; else res += cur;
			cur = 0;
			++p;
			sgn = 1;

		}else if (*p == '+'){
			if (sgn) res -= cur; else res += cur;
			cur = 0;
			++p;
			sgn = 0;

		}else if ('0' <= *p && *p <= '9'){
			cur = *p++ - '0';
			while ('0' <= *p && *p <= '9'){
				cur = 10 * cur + *p++ - '0';
			}

		}else{
			int a = *p++ - 'A';
			int b = *p++ - '0';

			if (map[a][b].flag == 0) calc(a, b);
			if (map[a][b].flag != 1){
				isgood = 0;
				return;
			}

			cur = map[a][b].value;
		}
	}

	if (sgn) res -= cur; else res += cur;
	map[i][j].flag = 1;
	map[i][j].value = res;
}

int main(){
	int i, j;

	while (scanf("%d%d", &row, &col) == 2 && (row || col)){
		isgood = 1;
		for (i = 0; i < row; ++i){
			for (j = 0; j < col; ++j){
				scanf("%s", map[i][j].str);
				map[i][j].flag = 0;
			}
		}

		for (i = 0; i < row; ++i) for (j = 0; j < col; ++j){
			if (map[i][j].flag == 0) calc(i, j);
		}

		if (isgood){
			putchar(' ');
			for (i = 0; i < col; ++i) printf("%6d", i);
			putchar('\n');

			for (i = 0; i < row; ++i){
				putchar('A' + i);
				for (j = 0; j < col; ++j) printf("%6d", map[i][j].value);
				putchar('\n');
			}
		}else{
			for (i = 0; i < row; ++i) for (j = 0; j < col; ++j){
				if (map[i][j].flag == -1){
					printf("%c%d: %s\n", 'A' + i, j, map[i][j].str);
				}
			}
		}

		putchar('\n');
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
