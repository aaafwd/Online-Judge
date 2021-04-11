/* @JUDGE_ID: 19899RK 10525 C++ "By Anadan" */ 
// NEW TO BANGLADESH?
// Accepted (0.002 seconds with low memory spent)

#include <stdio.h>
#include <string.h>
#define SZ 100

int N, t[SZ][SZ], d[SZ][SZ];

int main(){
	int set, i, j, k, l, Q;

	scanf("%d", &set);
	while (set--){
		scanf("%d%d", &N, &Q);
		for (i = 0; i < N; ++i){
			for (j = 0; j < N; ++j){
				t[i][j] = -1;
			}

			t[i][i] = d[i][i] = 0;
		}

		while (Q--){
			scanf("%d%d%d%d", &i, &j, &k, &l); --i; --j;
//			if (t[i][j] == -1 || t[i][j] > k){
				t[i][j] = t[j][i] = k;
				d[i][j] = d[j][i] = l;
//			}
		}

		for (k = 0; k < N; ++k){
			for (i = 0; i < N; ++i){
				if (i == k || t[i][k] == -1) continue;
				for (j = 0; j < N; ++j){
					if (j == k || t[k][j] == -1) continue;

					if (t[i][j] == -1 || t[i][j] > t[i][k] + t[k][j] || ((t[i][j] == t[i][k] + t[k][j]) && (d[i][j] > d[i][k] + d[k][j]))){
						t[i][j] = t[i][k] + t[k][j];
						d[i][j] = d[i][k] + d[k][j];
					}
				}
			}
		}

		scanf("%d", &Q);
		while (Q--){
			scanf("%d%d", &i, &j); --i; --j;
			if (t[i][j] == -1) puts("No Path.");
			else printf("Distance and time to reach destination is %d & %d.\n", d[i][j], t[i][j]);
		}

		if (set) putchar('\n');
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
