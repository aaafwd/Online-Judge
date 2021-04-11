/* @JUDGE_ID: 19899RK 659 C++ "By Anadan" */ 
// Reflections
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>
#include <math.h>

struct Circle{
	int x, y, r;
}pt[25];

inline double sqr(double x) { return x * x; }

int main(){
	int set = 0, N, i, j, k, hits;
	double x, y, dx, dy, t, mint, a, b, D;

	while (scanf("%d\n", &N) == 1 && N){
		for (i = 0; i < N; ++i) scanf("%d%d%d\n", &pt[i].x, &pt[i].y, &pt[i].r);
		scanf("%lf%lf%lf%lf\n", &x, &y, &dx, &dy);
		t = 1.0 / sqrt(dx * dx + dy * dy); dx *= t; dy *= t;

		printf("Scene %d\n", ++set);
		for (j = -1, hits = 0; hits < 11; ++hits){
			mint = -1.0;
			for (k = -1, i = 0; i < N; ++i){
				if (i == j) continue;
				a = -(dx * (x - pt[i].x) + dy * (y - pt[i].y));
				D = a * a - (sqr(x - pt[i].x) + sqr(y - pt[i].y) - sqr(pt[i].r));
				if (D < 1e-12) continue;
				t = a - sqrt(D);
				if (t < 1e-12) continue;
				if (mint == -1.0 || mint > t){
					mint = t;
					k = i;
				}
			}

			if (k == -1){
				printf("inf\n\n");
				break;
			}else if (hits == 10){
				printf("...\n\n");
				break;
			}

			j = k;
			x += mint * dx; y += mint * dy;
			a = x - pt[k].x; b = y - pt[k].y;
			D = 1.0 / sqrt(a * a + b * b); a *= D; b *= D;
			t = 2.0 * (a * dx + b * dy);
			dx -= t * a; dy -= t * b;
			printf("%d ", k + 1);
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
