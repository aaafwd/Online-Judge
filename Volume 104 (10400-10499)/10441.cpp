/* @JUDGE_ID: 19899RK 10441 C++ "By Anadan" */
// Catenyms
// Accepted (0.018 seconds with low memory spent)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int N, map[26][26], lens[1000], indexes[26];
char dict[1000][21], mask[1000];

int sort_function(const void *a, const void *b){
	return strcmp((char *)a, (char *)b);
}

int isbridge(int v, int u){
	int i = 0, j = 1, k, m, vertexes[26];
	char vmask[26];

	if (u == v) return 0;

	memset(vmask, 0, 26);
	vmask[u] = 1;
	vertexes[0] = u;

	while (i < j){
		k = vertexes[i++];
		if (k == v) break;
		for (m = 0; m < 26; ++m){
			if (vmask[m] == 0 && map[k][m]){
				vmask[m] = 1;
				vertexes[j++] = m;
			}
		}
	}

	return (vmask[v] == 0);
}

int connected(){
	int i = 0, j = 1, u, v, vertexes[26];
	char vmask[26];

	for (u = 0; u < 26; ++u) if (indexes[u]) break;
	memset(vmask, 0, 26);
	vmask[u] = 1;
	vertexes[0] = u;

	while (i < j){
		u = vertexes[i++];
		for (v = 0; v < 26; ++v){
			if (vmask[v] == 0 && (map[u][v] || map[v][u])){
				vmask[v] = 1;
				vertexes[j++] = v;
			}
		}
	}

	for (i = 0; i < 26; ++i) if (vmask[i] == 0 && indexes[i]) return 0;
	return 1;
}

int main(){
	int set, i, j, k, u, v, out, sum[26];

	scanf("%d\n", &set);
	while (set--){
		scanf("%d\n", &N);
		memset(map, 0, sizeof(map));
		memset(sum, 0, sizeof(sum));
		memset(indexes, 0, sizeof(indexes));
		for (i = 0; i < N; ++i){
			scanf("%s\n", dict[i]);
			j = strlen(dict[i]) - 1;
			indexes[dict[i][0] - 'a'] = indexes[dict[i][j] - 'a'] = 1;
			++map[dict[i][0] - 'a'][dict[i][j] - 'a'];
			++sum[dict[i][0] - 'a']; --sum[dict[i][j] - 'a'];
		}

		u = v = -1;
		for (i = 0; i < 26; ++i){
			if (sum[i] != 0){
				if (sum[i] == 1 && u == -1) u = i;
				else if (sum[i] == -1 && v == -1) v = i;
				else break;
			}
		}

		if (i < 26 || !connected()) printf("***\n");
		else{
			out = 0;
			qsort(dict, N, sizeof(dict[0]), sort_function);
			for (i = 0; i < 26; ++i) indexes[i] = -1;
			for (i = 0; i < N; ++i){
				if (indexes[dict[i][0] - 'a'] == -1) indexes[dict[i][0] - 'a']  = i;
			}

			if (u == -1) u = dict[0][0] - 'a';
			memset(mask, 0, sizeof(mask));
			for (i = 0; i < N; ++i) lens[i] = strlen(dict[i]) - 1;

			for (i = 0; i < N; ++i){
				while (mask[indexes[u]] != 0) ++indexes[u];
				j = indexes[u];
				while (1){
					while (mask[j]) ++j;
					v = dict[j][lens[j]] - 'a';
					if (map[u][v]){
						for (k = 0; k < 26; ++k){
							if (map[u][k] && !isbridge(u, k)) break;
						}
						if (k == 26 || k == v) break;
						if (k < v && !isbridge(u, v)) break;
					}

					++j;
				}

				mask[j] = 1;
				if (out) putchar('.'); else out = 1;
				printf("%s", dict[j]);
				--map[u][v];
				u = v;
			}

			putchar('\n');
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
