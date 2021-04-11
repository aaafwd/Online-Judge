/* @JUDGE_ID: 19899RK 10598 C++ "By Anadan" */
// Find the Latitude
// Accepted (0.004 seconds with low memory spent)

#include <stdio.h>
#include <math.h>

int main(){
	int set = 0, R, N, k;
	double tmp;
	const double pi = acos(0) * 2;

	while (scanf("%d%d", &R, &N) == 2 && R){
		printf("Case %d:\n", ++set);
		for (k = 1; k <= 10; ++k){
			tmp = acos(N / pi / R / k * 0.5) - double(N) / R;
			tmp *= 180.0 / pi;
			printf("%.5lf\n", tmp);
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
