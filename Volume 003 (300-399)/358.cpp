/* @JUDGE_ID: 19899RK 358 C++ "By Anadan" */
// Don't Have A Cow, Dude
// Accepted (0.160 seconds using as much as 400 kbytes)

#include <stdio.h>
#include <math.h>

double P;
const double pi = 3.14159;
const double m_pi = acos(0.0) * 2.0;

inline double f(double x){
	return (m_pi - x)*cos(x) + sin(x) - m_pi + pi * P;
}

int main(){
	int set;
	double a, a0, a1, R;

	scanf("%d\n\n", &set);
	while (set--){
		scanf("%lf%lf", &R, &P);

		a0 = 0.0;
		a1 = pi * 0.5;
		while (a1 - a0 > 1e-12){
			a = 0.5 * (a0 + a1);
			if (f(a) > 0.0) a0 = a; else a1 = a;
		}

		a = 2.0 * R * sin(0.5 * a);
		printf("R = %.0lf, P = %.2lf, Rope = %.2lf\n", R,  P, a);
		if (set) putchar('\n');
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
