/* @JUDGE_ID: 19899RK 10517 C++ "By Anadan" */ 
// Wind of Change!
// Accepted (0.154 seconds using as much as 400 kbytes)

#include <stdio.h>
#include <math.h>

double n, m;
const double R = 6378.0;
const double pi_2 = acos(0.0);
const double right = pi_2 / 90.0 * 70.0;
const double coeff = 90.0 / pi_2;

inline double func(double f) { return n * sin(f + n / R) - m * sin(f); }

double getangle(){
	double a = -pi_2, b = pi_2, f, tmp;

	while (b - a > 1e-12){
		f = (a + b) * 0.5;
		tmp = func(f);
		if (tmp > 0) a = f; else b = f;
	}

	return f;
}

int main(){
	int set, cs;
	double f, a, b;

	scanf("%d", &set);
	for (cs = 1; cs <= set; ++cs){
		printf("Case %d: ", cs);
		scanf("%lf%lf", &n, &m);

		if (n >= 1001){
			puts("Invalid or impossible.");
			continue;
		}

		f = getangle();
		if (fabs(func(f)) > 1e-7){
			puts("Invalid or impossible.");
			continue;
		}

		f += n / R;
		f = pi_2 - f;
		if (f > right || f < 0){
			puts("Invalid or impossible.");
			continue;
		}

		f *= coeff;
		a = floor(f); f -= a;
		f *= 60;
		b = floor(f); f -= b;
		f *= 60;

		printf("%.0lf deg %.0lf min %.0lf sec\n", a, b, f);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
