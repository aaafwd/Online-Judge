/* @JUDGE_ID: 19899RK 487 C++ "By Anadan" */
// Boggle Blitz
// Accepted (0.594 seconds using as much as 3016 kbytes)

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int N, sp;
char map[21][21], mask[21][21], curr[64], *res[131072];
struct tag_index{
	int start, end;
} indexes[21][21];

const int dx[] = { -1, -1, -1,  1, 1, 1, 0,  0 };
const int dy[] = { -1,  0,  1, -1, 0, 1, -1, 1 };

int sort_function(const void *a, const void *b) {
	int len1 = strlen(*(char**)a), len2 = strlen(*(char**)b);
	if (len1 < len2) return -1;
	if (len1 > len2) return  1;
	return strcmp(*(char**)a, *(char**)b);
}

void addWords(int r, int c) {
	int i;
	for (i = indexes[r][c].start; i < indexes[r][c].end; ++i) {
		strcpy(curr+1, res[i]);
		res[sp++] = strcpy(new char[strlen(curr) + 1], curr);
	}
}

inline int isValid(int r, int c) { return 0 <= r && 0 <= c && r < N && c < N; }

void generate(int r, int c) {
	int k;

	mask[r][c] = 1;
	for (k = 0; k < 8; ++k) {
		if (isValid(r+dx[k], c+dy[k]) && map[r][c] < map[r+dx[k]][c+dy[k]]) {
			if (indexes[r+dx[k]][c+dy[k]].start == -1) {
				generate(r+dx[k], c+dy[k]);
			}
		}
	}

	indexes[r][c].start = sp;
	curr[0] = map[r][c]; curr[1] = 0;
	res[sp++] = strcpy(new char[2], curr);

	for (k = 0; k < 8; ++k) {
		if (isValid(r+dx[k], c+dy[k]) && map[r][c] < map[r+dx[k]][c+dy[k]]) {
			addWords(r+dx[k], c+dy[k]);
		}
	}

	indexes[r][c].end = sp;
}

int main() {
	int set, i, j;

	scanf("%d", &set);
	while (set--) {
		scanf("%d", &N);
		for (i = 0; i < N; ++i) scanf("%s", map[i]);
		sp = 0;
		memset(mask, 0, sizeof(mask));
		memset(indexes, -1, sizeof(indexes));
		for (i = 0; i < N; ++i) {
			for (j = 0; j < N; ++j) {
				if (mask[i][j]) continue;
				generate(i, j);
			}
		}

		qsort(res, sp, sizeof(char*), sort_function);
		for (i = 0; i < sp; ++i) {
			if (i && strcmp(res[i-1], res[i]) == 0) continue;
			if (strlen(res[i]) > 2) puts(res[i]);
		}

		if (set) putchar('\n');
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
