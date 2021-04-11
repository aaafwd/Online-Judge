/* @JUDGE_ID: 19899RK 784 C++ "By Anadan" */
// Maze Exploration
// Accepted (0.061 seconds using as much as 388 kbytes)

#include <stdio.h>
#include <string.h>

char map[31][81];

void mark(int x, int y){
	map[x][y] = '#';
	if (map[x - 1][y] == ' ') mark(x - 1, y);
	if (map[x + 1][y] == ' ') mark(x + 1, y);
	if (map[x][y - 1] == ' ') mark(x, y - 1);
	if (map[x][y + 1] == ' ') mark(x, y + 1);
}

int main(){
	int set, N, i, j;
	char *p;

	scanf("%d\n", &set);
	while (set--){
		N = 0;
		i = -1;
		while (gets(map[N]) && map[N][0] != '_'){
			if (i == -1 && (p = strchr(map[N], '*')) != NULL){
				i = N; j = int(p - map[N]);
			}
			++N;
		}

		if (i != -1) mark(i, j);
		for (i = 0; i <= N; ++i) printf("%s\n", map[i]);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
