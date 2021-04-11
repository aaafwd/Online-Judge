/* @JUDGE_ID: 19899RK 10199 C++ "By Anadan" */ 
// Tourist Guide
// Accepted (0.148 seconds using as much as 412 kbytes)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int N;
struct City{
	int i;
	char name[31];
}pt[100];
char map[100][100];

int sort_function(const void *a, const void *b){
	return strcmp(((City *)a)->name, ((City *)b)->name);
}

int needcamera(int v){
	int i = 0, j = 1, k = v, u, vertexes[100];
	char mask[100];

	for (u = 0; u < N; ++u) if (map[v][u] && u != v) break;
	if (u == N) return 0;

	memset(mask, 0, N);
	mask[v] = mask[u] = 1;
	vertexes[0] = u;

	while (i < j){
		v = vertexes[i++];
		for (u = 0; u < N; ++u){
			if (mask[u] == 0 && map[v][u]){
				mask[u] = 1;
				vertexes[j++] = u;
			}
		}
	}

	for (u = 0; u < N; ++u) if (map[k][u] && mask[u] == 0) return 1;
	return 0;
}

int main(){
	int set = 0, i, tot;
	char cameras[100];
	City s1, s2, *p1, *p2;

	while (scanf("%d\n", &N) == 1 && N){
		for (i = 0; i < N; ++i){
			scanf("%s\n", pt[i].name);
			memset(map[i], 0, N);
		}
		qsort(pt, N, sizeof(City), sort_function);
		for (i = 0; i < N; ++i) pt[i].i = i;

		scanf("%d\n", &i);
		while (i--){
			scanf("%s%s\n", s1.name, s2.name);
			p1 = (City *)bsearch(&s1, pt, N, sizeof(City), sort_function);
			p2 = (City *)bsearch(&s2, pt, N, sizeof(City), sort_function);
			map[p1->i][p2->i] = map[p2->i][p1->i] = 1;
		}

		memset(cameras, 0, N);
		for (tot = i = 0; i < N; ++i){
			if (needcamera(i)){
				cameras[i] = 1;
				++tot;
			}
		}

		if (set) putchar('\n');
		printf("City map #%d: %d camera(s) found\n", ++set, tot);
		for (i = 0; i < N; ++i) if (cameras[i]) printf("%s\n", pt[i].name);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
