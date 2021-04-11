/* @JUDGE_ID: 19899RK 10178 C++ "By Anadan" */ 
// Count the Faces
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

int N, index;
char map[52][52], indexes[52];

int getindex(char *s){
	int i;
	for (i = 0; i < index; ++i) if (indexes[i] == *s) return i;
	indexes[i] = *s;
	return index++;
}

void dowave(int v){
	int i = 0, j = 1, vertexes[52], u;

	vertexes[0] = v;
	indexes[v] = 1;
	while (i < j){
		v = vertexes[i++];
		for (u = 0; u < N; ++u){
		 	if (indexes[u] == 0 && map[v][u]){
				indexes[u] = 1;
				vertexes[j++] = u;
		 	}
		}
	}
}

int main(){
	int E, i, j, k;
	char v1[2], v2[2];

	while (scanf("%d%d\n", &N, &E) == 2){
		index = 0;
		memset(indexes, 0, N);
		for (i = 0; i < N; ++i) memset(map[i], 0, N);
		for (i = 0; i < E; ++i){
			scanf("%s %s\n", v1, v2);
			j = getindex(v1); k = getindex(v2);
			map[j][k] = map[k][j] = 1;
		}

		memset(indexes, 0, N);
		for (i = j = 0; i < N; ++i){
		   	if (indexes[i] == 0){
		   		dowave(i);
				++j;
		   	}
		}

		printf("%d\n", 1 + j - N + E);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
