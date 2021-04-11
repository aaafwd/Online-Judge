/* @JUDGE_ID: 19899RK 10322 C++ "By Anadan" */ 
// The Four in One Stadium
// Accepted (3.127 seconds using as much as 400 kbytes)
// Too much time !

#include <stdio.h>
#include <math.h>

double r1, r2, r3;
const double pi = acos(0.0) * 2.0;
const double eps = 1e-10;

double f(double a, double b, double c){
	double tmp = 0.0;
	tmp += acos((a*a + b*b - (r1 + r2)*(r1 + r2)) / (2.0*a*b));
	tmp += acos((b*b + c*c - (r2 + r3)*(r2 + r3)) / (2.0*b*c));
	tmp += acos((c*c + a*a - (r3 + r1)*(r3 + r1)) / (2.0*c*a));
	return tmp - pi - pi;
}

inline double max(double a, double b, double c){
	if (a < b) a = b;
	if (a < c) a = c;
	return a;
}

inline double getsize(double a, double b, double c){
	return sqrt(2.0 - (a*a + b*b - c*c) / (a*b));
}

int main(){
	double s1, s2, s3, s;

	while (scanf("%lf%lf%lf\n", &s1, &s2, &s3) == 3){
		r1 = sqrt(s1 / pi);
		r2 = sqrt(s2 / pi);
		r3 = sqrt(s3 / pi);

		s1 = max(r1+r2, r2+r3, r3+r1);
		s2 = r1 + r2 + r3;

		while (fabs(s2 - s1) > eps){
			s3 = (s1 + s2) * 0.5;
			if (f(s3 - r1, s3 - r2, s3 - r3) > 0) s1 = s3; else s2 = s3;
		}

		printf("%.10lf ", s3);

		s1 = 0.0;
		s2 = s3;

		while (fabs(s2 - s1) > eps){
			s3 = (s1 + s2) * 0.5;
			if (f(s3 + r1, s3 + r2, s3 + r3) > 0) s1 = s3; else s2 = s3;
		}

		printf("%.10lf ", s3);

		s1 = getsize(r1 + r2, r1 + r3, r2 + r3) * r1;
		s2 = getsize(r1 + r2, r2 + r3, r1 + r3) * r2;
		s3 = getsize(r2 + r3, r1 + r3, r1 + r2) * r3;
		s = (s1 + s2 + s3) * 0.5;

		s = s * s * sqrt((1.0 - s1 / s) * (1.0 - s2 / s) * (1.0 - s3 / s));
		printf("%.10lf\n", s);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
