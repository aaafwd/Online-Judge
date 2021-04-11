/* @JUDGE_ID: 19899RK 542 C++ "By Anadan" */ 
// France '98
// Accepted (0.002 seconds with low memory spent)

#include <stdio.h>

int main(){
	int i, j, k, c = 0;
	char names[16][11];
	double p[16][16], w[2][16], tmp;

	for (i = 0; i < 16; ++i) gets(names[i]);
	for (i = 0; i < 16; ++i) for (j = 0; j < 16; ++j){
		scanf("%lf", &p[i][j]);
		p[i][j] *= 0.01;
	}

	for (i = 0; i < 16; i += 2){
		w[0][i] = p[i][i + 1];
		w[0][i + 1] = p[i + 1][i];
	}

	for (i = 0; i < 16; i += 4){
		for (j = i; j < i + 2; ++j){
			tmp = 0.0;
			for (k = i + 2; k < i + 4; ++k){
				tmp += w[c][k] * p[j][k];
			}
			w[c ^ 1][j] = w[c][j] * tmp;
		}

		for (; j < i + 4; ++j){
			tmp = 0.0;
			for (k = i; k < i + 2; ++k){
				tmp += w[c][k] * p[j][k];
			}
			w[c ^ 1][j] = w[c][j] * tmp;
		}
	}
	c ^= 1;

	for (i = 0; i < 16; i += 8){
		for (j = i; j < i + 4; ++j){
			tmp = 0.0;
			for (k = i + 4; k < i + 8; ++k){
				tmp += w[c][k] * p[j][k];
			}
			w[c ^ 1][j] = w[c][j] * tmp;
		}

		for (; j < i + 8; ++j){
			tmp = 0.0;
			for (k = i; k < i + 4; ++k){
				tmp += w[c][k] * p[j][k];
			}
			w[c ^ 1][j] = w[c][j] * tmp;
		}
	}
	c ^= 1;

	for (j = 0; j < 8; ++j){
		tmp = 0.0;
		for (k = 8; k < 16; ++k){
			tmp += w[c][k] * p[j][k];
		}
		w[c ^ 1][j] = w[c][j] * tmp;
	}

	for (; j < 16; ++j){
		tmp = 0.0;
		for (k = 0; k < 8; ++k){
			tmp += w[c][k] * p[j][k];
		}
		w[c ^ 1][j] = w[c][j] * tmp;
	}
	c ^= 1;

	for (i = 0; i < 16; ++i){
		printf("%-10s p=%.2lf%%\n", names[i], w[c][i] * 100.0);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
