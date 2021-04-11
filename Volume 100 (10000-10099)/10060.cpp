/* @JUDGE_ID: 19899RK 10060 C++ "By Anadan" */ 
// A Hole to Catch a Man
// Accepted (0.004 seconds with low memory spent)

#include <stdio.h>
#include <math.h>

int main(){
	int N, i;
	double T, S, V, x0, y0, x1, y1, x2, y2;
	const double pi = acos(0.0) * 2.0;

	while (scanf("%d\n", &N) == 1 && N){
		V = 0.0;
		while (N--){
			scanf("%lf%lf%lf%lf%lf", &T, &x0, &y0, &x1, &y1);
			if (x0 == x1 && y0 == y1) continue;
			S = 0.0;
			while (scanf("%lf%lf", &x2, &y2) == 2){
				if (x2 == x0 && y2 == y0) break;
				S += (x2 - x0) * (y1 - y0) - (x1 - x0) * (y2 - y0);
				x1 = x2; y1 = y2;
			}
			V += T * fabs(S) * 0.5;
		}
		scanf("%lf%lf\n", &x0, &y0);
		S = pi * x0 * x0 * y0;

		printf("%.0lf\n", floor(V / S));
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
