/* @JUDGE_ID: 19899RK 220 C++ "By Anadan" */ 
// Othello
// Accepted (0.002 seconds with low memory spent)

#include <stdio.h>

int c;
char map[10][10];
const char pl[3] = "WB";

int legal(int i, int j){
	int k;

	if (map[i][j] != '-') return 0;
	for (k = 1; map[i - k][j - k] == pl[c ^ 1]; ++k);
	if (k > 1 && map[i - k][j - k] == pl[c]) return 1;
	for (k = 1; map[i - k][j + k] == pl[c ^ 1]; ++k);
	if (k > 1 && map[i - k][j + k] == pl[c]) return 1;
	for (k = 1; map[i + k][j + k] == pl[c ^ 1]; ++k);
	if (k > 1 && map[i + k][j + k] == pl[c]) return 1;
	for (k = 1; map[i + k][j - k] == pl[c ^ 1]; ++k);
	if (k > 1 && map[i + k][j - k] == pl[c]) return 1;
	for (k = 1; map[i][j - k] == pl[c ^ 1]; ++k);
	if (k > 1 && map[i][j - k] == pl[c]) return 1;
	for (k = 1; map[i][j + k] == pl[c ^ 1]; ++k);
	if (k > 1 && map[i][j + k] == pl[c]) return 1;
	for (k = 1; map[i - k][j] == pl[c ^ 1]; ++k);
	if (k > 1 && map[i - k][j] == pl[c]) return 1;
	for (k = 1; map[i + k][j] == pl[c ^ 1]; ++k);
	if (k > 1 && map[i + k][j] == pl[c]) return 1;

	return 0;
}

void dolist(){
	int i, j, count = 0;

	for (i = 1; i <= 8; ++i){
		for (j = 1; j <= 8; ++j){
			if (legal(i, j)){
				if (count) putchar(' '); else count = 1;
				printf("(%d,%d)", i, j);
			}
		}
	}

	if (!count) printf("No legal move.\n"); else putchar('\n');
}

void move(int i, int j){
	int b = 0, w = 0, k;
	if (!legal(i, j)) c ^= 1;
	map[i][j] = pl[c];

	for (k = 1; map[i - k][j - k] == pl[c ^ 1]; ++k);
	if (k > 1 && map[i - k][j - k] == pl[c]) while (--k) map[i - k][j - k] = pl[c];
	for (k = 1; map[i - k][j + k] == pl[c ^ 1]; ++k);
	if (k > 1 && map[i - k][j + k] == pl[c]) while (--k) map[i - k][j + k] = pl[c];
	for (k = 1; map[i + k][j + k] == pl[c ^ 1]; ++k);
	if (k > 1 && map[i + k][j + k] == pl[c]) while (--k) map[i + k][j + k] = pl[c];
	for (k = 1; map[i + k][j - k] == pl[c ^ 1]; ++k);
	if (k > 1 && map[i + k][j - k] == pl[c]) while (--k) map[i + k][j - k] = pl[c];
	for (k = 1; map[i][j - k] == pl[c ^ 1]; ++k);
	if (k > 1 && map[i][j - k] == pl[c]) while (--k) map[i][j - k] = pl[c];
	for (k = 1; map[i][j + k] == pl[c ^ 1]; ++k);
	if (k > 1 && map[i][j + k] == pl[c]) while (--k) map[i][j + k] = pl[c];
	for (k = 1; map[i - k][j] == pl[c ^ 1]; ++k);
	if (k > 1 && map[i - k][j] == pl[c]) while (--k) map[i - k][j] = pl[c];
	for (k = 1; map[i + k][j] == pl[c ^ 1]; ++k);
	if (k > 1 && map[i + k][j] == pl[c]) while (--k) map[i + k][j] = pl[c];

	for (i = 1; i <= 8; ++i){
		for (j = 1; j <= 8; ++j){
			if (map[i][j] == 'B') ++b;
			else if (map[i][j] == 'W') ++w;
		}
	}

	printf("Black - %2d White - %2d\n", b, w);
	c ^= 1;
}

int main(){
	int set, i;
	char cop[10];

	for (i = 0; i < 10; ++i) map[0][i] = map[i][0] = map[9][i] = map[i][9] = 0;
	scanf("%d\n", &set);
	while (set--){
		for (i = 1; i <= 8; ++i) scanf("%s\n", map[i] + 1);
		scanf("%s\n", cop);
		if (cop[0] == 'W') c = 0; else c = 1;

		while (scanf("%s\n", cop) == 1 && cop[0] != 'Q'){
			if (cop[0] == 'L'){
				dolist();
			}else if (cop[0] == 'M'){
				move(int(cop[1] - '0'), int(cop[2] - '0'));
			}else while (1);
		}

		for (i = 1; i <= 8; ++i) printf("%s\n", map[i] + 1);

		if (set) putchar('\n');
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
