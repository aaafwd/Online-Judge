/* @JUDGE_ID: 19899RK 710 C++ "By Anadan" */ 
// The Game
// Accepted (0.040 seconds using as much as 504 kbytes)

#include <stdio.h>
#include <string.h>

int w, h;
char map[79][79];

struct Point{
	int x, y;
	int operator == (Point pt) { return ((pt.x == x) && (pt.y == y)); }
}p1, p2;

int getpath(){
	int i, N1, N2, steps = 0, tmp;
	char flags[79][79];
	Point w1[6400], w2[6400];

	for (i = 0; i < h + 3; i++) memset(flags[i], 0, w + 3);

	N1 = 1;
	w1[0] = p1;
	flags[p1.y][p1.x] = 1;
	while (N1){
		N2 = 0;
		++steps;
		for (i = 0; i < N1; i++){
			tmp = w1[i].x;
			while (!map[w1[i].y][++w1[i].x]){
				if (w1[i] == p2) return steps;
				if (!flags[w1[i].y][w1[i].x]){
					flags[w1[i].y][w1[i].x] = 1;
					w2[N2++] = w1[i];
				}
			}

			w1[i].x = tmp;
			while (!map[w1[i].y][--w1[i].x]){
				if (w1[i] == p2) return steps;
				if (!flags[w1[i].y][w1[i].x]){
					flags[w1[i].y][w1[i].x] = 1;
					w2[N2++] = w1[i];
				}
			}
			w1[i].x = tmp;

			tmp = w1[i].y;
			while (!map[++w1[i].y][w1[i].x]){
				if (w1[i] == p2) return steps;
				if (!flags[w1[i].y][w1[i].x]){
					flags[w1[i].y][w1[i].x] = 1;
					w2[N2++] = w1[i];
				}
			}

			w1[i].y =  tmp;
			while (!map[--w1[i].y][w1[i].x]){
				if (w1[i] == p2) return steps;
				if (!flags[w1[i].y][w1[i].x]){
					flags[w1[i].y][w1[i].x] = 1;
					w2[N2++] = w1[i];
				}
			}
		}

		N1 = N2;
		memcpy(w1, w2, N1 * sizeof(Point));
	}

	return 0;
}

int main(){
	char str[80];
	int set = 0, pair, i, j, steps;

	for (i = 0; i < 79; i++) map[0][i] = map[i][0] = 1;
	while (gets(str)){
		sscanf(str, "%d%d", &w, &h);
		if (w == 0) break;
		printf("Board #%d:\n", ++set);

		for (i = 0; i < h; i++){
			gets(str);
			for (j = 0; j < w; j++){
				if (str[j] == ' ') map[i + 2][j + 2] = 0;
				else map[i + 2][j + 2] = 1;
			}
			map[i + 2][j + 2] = map[i + 2][1] = 0;
			map[i + 2][j + 3] = 1;
		}

		for (j = 1; j <= w + 2; j++){
			map[1][j] = map[h + 2][j] = 0;
			map[h + 3][j] = 1;
		}
		map[1][j] = map[h + 2][j] = map[h + 3][j] = 1;

		pair = 0;
		while (1){
			scanf("%d %d %d %d\n", &p1.x, &p1.y, &p2.x, &p2.y);
			if (p1.x == 0) break;
			++p1.x; ++p1.y; ++p2.x; ++p2.y;
			map[p2.y][p2.x] = 0;
			printf("Pair %d: ", ++pair);
			steps = getpath();
			if (steps) printf("%d segments.\n", steps);
			else printf("impossible.\n");
			map[p2.y][p2.x] = 1;
		}

		putchar('\n');
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
