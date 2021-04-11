/* @JUDGE_ID: 19899RK 298 C++ "By Anadan" */ 
// Race Tracks
// Accepted (0.424 seconds using as much as 620 kbytes)

#include <stdio.h>
#include <string.h>
#define SZ 5000

int hopes[30][30][49], X, Y;
char map[30][30];

struct Point{
	int x, y, v;
};

inline int valid(Point p, int x, int y){
	if (x < -3 || x > 3 || y < -3 || y > 3) return 0;
	x += p.x; y += p.y;
	if (x < 0 || x >= X || y < 0 || y >= Y) return 0;
	return (map[x][y] == 0);
}

int main(){
	int set, i, j, k, x, y, dx, dy;
	Point p0, p1, q0, q1, vertexes[SZ];

	scanf("%d\n", &set);
	while (set--){
		scanf("%d%d%d%d%d%d%d\n", &X, &Y, &p0.x, &p0.y, &p1.x, &p1.y, &k);
		memset(map, 0, sizeof(map));
		while (k--){
			scanf("%d%d%d%d\n", &q0.x, &q1.x, &q0.y, &q1.y);
			for (i = q0.x; i <= q1.x; ++i){
				for (j = q0.y; j <= q1.y; ++j){
					map[i][j] = 1;
				}
			}
		}

		for (i = 0; i < X; ++i) for (j = 0; j < Y; ++j){
			memset(hopes[i][j], -1, sizeof(hopes[i][j]));
		}

		hopes[p0.x][p0.y][24] = 0;
		i = 0; j = 1; p0.v = 24; k = -1;
		vertexes[0] = p0;

		while (i != j){
			p0 = vertexes[i++]; if (i == SZ) i = 0;
			x = p0.v / 7 - 3;
			y = p0.v % 7 - 3;
			for (dx = -1; dx <= 1; ++dx) for (dy = -1; dy <= 1; ++dy){
				if (valid(p0, x + dx, y + dy)){
					vertexes[j].v = (x + dx + 3)*7 + y + dy + 3;
					int &tmp = hopes[p0.x + x + dx][p0.y + y + dy][vertexes[j].v];
					if (tmp == -1 || tmp > hopes[p0.x][p0.y][p0.v] + 1){
						tmp = hopes[p0.x][p0.y][p0.v] + 1;
						if (k == -1 || tmp < k){
							vertexes[j].x = p0.x + x + dx;
							vertexes[j].y = p0.y + y + dy;
							++j; if (j == SZ) j = 0;
						}
					}

					if (p0.x + x + dx == p1.x && p0.y + y + dy == p1.y){
						if (k == -1 || k > tmp) k = tmp;
					}
				}
			}
		}

		if (k == -1) printf("No solution.\n");
		else printf("Optimal solution takes %d hops.\n", k);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
