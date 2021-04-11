/* @JUDGE_ID: 19899RK 10000 C++ "By Anadan" */
// Longest Paths
// Accepted (0.137 seconds using as much as 404 kbytes)

#include <stdio.h>
#include <string.h>

int N, path[100], sp[100], fin[100];
char map[100][100], mask[100];

int getpath(int s){
	int i, tmp;

	if (path[s] != -1) return path[s];
	path[s] = 0;
	fin[s] = s;

	for (i = 0; i < sp[s]; ++i){
		tmp = getpath(map[s][i]) + 1;
		if (path[s] < tmp){
			path[s] = tmp;
			fin[s] = fin[map[s][i]];
		}else if (path[s] == tmp && fin[s] > fin[map[s][i]]){
			fin[s] = fin[map[s][i]];
		}
	}

	return path[s];
}

int main(){
	int s, i, j, set = 0;

	while (scanf("%d", &N) == 1 && N){
		scanf("%d", &s); --s;
		for (i = 0; i < N; ++i){
			sp[i] = 0;
			path[i] = -1;
		}

		while (scanf("%d%d", &i, &j) == 2){
			if (i == 0 && j == 0) break;
			if (i-- != j--) map[i][sp[i]++] = j;
		}

		getpath(s);
		printf("Case %d: The longest path from %d has length %d, finishing at %d.\n\n", ++set, s + 1, path[s], fin[s] + 1);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
