/* @JUDGE_ID: 19899RK 10341 C++ "By Anadan" */ 
// Solve It
// Accepted (0.043 seconds with low memory spent)

#include <stdio.h>
#include <math.h>

double p, q, r, s, t, u;
const double exp_1 = exp(-1);
const double sin_1 = sin(1);
const double cos_1 = cos(1);
const double tan_1 = tan(1);

inline double f(double x){
	return p * exp(-x) + q * sin(x) + r * cos(x) + s * tan(x) + t * x * x + u;
}

inline double f0(){
	return p + r + u;
}

inline double f1(){
	return p * exp_1 + q * sin_1 + r * cos_1 + s * tan_1 + t + u;
}

int myscanf(double &x){
	int i, sgn = 0;
	double y;

	while ((i = getchar()) != EOF && i != '.' && i != '-' && (i < '0' || i > '9'));
	if (i == EOF) return 0;
	if (i == '-'){
		sgn = 1;
		i = getchar();
	}

	if (i != '.'){
		x = i - '0';
		while ((i = getchar()) != EOF && i != '.' && '0' <= i && i <= '9'){
			x = x * 10 + i - '0';
		}
	}else x = 0.0;

	if (i == '.'){
		y = 0.1;
		while ((i = getchar()) != EOF && '0' <= i && i <= '9'){
			x += y * (i - '0');
			y *= 0.1;
		}
	}

	if (sgn) x = -x;

	return 1;
}

int main(){
	double x, x1, x2;

	while (myscanf(p)){
		myscanf(q); myscanf(r); myscanf(s); myscanf(t); myscanf(u);
		if (f0() >= 0 && f1() <= 0){
			x1 = 0; x2 = 1;
			while (x2 - x1 > 1e-7){
				x = (x1 + x2) * 0.5;
				if (f(x) > 0) x1 = x; else x2 = x;
			}

			printf("%.4lf\n", x);

		}else puts("No solution");
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
