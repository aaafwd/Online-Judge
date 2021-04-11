/* @JUDGE_ID: 19899RK 376 C++ "By Anadan" */ 
// More Triangles ... THE AMBIGUOUS CASE
// Accepted (0.230 seconds using as much as 396 kbytes)

#include <stdio.h>
#include <math.h>

inline double sqr(double x) { return x * x; }
const double eps = 1e-12;

int main(){
	int set = 0;
	double a, b, f, d;
	const double pi_180 = acos(0.0) / 90.0;

	printf("Case    A      B    THETA  # of    Side   Side\n");
	printf(" #     side   side  (deg)  Triags    1      2\n");

	while (scanf("%lf%lf%lf\n", &a, &b, &f) == 3){
		if (a == 0 && b == 0 && f == 0) break;
		printf("%4d%7.2lf%7.2lf%7.2lf", ++set, a, b, f);

		f *= pi_180;
		d = b * b - sqr(a * sin(f));

		if (d < -eps) printf("     0\n");
		else{
			a *= cos(f);
			if (d < eps) d = 0.0; else d = sqrt(d);

			b = a + d;
			a = a - d;

			if (b < eps) printf("     0\n");
			else if (a < eps || b - a < eps) printf("     1%9.2lf\n", b);
			else printf("     2%9.2lf%7.2lf\n", b, a);
		}
	}

	printf("\nEND OF REPORT for %d cases\n", set);

	return 0;
}
/* @END_OF_SOURCE_CODE */
