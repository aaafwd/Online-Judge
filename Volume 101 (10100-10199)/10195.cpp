/* @JUDGE_ID: 19899RK 10195 C++ "By Anadan" */ 
// The Knights Of The Round Table
// Accepted (0.016 seconds with low memory spent)

#include <stdio.h>
#include <math.h>

int main(){
	double a, b, c, p;

	while (scanf("%lf%lf%lf\n", &a, &b, &c) == 3){
		p = (a + b + c) * 0.5;
		if (a == 0 || b == 0 || c == 0) a = 0.0;
		else a = p * sqrt((1.0 - a / p) * (1.0 - b / p) * (1.0 - c / p));
		printf("The radius of the round table is: %.3lf\n", a);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
