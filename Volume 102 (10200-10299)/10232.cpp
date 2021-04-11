/* @JUDGE_ID: 19899RK 10232 C++ "By Anadan" */ 
// Bit-wise Sequence
// Accepted (0.002 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

int main(){
	int C[32][32], i, j, k, res;

	memset(C, 0, sizeof(C));
	C[0][0] = C[1][0] = C[1][1] = 1;
	for (i = 2; i <= 31; ++i){
		C[i][0] = C[i][i] = 1;
		for (j = 1; j < i; ++j) C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
	}

	while (scanf("%d\n", &j) == 1){
		if (j == 0) printf("0\n");
		else{
			for (k = 1; C[31][k] < j; ++k) j -= C[31][k];

			i = 30;
			res = 0;
			while (k){
				while (C[i][k] >= j) --i;
				res |= (1 << i);
				j -= C[i][k];
				++i; --k;
			}

			printf("%d\n", res);
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
