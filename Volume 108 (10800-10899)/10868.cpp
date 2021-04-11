/* @JUDGE_ID: 19899RK 10868 C++ "By Anadan" */
// Bungee Jumping
// Accepted (0.002 seconds with low memory spent)

#include <stdio.h>
#include <math.h>

int main() {
	double k, l, s, w, max, u;

	while (scanf("%lf%lf%lf%lf", &k, &l, &s, &w) == 4) {
		if (!k && !l && !s && !w) break;

		u = w*9.81/k;
		max = l + sqrt(u*(u+l+l))+u;
		if (max < s - 1e-12) puts("Stuck in the air.");
		else {	
			u = 2*9.81*s - k/w*(s-l)*(s-l);
			if (u < 0) u = 0;
			u = sqrt(u);
			if (u > 10) puts("Killed by the impact.");
			else puts("James Bond survives.");
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
