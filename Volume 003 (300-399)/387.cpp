/* @JUDGE_ID: 19899RK 387 C++ "By Anadan" */
// A Puzzling Problem
// Accepted (0.600 seconds using as much as 388 kbytes)

#include <stdio.h>
#include <string.h>

int N;
char map[8][9];
const int sz = 4;

struct Puzzle{
	int row, col;
	char figure[4][4], used;
}pz[5];

void xorpuzzle(int row, int col, int n){
	int i, j;

	for (i = 0; i < pz[n].row; i++) for (j = 0; j < pz[n].col; j++){
		if (pz[n].figure[i][j]) map[row + i][col + j] ^= n + '1';
	}

	pz[n].used ^= 1;
}

int match(int row, int col, int n){
	int i, j;

	for (i = 0; i < pz[n].row; i++) for (j = 0; j < pz[n].col; j++){
		if (pz[n].figure[i][j] && map[row + i][col + j]) return 0;
	}

	return 1;
}

int getpuzzle(int rest){
	int i, row, col;

	if (rest-- == 0) return 1;
	for (i = 0; i < N; i++){
		if (pz[i].used) continue;
		for (row = 0; row <= sz - pz[i].row; row++){
			for (col = 0; col <= sz - pz[i].col; col++){
				if (match(row, col, i)){
					xorpuzzle(row, col, i);
					if (getpuzzle(rest)) return 1;
					xorpuzzle(row, col, i);
				}
			}
		}
	}

	return 0;
}

void correctit(int n){
	int i;

	for (; pz[n].row > 1; pz[n].row--){
		for (i = 0; i < pz[n].col; i++) if (pz[n].figure[pz[n].row-1][i]) break;
		if (i < pz[n].col) break;
	}

	for (; pz[n].col > 1; pz[n].col--){
		for (i = 0; i < pz[n].row; i++) if (pz[n].figure[i][pz[n].col-1]) break;
		if (i < pz[n].row) break;
	}
}

int main(){
	int i, j, k, sum;
	char str[5], flag = 0;

	while (scanf("%d", &N) > 0){
		if (N == 0) break;
		for (i = sum = 0; i < N; i++){
			scanf("%d %d\n", &pz[i].row, &pz[i].col);
			for (j = 0; j < pz[i].row; j++){
				scanf("%s\n", str);
				for (k = 0; k < pz[i].col; k++){
					if (str[k] == '1'){
						++sum;
						pz[i].figure[j][k] = 1;
					}else pz[i].figure[j][k] = 0;
				}
			}
			correctit(i);
			pz[i].used = 0;
		}

		if (flag) putchar('\n'); else flag = 1;
		if (sum != 16) printf("No solution possible\n");
		else{
			for (i = 0; i < sz; i++) memset(map[i], 0, sz + 1);
			if (getpuzzle(N)){
				for (i = 0; i < sz; i++) printf("%s\n", map[i]);
			}else printf("No solution possible\n");
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
