/* @JUDGE_ID: 19899RK 10524 C++ "By Anadan" */ 
// Matrix Reloaded
// Accepted (0.002 seconds with low memory spent)

#include <stdio.h>
#include <math.h>
#define SZ 100

double map[SZ][SZ], tmp[SZ][SZ];

double getdet(int N){
	int i, j, k;
	double det = 1.0, t;

	for (i = 0; i < N; ++i){
		if (fabs(tmp[i][i]) < 1e-12) return 0.0;

		for (j = i + 1; j < N; ++j){
			if (fabs(tmp[j][i]) < 1e-12) continue;
			t = - tmp[j][i] / tmp[i][i];
			for (k = i; k < N; ++k){
				tmp[j][k] += t * tmp[i][k];
			}
		}

		det *= tmp[i][i];
	}

	return det;
}

int main(){
	int N, i, j, k, m;
	double det, t;

	while (scanf("%d", &N) == 1 && N){
		for (i = 0; i < N; ++i) for (j = 0; j < N; ++j){
			scanf("%lf", &map[i][j]);
			tmp[i][j] = map[i][j];
		}

		det = getdet(N);
		if (fabs(det) < 1e-12){
			puts("Not possible\n");
			continue;
		}

		for (i = 0; i < N; ++i){
			for (j = 0; j < N; ++j){
				if (j) putchar(' ');
				for (k = 0; k < N; ++k){
					if (k == j) continue;
					for (m = 0; m < N; ++m){
						if (m == i) continue;
						tmp[(k < j) ? (k) : (k - 1)][(m < i) ? (m) : (m - 1)] = map[k][m];
					}
				}

				t = getdet(N - 1);
				if ((i + j) & 1) t = -t;
				printf("%.6lf", t / det);
			}

			putchar('\n');
		}

		putchar('\n');
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
