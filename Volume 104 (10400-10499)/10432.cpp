/* @JUDGE_ID: 19899RK 10432 C++ "By Anadan" */ 
// Polygon Inside A Circle
// Accepted (0.006 seconds with low memory spent)

#include <stdio.h>
#include <math.h>

int main(){
	double r, n;
	const double pi_2 = acos(0.0) * 4.0;

	while (scanf("%lf%lf\n", &r, &n) == 2) printf("%.3lf\n", r * r * n * 0.5 * sin(pi_2 / n));

	return 0;
}
/* @END_OF_SOURCE_CODE */
