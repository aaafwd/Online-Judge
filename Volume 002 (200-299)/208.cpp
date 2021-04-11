/* @JUDGE_ID: 19899RK 208 C++ "By Anadan" */ 
// Firetruck
// Accepted (0.002 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

int N, routes, cur[400];
char map[20][20], mask[20];

void correct(int v, int u){
	int i = 0, j = 1, x, y, vertexes[20];
	char tmp[20];

	map[v][u] = map[u][v] = 0;

	memset(tmp, 0, 20);
	tmp[u] = 1;
	vertexes[0] = u;

	while (i < j){
		x = vertexes[i++];
		if (x == N){
			map[v][u] = map[u][v] = 2;
			break;
		}

		for (y = 0; y < 20; ++y){
			if (tmp[y] == 0 && map[x][y]){
				tmp[y] = 1;
				vertexes[j++] = y;
			}
		}
	}
}

void findroute(int v, int n){
	int i;

	if (v == N){
		printf("1");
		for (i = 1; i < n; ++i) printf(" %d", cur[i] + 1);
		if (N) printf(" %d", N + 1);
		putchar('\n');
		++routes;
		return;
	}

	cur[n] = v;
	mask[v] = 1;
	for (i = 0; i < 20; ++i){
		if (mask[i] == 0){
			if (map[v][i] == 1) correct(v, i);
			if (map[v][i]) findroute(i, n + 1);
		}
	}
	mask[v] = 0;
}

int main(){
	int i, j, set = 0;

	while (scanf("%d\n", &N) == 1){
		for (i = 0; i < 20; ++i) memset(map[i], 0, 20);
		while (scanf("%d%d\n", &i, &j) == 2 && i && j){
			--i; --j;
			map[i][j] = map[j][i] = 1;
		}

		routes = 0;
		memset(mask, 0, N--);
		printf("CASE %d:\n", ++set);
		findroute(0, 0);
		printf("There are %d routes from the firestation to streetcorner %d.\n", routes, N + 1);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
