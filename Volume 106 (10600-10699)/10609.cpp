/* @JUDGE_ID: 19899RK 10609 C++ "By Anadan" */
// Fractal
// Accepted (0.783 seconds using as much as 1956 kbytes)

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Point{
	double x, y;
} pt[50000];
int sp;
double threshold;
const double coeff = sqrt(3) / 4;

int sort_function(const void *a, const void *b) {
	Point *pa = (Point *)a, *pb = (Point *)b;
	if (pa->x <= pb->x - 1e-8) return -1;
	if (pa->x >= pb->x + 1e-8) return  1;
	if (pa->y < pb->y) return -1;
	return 1;
}


void generate(double x1, double y1, double x2, double y2) {
	int i;
	double tmp;

	while (1) {
		tmp = (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1);
		if (tmp < threshold) return;

		i = sp;
		pt[sp].x   = x1 + (x2 - x1) * 0.25;
		pt[sp++].y = y1 + (y2 - y1) * 0.25;

		pt[sp].x   = x1 + x2 - pt[i].x;
		pt[sp++].y = y1 + y2 - pt[i].y;

		pt[sp].x   = (x1 + x2) * 0.5 - coeff * (y2 - y1);
		pt[sp++].y = (y1 + y2) * 0.5 + coeff * (x2 - x1);

		generate(pt[i].x, pt[i].y, pt[i+2].x, pt[i+2].y);

		x1 = pt[i+2].x; y1 = pt[i+2].y;
		x2 = pt[i+1].x; y2 = pt[i+1].y;
	}
}

int main() {
	int set = 0, i;
	double x1, y1, x2, y2;

	while (scanf("%lf%lf%lf%lf%lf", &x1, &y1, &x2, &y2, &threshold) == 5) {
		if (threshold < 1) break;
		threshold *= threshold * 4;
		sp = 0;
		pt[sp].x = x1; pt[sp++].y = y1;
		pt[sp].x = x2; pt[sp++].y = y2;
		generate(x1, y1, x2, y2);
		qsort(pt, sp, sizeof(Point), sort_function);
		printf("Case %d:\n%d\n", ++set, sp);
		for (i = 0; i < sp; ++i) {
			printf("%.5lf %.5lf\n", pt[i].x, pt[i].y);
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
