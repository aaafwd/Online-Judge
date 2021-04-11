/* @JUDGE_ID: 19899RK 10773 C++ "By Anadan" */
// Back to Intermediate Math
// Accepted (0.002 seconds with low memory spent)

#include <stdio.h>
#include <math.h>

int main() {
	int set, cs = 0;
	double d, v, u, res;

	scanf("%d", &set);
	while (set--) {
		scanf("%lf%lf%lf", &d, &v, &u);
		if (u <= v || v == 0) printf("Case %d: can't determine\n", ++cs);
		else {
			res = d*(1/sqrt(u*u-v*v) - 1/u);
			printf("Case %d: %.3lf\n", ++cs, res);
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
