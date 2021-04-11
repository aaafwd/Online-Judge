/* @JUDGE_ID: 19899RK 10264 C++ "By Anadan" */ 
// The Most Potent Corner
// Accepted (0.045 seconds with low memory spent)

#include <stdio.h>
#define SZ 16384

int main(){
	int N, i, j, x, y, max, w[SZ], pot[SZ], *p;

	while (scanf("%d\n", &N) == 1){
		j = 1 << N;
		for (p = w, i = 0; i < j; ++i, ++p) scanf("%d", p);
		for (i = 0; i < j; ++i){
			pot[i] = 0;
			for (y = 1, x = 0; x < N; ++x, y <<= 1){
				pot[i] += w[i ^ y];
			}
		}

		for (max = i = 0; i < j; ++i){
			for (y = 1, x = 0; x < N; ++x, y <<= 1){
				if (max < pot[i] + pot[i ^ y]){
					max = pot[i] + pot[i ^ y];
				}
			}
		}

		printf("%d\n", max);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
