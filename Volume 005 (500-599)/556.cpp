/* @JUDGE_ID: 19899RK 556 C++ "By Anadan" */
// Amazing
// Accepted (0.002 seconds with low memory spent)

#include <stdio.h>
#include <string.h>
#define SZ 102

int main(){
	int b, w, i, j, k, di, dj, freq[SZ][SZ], res[5];
	char map[SZ][SZ];

	for (i = 0; i < SZ; ++i) map[0][i] = map[i][0] = 0;
	while (scanf("%d%d\n", &b, &w) == 2 && b){
		for (i = 1; i <= b; ++i){
			scanf("%s\n", map[i] + 1);
			for (j = 1; j <= w; ++j){
				if (map[i][j] == '0') freq[i][j] = 0;
				else freq[i][j] = 10;
			}
		}

		memset(map[i], 0, w + 2);
		i = b; j = 1; di = 0; dj = 1;

		do{
			di ^= dj ^= di ^= dj;
			dj = -dj;

			for (k = 0; k < 4; ++k){
				if (map[i + di][j + dj] == '0') break;
				di ^= dj ^= di ^= dj;
				di = -di;
			}

			if (k == 4) break;
			++freq[i][j];
			i += di; j += dj;

		}while (i != b || j != 1);

		for (i = 0; i < 5; ++i) res[i] = 0;
		for (i = 1; i <= b; ++i) for (j = 1; j <= w; ++j){
			if (freq[i][j] < 5) ++res[freq[i][j]];
		}

		for (i = 0 ; i < 5; ++i) printf("%3d", res[i]);
		putchar('\n');
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
