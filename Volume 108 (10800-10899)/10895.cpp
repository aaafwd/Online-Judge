/* @JUDGE_ID: 19899RK 10895 C++ "By Anadan" */
// Matrix Transpose
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>
#include <stdlib.h>
#define SZ 1000

struct Line {
	int ndx, value;
};

int N, M, elems[SZ], index[SZ], next[SZ], sp, begin[10000], end[10000];

void init() {
	int i;
	for (i = 0; i < N; ++i) begin[i] = end[i] = -1;
	sp = 0;
}

void add(int i, int j, int value) {
	if (end[i] == -1) {
		begin[i] = end[i] = sp;
	} else {
		next[end[i]] = sp;
		end[i] = sp;
	}
	index[sp] = j;
	elems[sp] = value;
	next[sp] = -1;
	++sp;
}

int sort_function(const void *a, const void *b) {
	Line *la = (Line *)a, *lb = (Line *)b;
	if (la->ndx < lb->ndx) return -1;
	return 1;
}

int getLine(int row, Line * line) {
	int sz = 0, i;
	for (i = begin[row]; i != -1; i = next[i]) {
		line[sz].ndx = index[i];
		line[sz].value = elems[i];
		++sz;
	}
	qsort(line, sz, sizeof(Line), sort_function);
	return sz;
}

int main() {
	int R, i, j, k, ndx[SZ];
	Line line[SZ];

	while (scanf("%d%d", &M, &N) == 2) {
		init();
		for (i = 0; i < M; ++i) {
			scanf("%d", &R);
			for (j = 0; j < R; ++j) scanf("%d", ndx+j);
			for (j = 0; j < R; ++j) {
				scanf("%d", &k);
				add(ndx[j]-1, i, k);
			}
		}

		printf("%d %d\n", N, M);
		for (i = 0; i < N; ++i) {
			k = getLine(i, line);
			printf("%d", k);
			for (j = 0; j < k; ++j) printf(" %d", line[j].ndx+1);
			putchar('\n');
			for (j = 0; j < k; ++j) {
				if (j) putchar(' ');
				printf("%d", line[j].value);
			}
			putchar('\n');
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
