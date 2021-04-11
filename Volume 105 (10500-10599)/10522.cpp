/* @JUDGE_ID: 19899RK 10522 C++ "By Anadan" */ 
// Height to Area
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>
#include <math.h>

int main(){
	int set;
	double a, b, c, p;

	scanf("%d", &set);
	while (set > 0 && scanf("%lf%lf%lf", &a, &b, &c) == 3){
		if (a == 0 || b == 0 || c == 0){
			puts("These are invalid inputs!");
			--set;
			continue;
		}

		p = 1 / a + 1 / b + 1 / c;
		if (p - 2 / a < 1e-12 || p - 2 / b < 1e-12 || p - 2 / c < 1e-12){
			puts("These are invalid inputs!");
			--set;
			continue;
		}

		p = 1 / sqrt(p * (p - 2 / a)) / sqrt((p - 2 / b) * (p - 2 / c));
		printf("%.3lf\n", p);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
