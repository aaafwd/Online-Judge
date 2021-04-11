/* @JUDGE_ID: 19899RK 627 C++ "By Anadan" */ 
// The Net
// Accepted (0.006 seconds with low memory spent)

#include <stdio.h>
#include <string.h>
#define SZ 300

int index, ids[SZ], dv[SZ], map[SZ][50], e[SZ][SZ];
char path[SZ][SZ];

int getindex(int id){
	int i;
	for (i = 0; i < index; ++i) if (ids[i] == id) return i;
	ids[i] = id;
	dv[i] = 0;
	return index++;
}

void outprint(int i, int j){
	if (e[i][j] != -1) outprint(i, e[i][j]);
	if (i != j) putchar(' ');
	printf("%d", ids[j]);
}

void findpath(int src, int dst){
	int i = 0, j = 1, k, u, vertexes[SZ];
	char mask[SZ];

	if (path[src][dst]){
		if (path[src][dst] == -1) printf("connection impossible");
		else outprint(src, dst);
		return;
	}

	memset(mask, 0, index);
	vertexes[0] = src;
	mask[src] = 1;

	while (i < j){
		u = vertexes[i++];
		for (k = 0; k < dv[u]; ++k){
			if (mask[map[u][k]]) continue;
			mask[map[u][k]] = 1;
			vertexes[j++] = map[u][k];
			path[src][map[u][k]] = 1;
			e[src][map[u][k]] = u;
		}
	}

	for (i = 0; i < index; ++i){
		if (path[src][i] == 0) path[src][i] = -1;
	}

	if (path[src][dst] == -1) printf("connection impossible");
	else outprint(src, dst);
}

int main(){
	int N, i, j;
	char str[128], *p;

	while (scanf("%d\n", &N) == 1){
		index = 0;
		while (N--){
			scanf("%d%s\n", &i, str);
			i = getindex(i);

			p = strtok(str + 1, ",");
			while (p){
				sscanf(p, "%d", &j);
				map[i][dv[i]++] = getindex(j);
				p = strtok(NULL, ",");
			}
		}

		for (i = 0; i < index; ++i){
			memset(path[i], 0, index);
			for (j = 0; j < index; ++j) e[i][j] = -1;
		}

		printf("-----\n");
		scanf("%d\n", &N);
		while (N--){
			scanf("%d%d\n", &i, &j);
			i = getindex(i); j = getindex(j);

			if (i == j){
				printf("%d\n", ids[i]);
				continue;
			}

			findpath(i, j);
			putchar('\n');
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
