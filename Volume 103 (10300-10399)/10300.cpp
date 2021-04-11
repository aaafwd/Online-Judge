/* @JUDGE_ID: 19899RK 10300 C++ "By Anadan" */
// Ecological Premium
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>

int main(){
	int N, M;
	double res, i, j;

	scanf("%d", &N);
	while (N--){
		scanf("%d", &M);
		res = 0.0;
		while (M--){
			scanf("%lf %*lf %lf", &i, &j);
			res += i * j;
		}

		printf("%.0lf\n", res);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
