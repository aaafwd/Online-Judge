/* @JUDGE_ID: 19899RK 684 C++ "By Anadan" */ 
// Integral Determinant
// Accepted (0.416 seconds using as much as 396 kbytes)

#include <stdio.h>
#include <math.h>

int N;
double a[30][30];

double determinant(){
	int i, j, k;
	double det = 1.0, tmp;

	for (i = 0; i < N; ++i){
		for (j = i; j < N; ++j) if (fabs(a[j][i]) > 1e-12) break;
		if (j >= N) return 0.0;
		if (j != i){
			for (k = i; k < N; ++k){
				tmp = a[i][k];
				a[i][k] = a[j][k];
				a[j][k] = tmp;
			}
			det = -det;
		}

		for (j = i + 1; j < N; ++j){
			if (fabs(a[j][i]) < 1e-12) continue;
			tmp = -a[j][i] / a[i][i];
			for (k = i + 1; k < N; ++k){
				a[j][k] += tmp * a[i][k];
			}
		}

		det *= a[i][i];
	}

	return det;
}

int main(){
	int i, j;
	double det;

	while (scanf("%d\n", &N) == 1 && N){
		for (i = 0; i < N; ++i) for (j = 0; j < N; ++j){
			scanf("%lf", &a[i][j]);
		}
		det = determinant();
		if (fabs(det) < 1e-12) det = 0.0;
		printf("%.0lf\n", det);
	}
	printf("*\n");

	return 0;
}
/* @END_OF_SOURCE_CODE */
