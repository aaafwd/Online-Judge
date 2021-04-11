/* @JUDGE_ID: 19899RK 10566 C++ "By Anadan" */
// Crossed Ladders
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>
#include <math.h>

double a, b, h;

double func(double x){
	return 1/sqrt(a*a-x*x) + 1/sqrt(b*b-x*x) - 1/h;
}

int main(){
	double x0, x1, x;

	while (scanf("%lf%lf%lf", &a, &b, &h) == 3){
		x0 = 0;
		x1 = a;
		if (x1 > b) x1 = b;
		while (x1 - x0 > 1e-10){
			x = (x0 + x1) * 0.5;
			if (func(x) > 0) x1 = x; else x0 = x;
		}

		printf("%.3lf\n", x);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
