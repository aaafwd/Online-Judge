/* @JUDGE_ID: 19899RK 544 C++ "By Anadan" */ 
// Heavy Cargo
// Accepted (0.057 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

int index, N;
char names[200][31];
int map[200][200];

int getindex(char *str){
	int i;
	for (i = 0; i < index; ++i) if (!strcmp(names[i], str)) return i;
	strcpy(names[i], str);
	return index++;
}

int maxpath(int src, int dst){
 	int path[200], mask[200], i, j, k, cur = 1, max = 0;
 	char changed;

	for (i = 0; i < N; ++i) path[i] = mask[i] = 0;
	mask[src] = 1;

	changed = 1;
	while (changed){
		changed = 0;
	 	for (i = 0; i < N; ++i){
	 		if (i == dst) continue;
	 	 	if (mask[i] == cur){
	 	 		if (i != src && path[i] <= max) continue;
				for (j = 0; j < N; ++j){
				  	if (map[i][j] == 0 || j == src) continue;
				  	k = map[i][j];
				  	if (i != src && k > path[i]) k = path[i];
					if (path[j] >= k) continue;
					path[j] = k;
					mask[j] = cur + 1;
					changed = 1;
				}

				max = path[dst];
	 	 	}
	 	}
		++cur;
	}

	return max;
}

int main(){
	int set = 0, R, i, j, k;
	char str1[31], str2[31];

	while (scanf("%d%d\n", &N, &R) == 2 && N){
		index = 0;
		for (i = 0; i < N; ++i) for (j = 0; j < N; ++j) map[i][j] = -1;
		while (R--){
			scanf("%s %s %d\n", str1, str2, &k);
			i = getindex(str1);
			j = getindex(str2);
			map[i][j] = map[j][i] = k;
		}

		scanf("%s%s\n", str1, str2);
		i = getindex(str1);
		j = getindex(str2);
		k = maxpath(i, j);

		printf("Scenario #%d\n%d tons\n\n", ++set, k);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
