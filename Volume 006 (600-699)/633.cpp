/* @JUDGE_ID: 19899RK 633 C++ "By Anadan" */ 
// A Chess Knight
// Accepted (0.010 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

int N;
struct Point{
	int x, y;
}p0, p1;
char map[40][40][3];
const int dx[] = { 1, 1, 2, 2, -1, -1, -2, -2, 2, 2, -2, -2 };
const int dy[] = { 2, -2, 1, -1, 2, -2, 1, -1, 2, -2, 2, -2 };

inline int isvalid(int x, int y){
	return (x >= 0 && y >= 0 && x < N && y < N);
}

// 0 - type K
// 1 - type B
// 2 - type T
int getminstep(){
	int i = 0, j = 3, k, vertexes[4800], step = 0, count, x, y, type;

	map[p0.x][p0.y][0] = map[p0.x][p0.y][1] = map[p0.x][p0.y][2] = 1;
	vertexes[0] = (p0.x << 8) + (p0.y << 2) + 0;
	vertexes[1] = (p0.x << 8) + (p0.y << 2) + 1;
	vertexes[2] = (p0.x << 8) + (p0.y << 2) + 2;

	while (i < j){
		count = 0;
		while (i < j){
			x = vertexes[i] >> 8;
			y = (vertexes[i] >> 2) & 63;
			type = vertexes[i++] & 3;

			if (x == p1.x && y == p1.y) return step;

			if (type != 0){
				for (k = 0; k < 8; ++k){
					if (isvalid(x + dx[k], y + dy[k]) && map[x + dx[k]][y + dy[k]][0] == 0){
						map[x + dx[k]][y + dy[k]][0] = 1;
						vertexes[j + count++] = ((x + dx[k]) << 8) + ((y + dy[k]) << 2) + 0;
					}
				}
			}

			if (type != 1){
				for (k = 8; k < 12; ++k){
					if (isvalid(x + dx[k], y + dy[k]) && map[x + dx[k]][y + dy[k]][1] == 0){
						map[x + dx[k]][y + dy[k]][1] = 1;
						vertexes[j + count++] = ((x + dx[k]) << 8) + ((y + dy[k]) << 2) + 1;
					}
				}
			}

			if (type != 2){
				if (map[x][N - 1 - y][2] == 0){
					map[x][N - 1 - y][2] = 1;
					vertexes[j + count++] = ((x) << 8) + ((N - 1 - y) << 2) + 2;
				}

				if (map[N - 1 - x][y][2] == 0){
					map[N - 1 - x][y][2] = 1;
					vertexes[j + count++] = ((N - 1 - x) << 8) + ((y) << 2) + 2;
				}
			}
		}

		j += count;
		++step;
	}

	return -1;
}

int main(){
	int i, j;

	while (scanf("%d%d%d%d%d", &N, &p0.x, &p0.y, &p1.x, &p1.y) == 5 && N){
		--p0.x; --p0.y; --p1.x; --p1.y;
		N <<= 1;
		memset(map, 0, sizeof(map));
		while (scanf("%d%d", &i, &j) == 2 && i){
			--i; --j;
			map[i][j][0] = map[i][j][1] = map[i][j][2] = 1;
		}

		i = getminstep();
		if (i == -1) puts("Solution doesn't exist");
		else printf("Result : %d\n", i);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
