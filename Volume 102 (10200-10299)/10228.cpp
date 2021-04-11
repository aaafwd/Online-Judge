/* @JUDGE_ID: 19899RK 10228 C++ "By Anadan" */
// A Star not a Tree?
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>
#include <math.h>

struct Point{
	double x, y;
}pt[100];

inline double sqr(double x) { return x * x; }

int main(){
	int set, N, i;
	char fx, fy;
	double x, y, grx, gry, stepx, stepy, tmp;

	scanf("%d\n\n", &set);
	while (set--){
		scanf("%d\n", &N);
		x = y = 0.0;
		stepx = stepy = 100.0;
		for (i = 0; i < N; ++i){
			scanf("%lf %lf\n", &pt[i].x, &pt[i].y);
			x += pt[i].x; y += pt[i].y;
		}

		x /= N; y /= N;
		fx = fy = 0;
		while (1){
			grx = gry = 0.0;
			for (i = 0; i < N; ++i){
				tmp = sqrt(sqr(x - pt[i].x) + sqr(y - pt[i].y));
				if (tmp > 1e-12){
					grx += (x - pt[i].x) / tmp;
					gry += (y - pt[i].y) / tmp;
				}
			}

			if (fabs(grx) + fabs(gry) < 1e-12) break;
			grx *= stepx; gry *= stepy;
			x -= grx; y -= gry;
			if (fx == 0 && fy == 0){
				if (grx > 0) fx = 1; else fx = -1;
				if (gry > 0) fy = 1; else fy = -1;
			}else{
				if (grx > 0 && fx != 1){
					fx = 1;
					stepx *= 0.5;
				}

				if (grx < 0 && fx != -1){
					fx = -1;
					stepx *= 0.5;
				}

				if (gry > 0 && fy != 1){
					fy = 1;
					stepy *= 0.5;
				}

				if (gry < 0 && fy != -1){
					fy = -1;
					stepy *= 0.5;
				}
			}
		}

		tmp = 0.0;
		for (i = 0; i < N; ++i){
			tmp += sqrt(sqr(x - pt[i].x) + sqr(y - pt[i].y));
		}

		printf("%.0lf\n", tmp);
		if (set) putchar('\n');
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
