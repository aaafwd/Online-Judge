/* @JUDGE_ID: 19899RK 302 C++ "By Anadan" */
// John`s trip
// Accepted (0.160 seconds using as much as 424 kbytes)

#include <stdio.h>
#include <string.h>

int map[44][44], N, M;
struct Street{
	int x, y;
	char passed;
}st[1995];

int ispath(int v, int w){
	char mask[44];
	int vertexes[44], i = 0, j = 1, k;

	vertexes[0] = v;
	memset(mask, 0, M);
	mask[v] = 1;

	while (i < j){
		v = vertexes[i++];
		for (k = 0; k < M; ++k){
			if (mask[k] || map[v][k] == 0) continue;
			if (k == w) return 1;
			vertexes[j++] = k;
			mask[k] = 1;
		}
	}

	return 0;
}

void func(int v){
	char flag = 0;
	int i, w, rest = N, bridge, wb;

	while (rest--){
		bridge = -1;
		for (i = 0; i < N; ++i){
			if (st[i].passed) continue;
			if (st[i].x == v) w = st[i].y;
			else if (st[i].y == v) w = st[i].x;
			else continue;
			--map[v][w];
			--map[w][v];
			if (v == w || ispath(v, w)){
				st[i].passed = 1;
				v = w;
				if (flag) printf(" %d", i + 1);
				else{
					flag = 1;
					printf("%d", i + 1);
				}
				break;
			}
			++map[v][w];
			++map[w][v];
			if (bridge == -1){
				bridge = i;
				wb = w;
			}
		}

		if (i == N){
			if (flag) printf(" %d", bridge + 1);
			else{
				flag = 1;
				printf("%d", bridge + 1);
			}
			--map[v][wb];
			--map[wb][v];
			st[bridge].passed = 1;
			v = wb;
		}
	}

	printf("\n\n");
}

int main(){
	int x, y, z, i, v, edges[44];

	while (1){
		for (i = 0; i < 1995; ++i){
			st[i].x = st[i].y = 0;
			st[i].passed = 1;
		}

		for (i = 0; i < 44; ++i){
			memset(map[i], 0, sizeof(int) * 44);
			edges[i] = 0;
		}

		N = M = 0;
		while (scanf("%d%d", &x, &y) == 2){
			if (x == 0 && y == 0) break;
			scanf("%d", &z);
			--x; --y; --z;
			if (x > y) x ^= y ^= x ^= y;
			st[z].x = x; st[z].y = y; st[z].passed = 0;
			if (y > M) M = y;

			++map[x][y];
			++map[y][x];

			++edges[x];
			++edges[y];
			if (N == 0) v = x;
			++N;
		}

		++M;

		if (!N) break;
		for (i = 0; i < 44; ++i) if (edges[i] & 1) break;
		if (i < 44) printf("Round trip does not exist.\n\n");
		else func(v);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
