/* @JUDGE_ID: 19899RK 10697 C++ "By Anadan" */
// Firemen barracks
// Accepted (0.016 seconds with low memory spent)

#include <stdio.h>
#include <math.h>

inline void fround(double & x) {
	if (fabs(x) < 0.05 - 1e-12) x = 0;
	else if (fabs(x) < 0.05 + 1e-12) {
		if (x > 0) x = 0.1; else x = -0.1;
	}
}

int main() {
	int set, revflag;
	double x1, y1, x2, y2, x3, y3;
	double a1, b1, c1, a2, b2, c2;

	scanf("%d", &set);
	while (set--) {
		scanf("%lf%lf%lf%lf%lf%lf", &x1, &y1, &x2, &y2, &x3, &y3);
		a1 = x1-x2+x1-x2; b1 = y1-y2+y1-y2; c1 = x1*x1 + y1*y1 - x2*x2 - y2*y2;
		a2 = x1-x3+x1-x3; b2 = y1-y3+y1-y3; c2 = x1*x1 + y1*y1 - x3*x3 - y3*y3;

		revflag = 0;
		if (b1 == 0 || b2 == 0) {
			x1 = a1; a1 = b1; b1 = x1;
			x2 = a2; a2 = b2; b2 = x2;
			revflag = 1;
		}

		if (a2 == 0) {
			x1 = a1; a1 = a2; a2 = x1;
			x1 = b1; b1 = b2; b2 = x1;
			x1 = c1; c1 = c2; c2 = x1;
		}

		if (a1 == 0) {
			if (b1 == 0) {
				if (fabs(c1) > 1e-12) puts("There is no possible location.");
				else if (a2 != 0 || b2 != 0 || fabs(c2) > 1e-12) puts("There is an infinity of possible locations.");
				else puts("There is no possible location.");
			} else if (a2 == 0) {
				if (b2 == 0) {
					if (fabs(c2) > 1e-12) puts("There is an infinity of possible locations.");
					else puts("There is no possible location.");
				} else {
					if (fabs(b2*c1 - c2*b1) < 1e-12) puts("There is an infinity of possible locations.");
					else puts("There is no possible location.");
				}
			} else {
				y1 = c1/b1;
				x1 = (c2-b2*y1)/a2;
				fround(x1);
				fround(y1);
				if (revflag) { a1 = x1; x1 = y1; y1 = a1; }
				printf("The equidistant location is (%.1lf, %.1lf).\n", x1, y1);
			}
		} else {
			double det = a1*b2 - a2*b1;
			double dtx = c1*b2 - c2*b1;
			double dty = a1*c2 - a2*c1;

			if (fabs(det) < 1e-12) {
				if (fabs(dtx) < 1e-12) puts("There is an infinity of possible locations.");
				else puts("There is no possible location.");
			} else {
				x1 = dtx/det;
				y1 = dty/det;
				fround(x1);
				fround(y1);
				if (revflag) { a1 = x1; x1 = y1; y1 = a1; }
				printf("The equidistant location is (%.1lf, %.1lf).\n", x1, y1);
			}
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
