/* @JUDGE_ID: 19899RK 10309 C++ "By Anadan" */ 
// Turn the Lights Off
// Accepted (1.824 seconds using as much as 400 kbytes)

#include <stdio.h>
#include <string.h>

int min, count, tmp, mmask;
char map[10][11], mask[10][10];

void xxor(int i, int j){
	mask[i][j] ^= 1;
	map[i][j] ^= 1;
	if (i) map[i - 1][j] ^= 1;
	if (j) map[i][j - 1] ^= 1;
	if (i < 9) map[i + 1][j] ^= 1;
	if (j < 9) map[i][j + 1] ^= 1;
}

void doswitch(int row, int curr){
	int col;

	if (curr >= min) return;

	if (row == 0){
		for (count = 0; count < 1024; ++count){
			tmp = count;
			for (col = 0; col < 10; ++col){
				if (tmp & 1) xxor(0, col), ++curr;
				tmp >>= 1;
			}

			mmask = 0;
			for (tmp = 0; tmp < 10; ++tmp){
				mmask <<= 1;
				if (map[0][tmp]){
					mmask |= 1;
					xxor(1, tmp);
					++curr;
				}
			}

			doswitch(1, curr);

			for (tmp = 9; tmp >= 0; --tmp){
				if (mmask & 1) xxor(1, tmp), --curr;
				mmask >>= 1;
			}

			tmp = count;
			for (col = 0; col < 10; ++col){
				if (tmp & 1) xxor(0, col), --curr;
				tmp >>= 1;
			}
		}

		return;
	}

	for (; row < 10; ++row){
		for (col = 0; col < 10; ++col) if (map[row][col]) break;
		if (col < 10) break;
	}

	if (row == 10){
		min = curr;
		return;
	}

	if (row < 9){
		xxor(row + 1, col);
		if (mask[row + 1][col]) doswitch(row, curr + 1);
		xxor(row + 1, col);

		if (row > 1 && col < 9){
			xxor(row, col + 1);
			if (mask[row][col + 1]) doswitch(row - 1, curr + 1);
			xxor(row, col + 1);
		}

		if (row > 1 && col){
			xxor(row, col - 1);
			if (mask[row][col - 1]) doswitch(row - 1, curr + 1);
			xxor(row, col - 1);
		}

		if (row > 2){
			xxor(row - 1, col - 1);
			if (mask[row - 1][col - 1]) doswitch(row - 2, curr + 1);
			xxor(row - 1, col - 1);
		}

	}else if (row == 9){
		if (col < 9){
			xxor(row, col + 1);
			if (mask[row][col + 1]) doswitch(row - 1, curr + 1);
			xxor(row, col + 1);
		}

		if (col){
			xxor(row, col - 1);
			if (mask[row][col - 1]) doswitch(row - 1, curr + 1);
			xxor(row, col - 1);
		}

		xxor(row - 1, col - 1);
		if (mask[row - 1][col - 1]) doswitch(row - 2, curr + 1);
		xxor(row - 1, col - 1);
	}
}

int main(){
	int i, j;
	char str[128];

	while (scanf("%s", str) == 1 && strcmp(str, "end")){
		for (i = 0; i < 10; ++i){
			scanf("%s", map[i]);
			for (j = 0; j < 10; ++j){
				if (map[i][j] == 'O') map[i][j] = 1;
				else map[i][j] = 0;
			}
		}

		memset(mask, 0, sizeof(mask));
		min = 101;
		doswitch(0, 0);
		if (min > 100) min = -1;
		printf("%s %d\n", str, min);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
