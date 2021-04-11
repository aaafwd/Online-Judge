/* @JUDGE_ID: 19899RK 10336 C++ "By Anadan" */
// Rank the Languages
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SZ 200

struct Result{
	char c;
	int res;
}res[26];
char map[SZ][SZ];

int sort_function(const void *a, const void *b){
	Result *ra = (Result *)a, *rb = (Result *)b;
	if (ra->res > rb->res) return -1;
	if (ra->res < rb->res) return 1;
	if (ra->c < rb->c) return -1;
	return 1;
}

void func(int i, int j){
	char c = map[i][j];
	map[i][j] = 0;
	if (map[i - 1][j] == c) func(i - 1, j);
	if (map[i + 1][j] == c) func(i + 1, j);
	if (map[i][j - 1] == c) func(i, j - 1);
	if (map[i][j + 1] == c) func(i, j + 1);
}

int main(){
	int H, W, i, j, sets, n;

	for (i = 0; i < SZ; ++i) map[0][i] = map[i][0] = 0;
	scanf("%d\n", &sets);
	for (n = 1; n <= sets; ++n){
		scanf("%d%d\n", &H, &W);
		for (i = 1; i <= H; ++i) scanf("%s\n", map[i] + 1);
		memset(map[i], 0, W + 2);
		for (i = 0; i < 26; ++i){
			res[i].c = 'a' + i;
			res[i].res = 0;
		}

		for (i = 1; i <= H; ++i){
			for (j = 1; j <= W; ++j){
				if (map[i][j]){
					++res[map[i][j] - 'a'].res;
					func(i, j);
				}
			}
		}

		qsort(res, 26, sizeof(Result), sort_function);
		printf("World #%d\n", n);
		for (i = 0; i < 26; ++i){
			if (res[i].res == 0) break;
			printf("%c: %d\n", res[i].c, res[i].res);
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
