/* @JUDGE_ID: 19899RK 10081 C++ "By Anadan" */ 
// Tight words
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>

int main(){
	int i, j, k, n;
	double w1[12], w2[12], res;

	while (scanf("%d%d", &k, &n) == 2){
		if (n == 1) printf("100.00000\n");
		else{
			++k;
			for (i = 1; i <= k; i++) w1[i] = w2[i] = 1.0;
			for (i = 1; i < n; i++){
				for (j = 1; j <= k; j++){
					w2[j - 1] += w1[j];
					w2[j + 1] += w1[j];
				}
				for (j = 1; j <= k; j++) w1[j] = w2[j];
			}

			for (j = 1, res = 0.0; j <= k; j++) res += w1[j];
			for (i = 0; i < n; i++) res /= double(k);
			printf("%.5lf\n", res * 100.0);
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
