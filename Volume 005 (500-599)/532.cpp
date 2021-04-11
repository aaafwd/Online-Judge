/* @JUDGE_ID: 19899RK 532 C++ "By Anadan" */
// Dungeon Master
// Accepted (0.016 seconds with low memory spent)

#include <stdio.h>
#include <string.h>
#define SZ 27000

struct Point{
	int x, y, z;
};
int L, R, C;
char map[30][30][31];
Point end;

int getsteps(Point &p0){
	int i = 0, j = 1, count, step = 0;
	Point vertexes[SZ];

	map[p0.x][p0.y][p0.z] = 0;
	vertexes[0] = p0;
	while (i < j){
		++step;
		count = 0;
		while (i < j){
			p0 = vertexes[i++];

			if (p0.x){
				if (map[p0.x - 1][p0.y][p0.z] == 'E') return step;
				if (map[p0.x - 1][p0.y][p0.z] == '.'){
					vertexes[j + count] = p0;
					vertexes[j + count].x--;
					map[p0.x - 1][p0.y][p0.z] = 0;
					++count;
				}
			}

			if (p0.x < L - 1){
				if (map[p0.x + 1][p0.y][p0.z] == 'E') return step;
				if (map[p0.x + 1][p0.y][p0.z] == '.'){
					vertexes[j + count] = p0;
					vertexes[j + count].x++;
					map[p0.x + 1][p0.y][p0.z] = 0;
					++count;
				}
			}

			if (p0.y){
				if (map[p0.x][p0.y - 1][p0.z] == 'E') return step;
				if (map[p0.x][p0.y - 1][p0.z] == '.'){
					vertexes[j + count] = p0;
					vertexes[j + count].y--;
					map[p0.x][p0.y - 1][p0.z] = 0;
					++count;
				}
			}

			if (p0.y < R - 1){
				if (map[p0.x][p0.y + 1][p0.z] == 'E') return step;
				if (map[p0.x][p0.y + 1][p0.z] == '.'){
					vertexes[j + count] = p0;
					vertexes[j + count].y++;
					map[p0.x][p0.y + 1][p0.z] = 0;
					++count;
				}
			}

			if (p0.z){
				if (map[p0.x][p0.y][p0.z - 1] == 'E') return step;
				if (map[p0.x][p0.y][p0.z - 1] == '.'){
					vertexes[j + count] = p0;
					vertexes[j + count].z--;
					map[p0.x][p0.y][p0.z - 1] = 0;
					++count;
				}
			}

			if (p0.z < C - 1){
				if (map[p0.x][p0.y][p0.z + 1] == 'E') return step;
				if (map[p0.x][p0.y][p0.z + 1] == '.'){
					vertexes[j + count] = p0;
					vertexes[j + count].z++;
					map[p0.x][p0.y][p0.z + 1] = 0;
					++count;
				}
			}
		}

		j += count;
	}

	return -1;
}

int main(){
	int i, j;
	Point p0;
	char *p;

	while (scanf("%d%d%d\n", &L, &R, &C) == 3){
		if (L == 0 && R == 0 && C == 0) break;
		p0.x = end.x = -1;
		for (i = 0; i < L; ++i){
			for (j = 0; j < R; ++j){
				scanf("%s\n", map[i][j]);
				if (p0.x == -1 && (p = strchr(map[i][j], 'S')) != NULL){
					p0.x = i; p0.y = j; p0.z = int(p - map[i][j]);
				}
				if (end.x == -1 && (p = strchr(map[i][j], 'E')) != NULL){
					end.x = i; end.y = j; end.z = int(p - map[i][j]);
				}
			}
		}

		if (p0.x == -1 || end.x == -1){
			printf("Trapped!\n");
		}else{
			i = getsteps(p0);
			if (i == -1) printf("Trapped!\n");
			else printf("Escaped in %d minute(s).\n", i);
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
