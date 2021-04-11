/* @JUDGE_ID: 19899RK 10428 C++ "By Anadan" */ 
// The Roots
// Accepted (0.262 seconds using as much as 400 kbytes)

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int N;
double c[6], roots[5];

int sort_function(const void *a, const void *b){
	if (*(double *)a < *(double *)b) return -1;
	return 1;
}

double f(double x){
	int i;
	double res = 0.0;
	for (i = 0; i <= N; ++i) { res *= x; res += c[i]; }
	return res;
}

void solvecubic(double k1, double k2, double k3, double &x1, double &x2, double &x3){
	double a = -25.5, b = 25.5, x, tmp;

	while (b - a > 1e-10){
		x = (a + b) * 0.5;
		tmp = ((x + k1) * x + k2) * x + k3;
		if (tmp > 0.0) b = x; else a = x;
	}

	x1 = (a + b) * 0.5;
	a = k1 + x1; b = a * x + k2;
	x = a * a - 4.0 * b;
	if (x < 0.0) x = 0.0;
	x = sqrt(x);
	x2 = 0.5 * (-a + x);
	x3 = 0.5 * (-a - x);
}

double getroot(){
	double x, y, z, a = -25.5, b = 25.5, d;

	if (N == 1) return -c[1] / c[0];
	else if (N == 2){
		x = c[1] * c[1] - 4.0 * c[0] * c[2];
		if (x < 0.0) x = 0.0;
		return (-c[1] + sqrt(x)) / c[0] * 0.5;
	}else if (N & 1){
		while (b - a > 1e-10){
			x = (a + b) * 0.5;
			if ((c[0] > 0.0) ^ (f(x) > 0.0)) a = x; else b = x;
		}

		x = (a + b) * 0.5;
		return x;
	}

	a = 0.75 * c[1] / c[0]; b = 0.5 * c[2] / c[0]; d = 0.25 * c[3] / c[0];
	solvecubic(a, b, d, x, y, z);

	a = -25.5;
	if (x < y){
		if (x < z) b = x; else b = z;
	}else{
		if (y < z) b = y; else b = z;
	}

	while (b - a > 1e-10){
		x = (a + b) * 0.5;
		if ((c[0] > 0.0) ^ (f(x) > 0.0)) b = x; else a = x;
	}

	x = (a + b) * 0.5;
	return x;
}

double removeroot(){
	int i;
	double root = getroot(), tmp = c[0];

	for (i = 1; i < N; ++i) { tmp *= root; tmp += c[i]; c[i] = tmp; }
	--N;
	return root;
}

int main(){
	int set = 0, i, index;

	while (scanf("%d\n", &N) == 1 && N){
		for (i = 0; i <= N; ++i) scanf("%lf", c + i);
		index = 0;
		while (N) roots[index++] = removeroot();
		qsort(roots, index, sizeof(double), sort_function);
		printf("Equation %d:", ++set);
		for (i = 0; i < index; ++i){
			if (fabs(roots[i]) < 0.00005) roots[i] = 0.0;
			printf(" %.4lf", roots[i]);
		}
		putchar('\n');
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
