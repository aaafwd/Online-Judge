/* @JUDGE_ID: 19899RK 10307 C++ "By Anadan" */
// Killing Aliens in Borg Maze
// Accepted (0.275 seconds using as much as 612 kbytes)

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Edge {
	int i, j, v;
} pt[10240];
int rows, cols, index[64][64], sp, rank[128], p[128];
char map[64][64];
const int dx[] = {1,-1,0,0};
const int dy[] = {0,0,1,-1};

int sort_function(const void *a, const void *b) {
	Edge *ea = (Edge *)a, *eb = (Edge *)b;
	if (ea->v < eb->v) return -1;
	return 1;
}

int getp(int i) {
	if (p[i] != i) p[i] = getp(p[i]);
	return p[i];
}

void link(int i, int j) {
	i = getp(i);
	j = getp(j);
	if (i == j) return;
	if (rank[i] < rank[j]) {
		p[i] = j;
	} else {
		p[j] = i;
		if (rank[i] == rank[j]) ++rank[i];
	}
}

void make_dist(int x, int y) {
	char mask[64][64];
	int que[4096], i = 0, j = 1, k, start, count, step = 0;

	memset(mask, 0, sizeof(mask));
	que[0] = x*64 + y;
	mask[x][y] = 1;
	start = index[x][y];

	while (i < j) {
		count = 0;
		while (i < j) {
			x = que[i] / 64;
			y = que[i] % 64;
			++i;
			if (map[x][y] == 'A' && start < index[x][y]) {
				pt[sp].i = start;
				pt[sp].j = index[x][y];
				pt[sp++].v = step;
			}
			for (k = 0; k < 4; ++k) {
				if (mask[x+dx[k]][y+dy[k]] || map[x+dx[k]][y+dy[k]] == '#') continue;
				mask[x+dx[k]][y+dy[k]] = 1;
				que[j+count++] = (x+dx[k])*64 + (y+dy[k]);
			}
		}
		j += count;
		++step;
	}
}

int main() {
	int set, i, j, count, res;

	scanf("%d", &set);
	while (set--) {
		scanf("%d%d", &cols, &rows);
		while (getchar() != '\n');

		count = 0;
		for (i = 0; i < rows; ++i) {
			gets(map[i]);
			for (j = 0; j < cols; ++j) {
				if (map[i][j] == 'S') map[i][j] = 'A';
				if (map[i][j] == 'A') index[i][j] = count++;
			}
		}

		sp = 0;
		for (i = 0; i < rows; ++i) {
			for (j = 0; j < cols; ++j) {
				if (map[i][j] == 'A') make_dist(i, j);
			}
		}
		qsort(pt, sp, sizeof(pt[0]), sort_function);

		for (i = 0; i < count; ++i) {
			p[i] = i;
			rank[i] = 0;
		}

		res = 0;
		for (i = 0; i < sp; ++i) {
			if (getp(pt[i].i) != getp(pt[i].j)) {
				link(pt[i].i, pt[i].j);
				res += pt[i].v;
			}
		}
		printf("%d\n", res);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
