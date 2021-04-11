/* @JUDGE_ID: 19899RK 10470 C++ "By Anadan" */ 
// Shifted Coefficient Number System
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>

int B, L, c[15], index;

int presentable(int N){
	index = 0;
	while (N){
		if (index >= 15) return 0;
		c[index] = (N - L + (B << 16)) % B + L;
		if (c[index] < L || c[index] >= L + B) return 0;
		N = (N - c[index++]) / B;
	}

	return 1;
}

int main(){
	int set = 0, N;

	while (scanf("%d%d%d\n", &B, &L, &N) == 3){
		printf("CASE# %d:\n", ++set);
		if (presentable(N)){
			while (index--){
				if (c[index] >= 0) putchar('+');
				printf("%d*%d^%d", c[index], B, index);
			}

			printf(" = %d\n", N);

		}else printf("NOT REPRESENTABLE\n");
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
