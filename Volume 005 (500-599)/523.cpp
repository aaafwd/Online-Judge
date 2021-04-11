/* @JUDGE_ID: 19899RK 523 C++ "By Anadan" */ 
// Minimum Transport Cost
// Accepted (1.098 seconds using as much as 472 kbytes)

#include <stdio.h>
#define SZ 100

int map[SZ][SZ], e[SZ][SZ];

void printpath(int i, int j){
	if (i == j) return;
	while (e[i][j] != -1){
		printpath(i, e[i][j]);
		i = e[i][j];
	}
	printf("-->%d", j + 1);
}

int main(){
	int set, i, j, k, N, tax[SZ];
	char str[256], *p;

	scanf("%d\n", &set);
	while (set--){
		gets(str);
		
		for (p = str, N = 0; sscanf(p, "%d%n", &i, &j) > 0; p += j, ++N){
			map[0][N] = i;
			e[0][N] = -1;
		}

		for (i = 1; i < N; ++i){
			for (j = 0; j < N; ++j){
				scanf("%d", &map[i][j]);
				e[i][j] = -1;
			}
		}
		for (j = 0; j < N; ++j) scanf("%d", &tax[j]);


		for (k = 0; k < N; ++k){
			for (i = 0; i < N; ++i){
				if (i == k || map[i][k] == -1) continue;
				for (j = 0; j < N; ++j){
					if (j == k || map[k][j] == -1) continue;
					if (map[i][j] == -1 || map[i][j] > map[i][k] + map[k][j] + tax[k]){
						map[i][j] = map[i][k] + map[k][j] + tax[k];
						e[i][j] = k;
					}
				}
			}
		}

		k = 0;
		gets(str);
		while (gets(str) && sscanf(str, "%d%d", &i, &j) == 2){
			if (k) putchar('\n'); else k = 1;
			printf("From %d to %d :\nPath: %d", i, j, i);
			printpath(--i, --j);
			printf("\nTotal cost : %d\n", map[i][j]);
		}

		if (set) putchar('\n');
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
