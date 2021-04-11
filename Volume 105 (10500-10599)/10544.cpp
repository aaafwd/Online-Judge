/* @JUDGE_ID: 19899RK 10544 C++ "By Anadan" */
// Numbering the Paths
// Accepted (0.002 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

int path[26], N;
char map[26][26];

int calcpath(int v){
	int i;

	if (path[v] != -1) return path[v];

	path[v] = 0;
	for (i = 0; i < N; ++i){
		if (map[v][i]) path[v] += calcpath(i);
	}

	if (path[v] == 0) path[v] = 1;

	return path[v];
}

void outnumber(char *s){
	int i, u, v, res = 0;

	u = *s++ - 'A';
	while (*s){
		v = *s++ - 'A';
		for (i = 0; i < v; ++i) if (map[u][i]) res += path[i];
		u = v;
	}

	printf("%d\n", res + 1);
}

int main(){
	int set, i, M;
	char str[32];

	scanf("%d", &set);
	while (set--){
		scanf("%d%d", &N, &M);
		for (i = 0; i < N; ++i) memset(map[i], 0, N);
		while (M--){
			scanf("%s", str);
			map[str[0] - 'A'][str[1] - 'A'] = 1;
		}

		for (i = 0; i < N; ++i) path[i] = -1;
		for (i = 0; i < N; ++i) if (path[i] == -1) calcpath(i);

		scanf("%d", &M);
		while (M--){
			scanf("%s", str);
			printf("%s: ", str);
			outnumber(str);
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
