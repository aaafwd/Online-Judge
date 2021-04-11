/* @JUDGE_ID: 19899RK 10263 C++ "By Anadan" */ 
// Railway
// Accepted (0.002 seconds with low memory spent)

#include <stdio.h>

inline double sqr(double x) { return x * x; }

int main(){
	int N;
	double xm, ym, x1, y1, x2, y2, min, x, y, tmp, a, b;

	while (scanf("%lf%lf%d%lf%lf", &xm, &ym, &N, &x1, &y1) == 5){
		x = x1; y = y1;
		min = sqr(x - xm) + sqr(y - ym);
		while (N--){
			scanf("%lf%lf", &x2, &y2);
			a = sqr(x2 - x1) + sqr(y2 - y1);
			tmp = (x2 - x1) * (xm - x1) + (y2 - y1) * (ym - y1);
			if (0.0 <= tmp && tmp <= a){
				b = sqr(xm - x1) + sqr(ym - y1) - tmp * tmp / a;
				if (min > b){
					min = b;
					x = x1 + tmp / a * (x2 - x1);
					y = y1 + tmp / a * (y2 - y1);
				}
			}else{
				b = sqr(x2 - xm) + sqr(y2 - ym);
				if (min > b){
					min = b;
					x = x2; y = y2;
				}
			}
			
			x1 = x2; y1 = y2;
		}

		printf("%.4lf\n%.4lf\n", x, y);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
