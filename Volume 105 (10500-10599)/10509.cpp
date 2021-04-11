/* @JUDGE_ID: 19899RK 10509 C++ "By Anadan" */ 
// R U Kidding Mr. Feynman!
// Accepted (0.270 seconds using as much as 400 kbytes)

#include <stdio.h>
#include <math.h>

int main(){
	double d, p, tmp;

	while (scanf("%lf", &d) == 1 && d){
		p = floor(pow(d, 1.0 / 3.0) + 0.5);
		if (p * p * p > d) --p;
		p += (d - p * p * p) / p / p / 3.0;
		printf("%.4lf\n", p);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
