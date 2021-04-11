/* @JUDGE_ID: 19899RK 10477 C++ "By Anadan" */ 
// The Hybrid Knight
// Accepted (1.965 seconds using as much as 400 kbytes)

#include <stdio.h>
#include <string.h>
#define SZ 1200

// 0 - Knight
// 1 - Mutant Knight
// 2 - Mutant Pawn
const int dx[3][8] = {
	{ -2, -2, -1, -1,  1,  1,  2,  2 },
	{ -3, -3, -1, -1,  1,  1,  3,  3 },
	{ -1,  0,  0,  1, -1, -1,  1,  1 },
};

const int dy[3][8] = {
	{  1, -1,  2, -2,  2, -2,  1, -1 },
	{  1, -1,  3, -3,  3, -3,  1, -1 },
	{  0,  1, -1,  0, -1,  1, -1,  1 },
};

struct Point{
	int x, y;
} p0, p1;

int N;
char map[20][20][3];

inline int valid(int x, int y){
	return ((0 <= x && x < N) && (0 <= y && y < N));
}

int dowave(int x, int y){
	int i = 0, j = 3, k, s, t, a, b, vertexes[SZ], step = 1, count;

	vertexes[0] = (x << 10) + (y << 5) + 0;
	vertexes[1] = (x << 10) + (y << 5) + 1;
	vertexes[2] = (x << 10) + (y << 5) + 2;
	map[x][y][0] = map[x][y][1] = map[x][y][2] = 1;
	if (map[p1.x][p1.y][0] || map[p1.x][p1.y][1] || map[p1.x][p1.y][2]) return 0;

	while (i < j){
		count = 0;
		while (i < j){
			x = vertexes[i] >> 10;
			y = (vertexes[i] >> 5) & 31;
			s = vertexes[i] & 31;
			t = (s + 1) % 3;
			++i;

			for (k = 0; k < 8; ++k){
				a = x + dx[s][k];
				b = y + dy[s][k];
				if (valid(a, b) && map[a][b][t] == 0){
					if (a == p1.x && b == p1.y){
						return step;
					}
					if (s != 2 || (s == 2 && k < 4)){
						map[a][b][t] = 1;
						vertexes[j + count++] = (a << 10) + (b << 5) + t;
					}
				}
			}
		}

		j += count;
		++step;
	}

	return -1;
}

int main(){
	int set = 0, S, i, j;

	while (scanf("%d%d\n", &N, &S) == 2 && N){
		printf("Set %d:\n", ++set);
		while (S--){
			scanf("%d%d", &i, &j); --i; --j;
			p0.x = i / N; p0.y = i % N;
			p1.x = j / N; p1.y = j % N;
			memset(map, 0, sizeof(map));

			i = dowave(p0.x, p0.y);

			if (i == -1) printf("?\n");
			else printf("%d\n", i);
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
