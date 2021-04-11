/* @JUDGE_ID: 19899RK 578 C++ "By Anadan" */
// Polygon Puzzler
// Accepted (0.406 seconds using as much as 396 kbytes)

#include <stdio.h>
#include <math.h>

inline double norm(double x, double y, double z) {
	double res = sqrt(x*x + y*y + z*z);
	if (fabs(z) < 1e-12) z = y;
	if (fabs(z) < 1e-12) z = x;
	if (z > 0) return res;
	else return -res;
}

int main() {
	int N, i;
	double x0, y0, z0, x1, y1, z1, x2, y2, z2, area;

	while (scanf("%d", &N) == 1 && N) {
		area = 0;
		scanf("%lf%lf%lf", &x0, &y0, &z0);
		scanf("%lf%lf%lf", &x1, &y1, &z1);
		for (i = 2; i < N; ++i) {
			scanf("%lf%lf%lf", &x2, &y2, &z2);
			area += norm((y1-y0)*(z2-z1) - (z1-z0)*(y2-y1),
						(x2-x1)*(z1-z0) - (z2-z1)*(x1-x0),
						(x1-x0)*(y2-y1) - (y1-y0)*(x2-x1));
			x1 = x2;
			y1 = y2;
			z1 = z2;
		}
		if (area < 0) area = -area;
		printf("%.3lf\n", area*0.5);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
