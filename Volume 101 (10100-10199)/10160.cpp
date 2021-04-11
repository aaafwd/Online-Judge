/* @JUDGE_ID: 19899RK 10160 C++ "By Anadan" */ 
// Servicing stations
// Accepted (1.436 seconds using as much as 388 kbytes)
// Too much time !

#include <stdio.h>
#include <string.h>

int N, min, service[35];
char map[35][35], mask[35];

void doit(int i, int serv, int nonserv){
	int j;

	if (serv + nonserv == N){
		min = serv;
		return;
	}

	for (; i < N; ++i){
		if (mask[i]) continue;
		for (j = 0; j < serv; ++j){
			if (map[i][service[j]]) break;
		}

		mask[i] = 1;
		if (j < serv){
			doit(i + 1, serv, nonserv + 1);
		}else if (serv + 1 < min){
			for (j = 0; j < N; ++j){
				if (mask[j] || map[i][j] == 0) continue;
				mask[j] = 1;
				service[serv] = j;
				doit(i + 1, serv + 1, nonserv + 1);
				mask[j] = 0;
			}
		}

		service[serv] = i;
		if (serv + 1 < min) doit(i + 1, serv + 1, nonserv);

		mask[i] = 0;
		break;
	}
}

int main(){
	int M, i, j, k, u, serv, nonserv;

	while (scanf("%d%d\n", &N, &M) == 2 && N){
		memset(map, 0, sizeof(map));
		while (M--){
			scanf("%d%d\n", &i, &j); --i; --j;
			map[i][j] = map[j][i] = 1;
		}

		memset(mask, 0, N);

		serv = nonserv = 0;
		for (i = 0; i < N; ++i){
			if (mask[i]) continue;
			for (k = j = 0; j < N; ++j){
				if (map[i][j]){
					++k; u = j;
				}
			}

			if (k == 0){
				service[serv++] = i;
				mask[i] = 1;
			}else if (k == 1){
				mask[i] = 1;
				++nonserv;
				if (mask[u] == 0){
					mask[u] = 1;
					service[serv++] = u;
				}
			}
		}

		k = nonserv;
		for (i = 0; i < N; ++i){
			if (mask[i]) continue;
			for (j = 0; j < N; ++j){
				if (map[i][j] && mask[j] == 0) break;
			}

			if (j == N){
				mask[i] = 1;
				++nonserv;
			}
		}

		min = N;
		doit(0, serv, nonserv);
		printf("%d\n", min);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
