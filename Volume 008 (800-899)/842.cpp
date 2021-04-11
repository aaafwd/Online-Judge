/* @JUDGE_ID: 19899RK 842 C++ "By Anadan" */ 
// Crossword Puzzles
// Accepted (0.006 seconds with low memory spent)

#include <stdio.h>
#include <string.h>
#define SZ 100

int solves, N, lens[SZ];
char dict[SZ][11], map[11][11];

int seth(int r, int c, int len, int k){
	int i = 0;

	while (len--){
		if (map[r][c] == '.' || map[r][c] == dict[k][i]){
			map[r][c] = dict[k][i];
		}else return 0;
		++c; ++i;
	}

	return 1;
}

int setv(int r, int c, int len, int k){
	int i = 0;

	while (len--){
		if (map[r][c] == '.' || map[r][c] == dict[k][i]){
			map[r][c] = dict[k][i];
		}else return 0;
		++r; ++i;
	}

	return 1;
}

void countsolves(int r, int c){
	int i, j, k, m;
	char tmp[11][11];

	if (c >= 10) { ++r; c = 0; }

	for (; r < 10; ++r){
		for (; c < 10; ++c){
			if (map[r][c] == '#') continue;
			i = j = 1;
			if (c == 0 || map[r][c - 1] == '#') while (map[r][c + i] != '#') ++i;
			if (r == 0 || map[r - 1][c] == '#') while (map[r + j][c] != '#') ++j;
			if (i != 1 || j != 1) break;
		}
		if (c < 10) break;
		c = 0;
	}

	if (r >= 10){
		++solves;
		return;
	}

	if (i != 1 && j != 1){
		for (k = 0; k < N; ++k){
			if (lens[k] != i) continue;
			for (m = 0; m < N; ++m){
				if (lens[m] != j || dict[m][0] != dict[k][0] || (map[r][c] != '.' && map[r][c] != dict[k][0])) continue;
				memcpy(tmp, map, sizeof(map));
				if (seth(r, c, i, k) && setv(r, c, j, m)){
					countsolves(r, c + 1);
				}
				memcpy(map, tmp, sizeof(map));
			}
		}
	}else if (i != 1){
		for (k = 0; k < N; ++k){
			if (lens[k] != i || (map[r][c] != '.' && map[r][c] != dict[k][0])) continue;
			memcpy(tmp, map, sizeof(map));
			if (seth(r, c, i, k)){
				countsolves(r, c + 1);
			}
			memcpy(map, tmp, sizeof(map));
		}
	}else if (j != 1){
		for (m = 0; m < N; ++m){
			if (lens[m] != j || (map[r][c] != '.' && map[r][c] != dict[m][0])) continue;
			memcpy(tmp, map, sizeof(map));
			if (setv(r, c, j, m)){
				countsolves(r, c + 1);
			}
			memcpy(map, tmp, sizeof(map));
		}
	}
}

int main(){
	int set, i;
	char str[256], *p;

	for (i = 0; i < 11; ++i) map[10][i] = '#';

	scanf("%d\n\n", &set);
	while (set--){
		for (i = 0; i < 10; ++i){
			gets(map[i]);
			map[i][10] = '#';
		}

		N = 0;
		while (gets(str) && str[0]){
			p = strtok(str, " \t");
			while (p){
				for (i = 0; i < N; ++i) if (strcmp(dict[i], p) == 0) break;
				if (i == N){
					strcpy(dict[N], p);
					lens[N++] = strlen(p);
				}
				p = strtok(NULL, " \t");
			}
		}

		solves = 0;
		countsolves(0, 0);

		printf("%d\n", solves);

		if (set) putchar('\n');
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
