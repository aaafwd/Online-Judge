/* @JUDGE_ID: 19899RK 10577 C++ "By Anadan" */
// Bounding box
// Accepted (0.002 seconds with low memory spent)

#include <stdio.h>
#include <math.h>

int main(){
	int set = 0, N, i;
	double x1, y1, x2, y2, x3, y3, cx, cy, t, xmax, xmin, ymax, ymin, a;
	double cosa, sina;
	const double pi2 = acos(0.0) * 4.0;

	while (scanf("%d", &N) == 1 && N){
		scanf("%lf%lf%lf%lf%lf%lf", &x1, &y1, &x2, &y2, &x3, &y3);

		a = (y2-y1)*(x2-x3) - (x2-x1)*(y2-y3);
		t = (x1-x3)*(x2-x3) - (y3-y1)*(y2-y3);
		t = t*0.5 / a;

		cx = (x1+x2)*0.5 + (y1-y2)*t;
		cy = (y1+y2)*0.5 + (x2-x1)*t;
		xmax = xmin = x1;
		ymax = ymin = y1;
		x1 -= cx; y1 -= cy;

		a = pi2/N;
		cosa = cos(a); sina = sin(a);
		for (i = 0; i < N; ++i){
			x2 = x1*cosa + y1*sina + cx;
			y2 = -x1*sina + y1*cosa + cy;

			if (xmin > x2) xmin = x2;
			if (xmax < x2) xmax = x2;
			if (ymin > y2) ymin = y2;
			if (ymax < y2) ymax = y2;

			x1 = x2 - cx; y1 = y2 - cy;
		}

		printf("Polygon %d: %.3lf\n", ++set, (xmax-xmin)*(ymax-ymin));
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
