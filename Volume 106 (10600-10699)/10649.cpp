/* @JUDGE_ID: 19899RK 10649 C++ "By Anadan" */
// Danger Point
// Accepted (0.008 seconds with low memory spent)

#include <stdio.h>
#include <math.h>

int main(){
	double d, l;

	while (scanf("%lf%lf", &d, &l) == 2 && (d || l)){
		d = d*d*0.5 - l*l;
		if (d < 0) puts("INCORRECT INFORMATION !!!");
		else printf("%.6lf\n", sqrt(d));
	}

	return 0;
}

/* @END_OF_SOURCE_CODE */
