/* @JUDGE_ID: 19899RK 10345 C++ "By Anadan" */ 
// Cricket/Football Goes Down
// Accepted (0.369 seconds using as much as 396 kbytes)

#include <stdio.h>
#include <math.h>

int main(){
	int set;
	double a;
	const double r1 = sqrt(0.5);
	const double r2 = sqrt(1.25);
	const double r3 = sqrt(425.0) / 16.0;
	const double r4 = sqrt(2.0);
	const double r5 = sqrt(2.5);
	const double r6 = 1.688542968202847987413406;

	scanf("%d\n", &set);
	while (set--){
		scanf("%lf\n", &a);
		printf("%.11lf %.11lf %.11lf %.11lf %.11lf %.11lf\n", r1*a, r2*a, r3*a, r4*a, r5*a, r6*a);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
