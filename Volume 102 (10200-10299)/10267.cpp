/* @JUDGE_ID: 19899RK 10267 C++ "By Anadan" */ 
// Graphical Editor
// Accepted (0.047 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

int N, M;
char map[252][252], fillcolor, tofill;

void clear(){
	int i;

	for (i = 1; i <= N; ++i){
		memset(map[i] + 1, 'O', M);
		map[i][M + 1] = 0;
	}
	memset(map[i], 0, M + 2);
}

void fill(int x, int y){
	map[x][y] = tofill;
	if (map[x - 1][y] == fillcolor) fill(x - 1, y);
	if (map[x + 1][y] == fillcolor) fill(x + 1, y);
	if (map[x][y - 1] == fillcolor) fill(x, y - 1);
	if (map[x][y + 1] == fillcolor) fill(x, y + 1);
}

int main(){
	int i, j, x1, y1, x2, y2;
	char str[256], c[2], *p;

	for (i = 0; i < 252; ++i) map[0][i] = map[i][0] = 0;

	while (gets(str)){
		p = str;
		if (*p == 'I'){
			sscanf(p + 1, "%d%d\n", &M, &N);
			clear();
		}else if (*p == 'C'){
			clear();
		}else if (*p == 'L'){
			sscanf(p + 1, "%d%d%s", &i, &j, c);
			map[j][i] = c[0];
		}else if (*p == 'V'){
			sscanf(p + 1, "%d%d%d%s", &x1, &y1, &y2, c);
			if (y1 > y2) y1 ^= y2 ^= y1 ^= y2;
			for (j = y1; j <= y2; ++j) map[j][x1] = c[0];
		}else if (*p == 'H'){
			sscanf(p + 1, "%d%d%d%s", &x1, &x2, &y1, c);
			if (x1 > x2) x1 ^= x2 ^= x1 ^= x2;
			for (i = x1; i <= x2; ++i) map[y1][i] = c[0];
		}else if (*p == 'K'){
			sscanf(p + 1, "%d%d%d%d%s", &x1, &y1, &x2, &y2, c);
			if (x1 > x2) x1 ^= x2 ^= x1 ^= x2;
			if (y1 > y2) y1 ^= y2 ^= y1 ^= y2;
			for (j = y1; j <= y2; ++j) for (i = x1; i <= x2; ++i){
				map[j][i] = c[0];
			}
		}else if (*p == 'F'){
			sscanf(p + 1, "%d%d%s", &i, &j, c);
			if (map[j][i] == c[0]) continue;
			fillcolor = map[j][i];
			tofill = c[0];
			fill(j, i);
		}else if (*p == 'S'){
			++p;
			while (*p == ' ' || *p == '\t') ++p;
			printf("%s\n", p);
			for (j = 1; j <= N; ++j) printf("%s\n", map[j] + 1);
		}else if (*p == 'X') break;
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
