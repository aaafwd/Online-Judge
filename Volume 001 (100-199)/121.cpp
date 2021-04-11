/* @JUDGE_ID: 19899RK 121 C++ "By Anadan" */
// Pipe Fitters
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>
#include <math.h>

const double coeff = sqrt(4.0 / 3.0);

double getskewmax(double a, double b){
	char flag = 0;
	double k = floor(coeff * (b - 1.0)) + 1.0;
	if (fmod(a, 1.0) < 0.5) flag = 1;
	a = floor(a) * k;
	if (flag) a -= floor(k * 0.5);
	return a;
}

int main(){
	char flag;
	double a, b, max, tmp;

	while (scanf("%lf%lf\n", &a, &b) == 2){
		max = floor(a) * floor(b);
		flag = 0;
		if (b >= 1.0){
			tmp = getskewmax(a, b);
			if (max < tmp) max = tmp, flag = 1;
		}
		if (a >= 1.0){
			tmp = getskewmax(b, a);
			if (max < tmp) max = tmp, flag = 1;
		}

		printf("%.0lf ", max);
		if (flag) printf("skew\n"); else printf("grid\n");
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
