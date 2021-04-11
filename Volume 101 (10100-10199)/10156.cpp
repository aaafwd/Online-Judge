/* @JUDGE_ID: 19899RK 10156 C++ "By Anadan" */
// Sala-ma-Sond, A Nice Little Pond
// Accepted (0.422 seconds using as much as 464 kbytes)

#include <stdio.h>

struct Turtle{
	int x, y;
}pt[3600];
char map[60][61];
int N, M;

const int dx[] = { -1, -1, 0, 1, 1,  1,  0, -1 };
const int dy[] = {  0,  1, 1, 1, 0, -1, -1, -1 };

inline int getdir(char *s){
	if (s[0] == 'N'){
		if (s[1] == 'E') return 1;
		if (s[1] == 'W') return 7;
		return 0;
	}

	if (s[0] == 'S'){
		if (s[1] == 'E') return 3;
		if (s[1] == 'W') return 5;
		return 4;
	}

	if (s[0] == 'E') return 2;
	if (s[0] == 'W') return 6;

	return -1;
}

inline int isvalid(int x, int y){
	return (0 <= x && x < N && 0 <= y && y < M && map[x][y] == ' ');
}

int main(){
	int id[10001], i, j, T, K;
	char str[4];

	while (scanf("%d%d%d%d", &N, &M, &T, &K) == 4){
		for (i = 0; i < N; ++i) for (j = 0; j < M; ++j) map[i][j] = ' ';
		for (i = 0; i < T; ++i){
			scanf("%d%d%d", &j, &pt[i].x, &pt[i].y);
			id[j] = i;
			map[pt[i].x][pt[i].y] = '*';
		}

		while (K--){
			scanf("%d%s", &j, str); j = id[j];
			i = getdir(str);
			if (isvalid(pt[j].x + dx[i], pt[j].y + dy[i])){
				map[pt[j].x][pt[j].y] = ' ';
				pt[j].x += dx[i];
				pt[j].y += dy[i];
				map[pt[j].x][pt[j].y] = '*';
			}
		}

		for (i = 0; i < N; ++i){
			for (j = M - 1; j >= 0; --j) if (map[i][j] == '*') break;
			map[i][j + 1] = 0;
			puts(map[i]);
		}

		putchar('\n');
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
