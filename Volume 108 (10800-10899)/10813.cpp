/* @JUDGE_ID: 19899RK 10813 C++ "By Anadan" */
// Traditional BINGO
// Accepted (0.004 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

int map[5][5], nums[75], arr[76];

int solve() {
	int i, j, res, row[5], col[5], d1, d2;

	for (i = 0; i < 5; ++i) row[i] = col[i] = 5;
	d1 = d2 = row[2] = col[2] = 4;

	for (res = 0; res < 75; ++res) {
		if (arr[nums[res]] < 0) continue;
		i = arr[nums[res]] >> 3;
		j = arr[nums[res]] & 7;
		if (--row[i] == 0 || --col[j] == 0) break;
		if (i == j && --d1 == 0) break;
		if (i == 4-j && --d2 == 0) break;
	}

	return res+1;
}

int main(){
	int set, i, j;

	map[2][2] = 0;
	scanf("%d", &set);
	while (set--) {
		memset(arr, -1, sizeof(arr));
		for (i = 0; i < 5; ++i) {
			for (j = 0; j < 5; ++j) {
				if (i == 2 && j == 2) continue;
				scanf("%d", &map[i][j]);
				arr[map[i][j]] = (i<<3) | j;
			}
		}
		for (i = 0; i < 75; ++i) scanf("%d", nums+i);
		printf("BINGO after %d numbers announced\n", solve());
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
