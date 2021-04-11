/* @JUDGE_ID: 19899RK 10021 C++ "By Anadan" */ 
// Cube in the labirint
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

const int left[6][6] = {
	{ -1, 3, 1, 4, 2, -1 },
	{ 2, -1, 5, 0, -1, 3 },
	{ 4, 0, -1, -1, 5, 1 },
	{ 1, 5, -1, -1, 0, 4 },
	{ 3, -1, 0, 5, -1, 2 },
	{ -1, 2, 4, 1, 3, -1 }
};

struct Point{
	int x, y;
} p1, p2;

int rows, cols;
char map[10][10], mask[10][10][36];

void scan_h(char *str){
	int x, y;

	while (gets(str) && str[0] && str[0] != 'v'){
		sscanf(str, "%d%d", &x, &y); --x; --y;
		map[y][x] |= 4;
		map[y + 1][x] |= 1;
	}
}

void scan_v(char *str){
	int x, y;

	while (gets(str) && str[0] && str[0] != 'h'){
		sscanf(str, "%d%d", &x, &y); --x; --y;
		map[y][x] |= 2;
		map[y][x + 1] |= 8;
	}
}

int dowave(){
	int i = 0, j = 1, vertexes[3600], step = 0, count, x, y, a, b;

	memset(mask, 0, sizeof(mask));
	mask[p1.y][p1.x][1] = 1;
	vertexes[0] = (p1.y << 10) + (p1.x << 6) + 1;

	while (i < j){
		count = 0;
		if (mask[p2.y][p2.x][1] || mask[p2.y][p2.x][13] || mask[p2.y][p2.x][19] || mask[p2.y][p2.x][31]) return step;
		while (i < j){
			y = vertexes[i] >> 10;
			x = (vertexes[i] >> 6) & 15;
			a = (vertexes[i] >> 3) & 7;
			b = vertexes[i] & 7;
			++i;

			// Up
			if (!(map[y][x] & 1) && !mask[y - 1][x][(b * 6 + 5 - a)]){
				mask[y - 1][x][(b * 6 + 5 - a)] = 1;
				vertexes[j + count++] = ((y - 1) << 10) + (x << 6) + (b << 3) + (5 - a);
			}

			// Down
			if (!(map[y][x] & 4) && !mask[y + 1][x][((5 - b) * 6 + a)]){
				mask[y + 1][x][((5 - b) * 6 + a)] = 1;
				vertexes[j + count++] = ((y + 1) << 10) + (x << 6) + ((5 - b) << 3) + (a);
			}

			// Left
			if (!(map[y][x] & 8) && !mask[y][x - 1][a * 6 + left[a][b]]){
				mask[y][x - 1][a * 6 + left[a][b]] = 1;
				vertexes[j + count++] = (y << 10) + ((x - 1) << 6) + (a << 3) + (left[a][b]);
			}

			// Right
			if (!(map[y][x] & 2) && !mask[y][x + 1][a * 6 + 5 - left[a][b]]){
				mask[y][x + 1][a * 6 + 5 - left[a][b]] = 1;
				vertexes[j + count++] = (y << 10) + ((x + 1) << 6) + (a << 3) + (5 - left[a][b]);
			}
		}

		j += count;
		++step;
	}

	return -1;
}

int main(){
	int set, i;
	char str[64];

	scanf("%d\n\n", &set);
	while (set--){
		scanf("%d%d%d%d%d%d", &cols, &rows, &p1.x, &p1.y, &p2.x, &p2.y);
		--p1.x; --p1.y; --p2.x; --p2.y;
		while ((i = getchar()) != '\n' && i != EOF);
		
		memset(map, 0, sizeof(map));
		for (i = 0; i < cols; ++i){
			map[0][i] |= 1;
			map[rows - 1][i] |= 4;
		}
		for (i = 0; i < rows; ++i){
			map[i][0] |= 8;
			map[i][cols - 1] |= 2;
		}

		if (gets(str) && str[0]){
			if (str[0] == 'v') scan_v(str);
			else scan_h(str);
			if (str[0] == 'v') scan_v(str);
			else scan_h(str);
		}

		i = dowave();
		if (i == -1) puts("No solution");
		else printf("%d\n", i);

		if (set) putchar('\n');
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
