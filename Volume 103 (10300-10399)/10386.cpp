/* @JUDGE_ID: 19899RK 10386 C++ "By Anadan" */
// Circles in Triangle
// Accepted (0.070 seconds with low memory spent)

#include <stdio.h>
#include <math.h>

int main(){
	int N;
	double R;
	double f1 = 9.293810046163106; /* = cos(acos(0.5 / sqrt(3.0)) - acos(0.0) / 3.0) * 8.0 + sqrt(3.0) * 2.0; */
	double f2 = 10.730087938848658; /* = cos(acos(1.0 / sqrt(3.0)) - acos(0.0) / 3.0) * 8.0 + sqrt(3.0) * 2.0; */

	scanf("%d\n", &N);
	while (N--){
		scanf("%lf\n", &R);
		printf("%.10lf %.10lf\n", f1 * R, f2 * R);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
