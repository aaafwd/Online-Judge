/* @JUDGE_ID: 19899RK 585 C++ "By Anadan" */
// Triangles
// Accepted (0.010 seconds with low memory spent)

#include <stdio.h>

int main(){
	int i, j, N, h[200], set = 0, res;
	char map[100][200];

	while (scanf("%d\n", &N) == 1 && N){
		for (i = 0; i < N; ++i) scanf("%s\n", map[i]);
		for (res = i = 0; i < 2*N - 1; ++i)
			if (map[0][i] == '-') res = h[i] = 1; else h[i] = 0;

		for (i = 1; i < N; ++i){
			for (j = 0; j < 2*(N - i) - 1; j += 2){
				if (map[i][j] == '-'){
					if (map[i - 1][j + 1] == '-'){
						if (h[j] <= h[j + 2]) ++h[j];
						else h[j] = 1 + h[j + 2];
					}else h[j] = 1;
					if (res < h[j]) res = h[j];
				}else h[j] = 0;
			}
		}

		for (i = N - 2; i >= 0; --i){
			j = 2*(N - i) - 3;
			if (map[i][j] == '-') h[j] = 1; else h[j] = 0;
			if (res == 0 && h[j]) res = 1;

			for (j -= 2; j > 1; j -= 2){
				if (map[i][j] == '-'){
					if (map[i + 1][j - 1] == '-'){
						if (h[j] <= h[j - 2]) ++h[j];
						else h[j] = 1 + h[j - 2];
					}else h[j] = 1;
					if (res < h[j]) res = h[j];
				}else h[j] = 0;
			}

			if (map[i][1] == '-') h[1] = 1; else h[1] = 0;
			if (res == 0 && h[1]) res = 1;
		}

		printf("Triangle #%d\nThe largest triangle area is %d.\n\n", ++set, res * res);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
