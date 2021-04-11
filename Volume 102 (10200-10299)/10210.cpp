/* @JUDGE_ID: 19899RK 10210 C++ "By Anadan" */
// Romeo & Juliet !
// Accepted (0.020 seconds with low memory spent)

#include <stdio.h>
#include <math.h>

int main(){
	double x1, y1, x2, y2, a1, a2, res;
	const double k = acos(0.0) / 90.0;

	while (scanf("%lf%lf%lf%lf%lf%lf", &x1, &y1, &x2, &y2, &a1, &a2) == 6){
		res = sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2)) * ((1.0 / tan(a1 * k)) + (1.0 / tan(a2 * k)));
		printf("%.3lf\n", res);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
