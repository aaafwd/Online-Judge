/* @JUDGE_ID: 19899RK 115 C++ "By Anadan" */
// Climbing Trees
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>
#include <string.h>
#define INF (-30000)
#define MAX 300

int N = 0;
int map[MAX][MAX];
char names[MAX][31];

int getindex(char *str){
	int i;
	for (i = 0; i < N; ++i) if (!strcmp(names[i], str)) return i;
	strcpy(names[N], str);
	return N++;
}

int main(){
	int i, j, p, q, r, tmp;
	char str1[31], str2[31];

	for (i = 0; i < MAX; ++i) for (j = 0; j < MAX; ++j)
		map[i][j] = INF;

	while (scanf("%s %s\n", str1, str2) == 2 && strcmp(str1, "no.child")){
		p = getindex(str2); q = getindex(str1);
		map[p][q] = 1;
		map[q][p] = -1;

		for (i = 0; i < N; ++i){
			if (map[q][i] > 0) map[p][i] = map[q][i] + 1;
			if (map[p][i] != INF && map[p][i] < 0)
				map[q][i] = map[p][i] - 1;
		}

		for (i = 0; i < N; ++i){
			if (map[i][p] != INF && map[i][p] > 0){
				map[i][q] = map[i][p] + 1;
				for (j = 0; j < N; ++j){
					if (map[q][j] != INF && map[q][j] > 0){
						map[i][j] = map[i][p] + 1 + map[q][j];
					}
				}
			}

			if (map[i][q] != INF && map[i][q] < 0){
				map[i][p] = map[i][q] - 1;
				for (j = 0; j < N; ++j){
					if (map[p][j] != INF && map[p][j] < 0){
						map[i][j] = map[i][q] - 1 + map[p][j];
					}
				}
			}
		}
	}

	while (scanf("%s %s\n", str1, str2) == 2){
		p = getindex(str1); q = getindex(str2);
		if (map[p][q] == INF){
			j = -INF;
			for (i = 0; i < N; ++i){
				if (map[i][p] > 0 && map[i][q] > 0){
					tmp = map[i][p];
					if (tmp > map[i][q]) tmp = map[i][q];
					if (j > tmp){
						j = tmp;
						r = map[i][p] - map[i][q];
						if (r < 0) r = -r;
					}
				}
			}

			if (j == -INF) printf("no relation\n");
			else if (j == 1 && r == 0)printf("sibling\n");
			else{
				printf("%d cousin", j - 1);
				if (r) printf(" removed %d", r);
				printf("\n");
			}
		}else{
			if (map[p][q] > 0) j = map[p][q];
			else j = -map[p][q];
			for (i = 0; i < j - 2; ++i) printf("great ");
			if (j > 1) printf("grand ");
			if (map[p][q] > 0) printf("parent\n");
			else printf("child\n");
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
