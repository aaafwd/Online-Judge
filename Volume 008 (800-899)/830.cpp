/* @JUDGE_ID: 19899RK 830 C++ "By Anadan" */
// Shark
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

char map[66][66];
int res[8];

void findshape(int i, int j){
	int n, m, l, r;
	char shark = 0;
	char c = map[i][j];

	for (m = 0; map[i][j + m] == c; ++m) map[i][j + m] = '.';
	for (n = 1, ++i; map[i][j] == c; ++n, ++i){
		l = r = 0;
		for (r = 0; map[i][j + r] == c; ++r) map[i][j + r] = '.';
		for (l = 0; map[i][j - l - 1] == c; ++l) map[i][j - l - 1] = '.';
		if (l + r != m) shark = 1;
	}

	if (map[i][j + 1] == c){
		map[i][j + 1] = '.';
		shark = 1;
	}

	if (n > m) n ^= m ^= n ^= m;
	if (shark) ++res[7];
	else if (n == 1){
		if (m == 1) ++res[0];
		else if (m == 2) ++res[1];
		else ++res[2];
	}
	else if (n == m) ++res[4];
	else if (n == 2) ++res[3];
	else if (n == 3) ++res[5];
	else if (n == 4) ++res[6];
}

int main(){
	int set, i, j, L, C;

	for (i = 0; i < 66; ++i) map[0][i] = map[i][0] = 0;
	scanf("%d\n\n", &set);
	while (set--){
		scanf("%d%d\n", &L, &C);
		for (i = 1; i <= L; ++i) scanf("%s\n", map[i] + 1);
		memset(map[i], 0, C + 2);
		memset(res, 0, sizeof(int) * 8);

		for (i = 1; i <= L; ++i) for (j = 1; j <= C; ++j){
			if (map[i][j] != '.'){
				findshape(i, j);
			}
		}

		printf("%d", res[0]);
		for (i = 1; i < 8; ++i) printf(" %d", res[i]);
		putchar('\n');

		if (set) putchar('\n');
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
