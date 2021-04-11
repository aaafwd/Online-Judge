/* @JUDGE_ID: 19899RK 10175 C++ "By Anadan" */ 
// Sphere
// Accepted (0.002 seconds with low memory spent)

#include <stdio.h>
#include <math.h>

inline double sqr3(double x) { return x * x * x; }

int main(){
	int set;
	double r1, r2, d, W, s, V, S, l1, l2;
	const double pi = acos(0.0) * 2.0;

	scanf("%d\n", &set);
	while (set--){
		scanf("%lf%lf%lf%lf%lf\n", &r1, &r2, &d, &W, &s);
		l1 = 0.5 * ((r1*r1 - r2*r2) / d + d);
		l2 = d - l1;
		V = 1.0 / 3.0 * pi * (sqr3(r1) * (2.0 + 3.0 * l1 / r1 - sqr3(l1 / r1)) + sqr3(r2) * (2.0 + 3.0 * l2 / r2 - sqr3(l2 / r2)));
		S = 2.0 * pi * (r1 * (r1 + l1) + r2 * (r2 + l2));
		printf("%.4lf %.4lf\n", V, S);
		if (s * V < W) printf("The Paired-Sphere Sinks.\n");
		else printf("The Paired-Sphere Floats.\n");
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
