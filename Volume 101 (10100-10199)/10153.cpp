/* @JUDGE_ID: 19899RK 10153 C++ "By Anadan" */ 
// New Horizons
// Accepted (0.336 seconds using as much as 432 kbytes)

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define SZ 100

inline double sqr(double x) { return x * x; }

int sort_function(const void *a, const void *b){
	return strcmp((char *)a, (char *)b);
}

int main(){
	int N, i;
	double R, x1, y1, z1, x2, y2, z2, h, a, b, A, B, C, D;
	const double pi_180 = acos(0.0) / 90.0;
	static char names[SZ][81];

	while (scanf("%lf\n", &R) == 1){
		R *= 0.5;
		scanf("%lf%lf%lf\n", &h, &a, &b);
		a *= pi_180; b *= pi_180;
		x1 = (R + h) * cos(a);
		y1 = x1 * sin(b); x1 *= cos(b);
		z1 = (R + h) * sin(a);
		C = h * (h + R * 2.0);

		N = 0;
		scanf("%d\n", &i);
		while (i--){
			scanf("%lf%lf%lf %[^\n]\n", &h, &a, &b, names[N]);
			a *= pi_180; b *= pi_180;
			x2 = (R + h) * cos(a);
			y2 = x2 * sin(b); x2 *= cos(b);
			z2 = (R + h) * sin(a);
			A = sqr(x2 - x1) + sqr(y2 - y1) + sqr(z2 - z1);
			B = x1 * (x2 - x1) + y1 * (y2 - y1) + z1 * (z2 - z1);
			D = B*B - A*C;
			if (D > -1e-12){
				if (D < 1e-12) D = 0.0; else D = sqrt(D);
				a = (-B - D) / A;
				b = (-B + D) / A;
				if (!(-1e-12 <= a && a <= 1.0 + 1e-12 && -1e-12 <= b && b <= 1.0 + 1e-12)) ++N;
			}else ++N;
		}

		qsort(names, N, sizeof(names[0]), sort_function);
		for (i = 0; i < N; ++i) printf("%s\n", names[i]);
		putchar('\n');
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
