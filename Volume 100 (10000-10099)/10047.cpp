/* @JUDGE_ID: 19899RK 10047 C++ "By Anadan" */
// The Monocycle
// Accepted (0.016 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

int rows, cols, que[32768];
char map[32][32], mask[32768];
const int dx[] = { -1,0,1,0 };
const int dy[] = { 0,1,0,-1 };

int addToQueue(int x, int y, int dir, int color, int offset) {
	int value;
	if (x < 0 || y < 0 || x >= rows || y >= cols || map[x][y] == '#') return 0;
	value = (x << 10) | (y << 5) | (color << 2) | (dir);
	if (mask[value]) return 0;
	que[offset] = value;
	mask[value] = 1;
	return 1;
}

int bfs() {
	int i, j, step = 0, count, x, y, dir, color;

	for (i = 0; i < rows; ++i) {
		for (j = 0; j < cols; ++j) if (map[i][j] == 'S') break;
		if (j < cols) break;
	}

	memset(mask, 0, sizeof(mask));
	que[0] = (i << 10) | (j << 5);

	i = 0; j = 1;
	while (i < j) {
		count = 0;
		while (i < j) {
			x = (que[i] >> 10) & 31;
			y = (que[i] >> 5) & 31;
			color = (que[i] >> 2) & 7;
			if (map[x][y] == 'T' && color == 0) return step;
			dir = (que[i]) & 3;
			++i;

			dir = (dir + 1) & 3;
			count += addToQueue(x, y, dir, color, j + count);
			dir = (dir + 2) & 3;
			count += addToQueue(x, y, dir, color, j + count);
			dir = (dir + 1) & 3;

			x += dx[dir];
			y += dy[dir];
			count += addToQueue(x, y, dir, (color + 1) % 5, j + count);
		}
		j += count;
		++step;
	}
	return -1;
}

int main() {
	int set = 0, i;

	while (scanf("%d%d", &rows, &cols) == 2 && rows) {
		for (i = 0; i < rows; ++i) scanf("%s", map[i]);

		if (set) putchar('\n');
		printf("Case #%d\n", ++set);
		i = bfs();
		if (i < 0) puts("destination not reachable");
		else printf("minimum time = %d sec\n", i);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
