/* @JUDGE_ID: 19899RK 662 C++ "By Anadan" */ 
// Fast Food
// Accepted (1.424 seconds using as much as 436 kbytes)
// Too much time !

#include <stdio.h>

int main(){
	int set = 0, N, L, i, j, k, m, min, cur;
	static int d[200], map[31][200], e[30][200], depot[30][3];

	while (scanf("%d%d\n", &N, &L) == 2 && N){
		for (i = 0; i < N; ++i) scanf("%d\n", d + i);

		map[0][0] = 0;
		for (i = 1; i < N; ++i){
			map[0][i] = map[0][i - 1] + i * (d[i] - d[i - 1]);
		}

		for (k = 1; k < L; ++k){
			for (i = k; i < N; ++i){
				min = -1;
				for (j = k - 1; j < i; ++j){
					cur = map[k - 1][j];
					for (m = j + 1; m < i; ++m){
						if (d[m] - d[j] < d[i] - d[m]) cur += d[m] - d[j];
						else cur += d[i] - d[m];
					}

					if (min == -1 || min > cur){
						min = cur;
						e[k][i] = j;
					}
				}
				map[k][i] = min;
			}
		}

		m = N - 1;
		min = map[k][N - 1] = map[k - 1][N - 1];
		for (i = N - 2, j = 0; i >= L - 1; --i){
			j += (N - 1 - i) * (d[i + 1] - d[i]);
			map[k][i] = map[k - 1][i] + j;
			if (min > map[k][i]){
				min = map[k][i];
				m = i;
			}
		}

		depot[L - 1][0] = m;
		depot[L - 1][2] = N - 1;
		for (k = L - 2; k >= 0; --k){
			j = depot[k][0] = e[k + 1][m];
			for (i = j; i < m; ++i){
				if (d[i] - d[j] > d[m] - d[i]) break;
			}
			depot[k + 1][1] = i;
			depot[k][2] = i - 1;
			m = j;
		}
		depot[0][1] = 0;

		printf("Chain %d\n", ++set);
		for (k = 0; k < L; ++k){
			printf("Depot %d at restaurant %d serves restaurant", k + 1, depot[k][0] + 1);
			if (depot[k][1] == depot[k][2]) printf(" %d\n", depot[k][1] + 1);
			else printf("s %d to %d\n", depot[k][1] + 1, depot[k][2] + 1);
		}
		printf("Total distance sum = %d\n\n", min);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
