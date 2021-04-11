/* @JUDGE_ID: 19899RK 10426 C++ "By Anadan" */ 
// Knights' Nightmare
// Accepted (0.510 seconds using as much as 396 kbytes)

#include <stdio.h>

int r, c;
struct Point{
	int x, y;
}pt[4], m;
char mask[18][18];

void init(int map[16][16]){
	int i, j;

	for (i = 0; i < r; ++i){
		for (j = 0; j < c; ++j){
			map[i][j] = -1;
			mask[i + 2][j + 2] = 0;
		}
		mask[i + 2][j + 2] = mask[i + 2][j + 3] = 1;
	}

	for (j = 0; j < c + 2; ++j){
		mask[i + 2][j + 2] = mask[i + 3][j + 2] = 1;
	}
}

void dowave(int map[16][16], Point p){
	int i = 0, j = 1, count, step = 0, vertexes[256];

	vertexes[0] = (p.x << 5) + p.y;
	mask[p.x][p.y] = 1;

	while(i < j){
		count = 0;
		while (i < j){
			p.x = vertexes[i] >> 5;
			p.y = vertexes[i] & 31;
			++i;
			map[p.x - 2][p.y - 2] = step;

			if (!mask[p.x - 2][p.y - 1]){
				mask[p.x - 2][p.y - 1] = 1;
				vertexes[j + count] = ((p.x - 2) << 5) + (p.y - 1);
				++count;
			}

			if (!mask[p.x - 2][p.y + 1]){
				mask[p.x - 2][p.y + 1] = 1;
				vertexes[j + count] = ((p.x - 2) << 5) + (p.y + 1);
				++count;
			}

			if (!mask[p.x + 2][p.y + 1]){
				mask[p.x + 2][p.y + 1] = 1;
				vertexes[j + count] = ((p.x + 2) << 5) + (p.y + 1);
				++count;
			}

			if (!mask[p.x + 2][p.y - 1]){
				mask[p.x + 2][p.y - 1] = 1;
				vertexes[j + count] = ((p.x + 2) << 5) + (p.y - 1);
				++count;
			}

			if (!mask[p.x - 1][p.y - 2]){
				mask[p.x - 1][p.y - 2] = 1;
				vertexes[j + count] = ((p.x - 1) << 5) + (p.y - 2);
				++count;
			}

			if (!mask[p.x - 1][p.y + 2]){
				mask[p.x - 1][p.y + 2] = 1;
				vertexes[j + count] = ((p.x - 1) << 5) + (p.y + 2);
				++count;
			}

			if (!mask[p.x + 1][p.y + 2]){
				mask[p.x + 1][p.y + 2] = 1;
				vertexes[j + count] = ((p.x + 1) << 5) + (p.y + 2);
				++count;
			}

			if (!mask[p.x + 1][p.y - 2]){
				mask[p.x + 1][p.y - 2] = 1;
				vertexes[j + count] = ((p.x + 1) << 5) + (p.y - 2);
				++count;
			}
		}

		j += count;
		++step;
	}
}

inline int imin(int a, int b, int c, int d){
	if (a > b) a = b;
	if (c > d) c = d;
	if (a > c) a = c;
	return a;
}

int getmintime(){
	int i, j, k, min;
	static int map1[4][16][16], map2[4][16][16];

	min = -1;
	for (k = 0; k < 4; ++k){
		init(map1[k]); mask[m.x][m.y] = 1;
		dowave(map1[k], pt[k]);
		init(map2[k]);
		dowave(map2[k], pt[k]);
	}

	for (i = 0; i < r; ++i) for (j = 0; j < c; ++j){
		if (map1[0][i][j] == -1 || map1[1][i][j] == -1 || map1[2][i][j] == -1 || map1[3][i][j] == -1) continue;
		k = imin(
			map2[0][i][j] + map1[1][i][j] + map1[2][i][j] + map1[3][i][j],
			map1[0][i][j] + map2[1][i][j] + map1[2][i][j] + map1[3][i][j],
			map1[0][i][j] + map1[1][i][j] + map2[2][i][j] + map1[3][i][j],
			map1[0][i][j] + map1[1][i][j] + map1[2][i][j] + map2[3][i][j]
		);
		
		if (min == -1 || min > k) min = k;
	}

	return min;
}

int main(){
	int i;
	char str[21];

	for (i = 0; i < 18; ++i) mask[0][i] = mask[i][0] = mask[1][i] = mask[i][1] = 1;
	while (scanf("%s\n%d%d", str, &r, &c) == 3){
		printf("%s\n", str);
		for (i = 0; i < 4; ++i){
			scanf("%d%d", &pt[i].x, &pt[i].y);
			++pt[i].x; ++pt[i].y;
		}
		scanf("%d%d\n", &m.x, &m.y); ++m.x; ++m.y;
		i = getmintime();
		if (i == -1) printf("Meeting is impossible.\n");
		else printf("Minimum time required is %d minutes.\n", i);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
