/* @JUDGE_ID: 19899RK 10286 C++ "By Anadan" */
// Trouble with a Pentagon
// Accepted (0.084 seconds with low memory spent)

#include <stdio.h>
#include <math.h>

int main(){
	const double pi = acos(0.0) * 2.0;
	double g = (cos(pi * 0.4) + 0.5 - sin(pi * 0.2)) / (cos(pi * 0.4) + cos(pi * 0.1));
	double a;

	g = sqrt(g * g + 2.0 * g * cos(pi * 0.4) + 1.0);
	while (scanf("%lf\n", &a) == 1){
		printf("%.10lf\n", g * a);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
