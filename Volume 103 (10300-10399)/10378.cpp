/* @JUDGE_ID: 19899RK 10378 C++ "By Anadan" */
// Complex Numbers
// Accepted (0.121 seconds using as much as 408 kbytes)

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

struct Result{
	double x, y;
}pt[100];

int sort_function(const void *a, const void *b){
	Result *ra = (Result *)a, *rb = (Result *)b;

	if (fabs(ra->x - rb->x) < 1e-12){
		if (ra->y > rb->y) return -1;
		return 1;
	}
	if (ra->x > rb->x) return -1;
	return 1;
}

inline double sqr(double x) { return x * x; }

int main(){
	int a, b, n, set = 0;
	double f, df, r;
	const double pi2 = acos(0.0) * 4.0;

	while (scanf("%d%di %d\n", &a, &b, &n) == 3){
		printf("Case %d:\n", ++set);

		if (a == 0 && b == 0){
			for (a = 0; a < n; ++a){
				printf("0.000+0.000i\n");
			}
		}else{
			f = atan2(b, a) / double(n);
			df = pi2 / double(n);
			r = sqrt(sqr(a) + sqr(b));
			r = pow(r, 1.0 / double(n));
			for (a = 0; a < n; ++a, f += df){
				pt[a].x = r * cos(f);
				pt[a].y = r * sin(f);
			}

			qsort(pt, n, sizeof(Result), sort_function);
			for (a = 0; a < n; ++a){
				if (fabs(pt[a].x) < 0.0005) pt[a].x = 0.0;
				if (fabs(pt[a].y) < 0.0005) pt[a].y = 0.0;
				printf("%.3lf", pt[a].x);
				if (pt[a].y >= -1e-12) putchar('+');
				printf("%.3lfi\n", pt[a].y);
			}
		}

		putchar('\n');
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
