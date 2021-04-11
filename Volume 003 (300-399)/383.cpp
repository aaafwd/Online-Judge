/* @JUDGE_ID: 19899RK 383 C++ "By Anadan" */
// Shipping Routes
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

char names[30][3];

int getindex(char *s){
	int i;
	for (i = 0; strcmp(s, names[i]); ++i);
	return i;
}

int main(){
	int set, dataset, N, M, P, i, j, k;
	char map[30][30], n1[3], n2[3];

	scanf("%d\n", &set);
	printf("SHIPPING ROUTES OUTPUT\n\n");
	for (dataset = 1; dataset <= set; ++dataset){
		printf("DATA SET %2d\n\n", dataset);
		scanf("%d%d%d\n", &N, &M, &P);
		for (i = 0; i < N; ++i) scanf("%s", names[i]);
		for (i = 0; i < N; ++i) memset(map[i], -1, N);
		for (i = 0; i < M; ++i){
			scanf("%s%s\n", n1, n2);
			j = getindex(n1);
			k = getindex(n2);
			map[j][k] = map[k][j] = 1;
		}

		for (k = 0; k < N; ++k){
			for (i = 0; i < N; ++i){
				if (i == k || map[i][k] == -1) continue;
				for (j = 0; j < N; ++j){
					if (j == k || map[k][j] == -1) continue;
					if (map[i][j] == -1 || map[i][j] > map[i][k] + map[k][j])
						map[i][j] = map[i][k] + map[k][j];
				}
			}
		}

		for (i = 0; i < P; ++i){
			scanf("%d %s %s\n", &M, n1, n2);
			j = getindex(n1);
			k = getindex(n2);
			if (map[j][k] == -1) printf("NO SHIPMENT POSSIBLE\n");
			else printf("$%d00\n", M * map[j][k]);
		}

		putchar('\n');
	}

	printf("END OF OUTPUT\n");

	return 0;
}
/* @END_OF_SOURCE_CODE */
