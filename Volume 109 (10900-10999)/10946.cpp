/* @JUDGE_ID: 19899RK 10946 C++ "By Anadan" */
// You want what filled?
// Accepted (0.027 seconds with low memory spent)

#include <stdio.h>
#include <stdlib.h>

struct Result {
	char ch;
	int count;
} pt[2500];

int rows, cols, sp, count;
char map[64][64];

void dowave(int i, int j) {
	char ch = map[i][j];
	++count;
	map[i][j] = '.';
	if (i && map[i-1][j] == ch) dowave(i-1, j);
	if (j && map[i][j-1] == ch) dowave(i, j-1);
	if (i < rows-1 && map[i+1][j] == ch) dowave(i+1, j);
	if (j < cols-1 && map[i][j+1] == ch) dowave(i, j+1);
}

int sort_function(const void *a, const void *b) {
	Result *ra = (Result*)a, *rb = (Result*)b;
	if (ra->count > rb->count) return -1;
	if (ra->count < rb->count) return 1;
	if (ra->ch < rb->ch) return -1;
	return 1;
}

int main() {
	int set = 0, i, j;

	while (scanf("%d%d", &rows, &cols) == 2 && rows) {
		for (i = 0; i < rows; ++i) {
			scanf("%s", map[i]);
		}
		sp = 0;
		for (i = 0; i < rows; ++i) {
			for (j = 0; j < cols; ++j) {
				if (map[i][j] != '.') {
					pt[sp].ch = map[i][j];
					count = 0;
					dowave(i, j);
					pt[sp].count = count;
					++sp;
				}
			}
		}
		qsort(pt, sp, sizeof(pt[0]), sort_function);

		printf("Problem %d:\n", ++set);
		for (i = 0; i < sp; ++i) {
			printf("%c %d\n", pt[i].ch, pt[i].count);
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
