/* @JUDGE_ID: 19899RK 10297 C++ "By Anadan" */
// Beavergnaw
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>
#include <math.h>

int main(){
	double D, V;
	const double pi = acos(0.0) * 2.0;

	while (scanf("%lf%lf", &D, &V) == 2){
		if (D == 0.0 && V == 0.0) break;
		printf("%.3lf\n", pow(D*D*D-6*V/pi, 1.0/3.0));
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
