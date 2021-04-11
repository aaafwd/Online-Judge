/* @JUDGE_ID: 19899RK 438 C++ "By Anadan" */ 
// The Circumference of the Circle
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>
#include <math.h>

const double pi = 3.141592653589793;
inline double sqr(double x) { return x*x; }

int main(){
	double x1, y1, x2, y2, x3, y3, l;

	while (scanf("%lf%lf%lf%lf%lf%lf", &x1, &y1, &x2, &y2, &x3, &y3) == 6){
		l = sqrt(sqr(x2-x1) + sqr(y2-y1)) * sqrt(sqr(x3-x1) + sqr(y3-y1));
		l /= fabs((x2-x1)*(y3-y1) - (x3-x1)*(y2-y1));
		l *= pi * sqrt(sqr(x3-x2) + sqr(y3-y2));
		printf("%.2lf\n", l);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
