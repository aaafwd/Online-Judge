/* @JUDGE_ID: 19899RK 10005 C++ "By Anadan" */ 
// Packing polygons
// Accepted (0.002 seconds with low memory spent)

#include <stdio.h>
#include <math.h>

int N;
struct Point{
	int x, y;
}pt[100];
double R;

const double eps = 1e-12;
inline int sqr(int x) { return x * x; }

int cover(double cx, double cy){
	int i;
	double tmp;

	for (i = 0; i < N; ++i){
		tmp = (cx - pt[i].x) * (cx - pt[i].x) + (cy - pt[i].y) * (cy - pt[i].y);
		if (tmp > R + eps) break;
	}

	if (i < N) return 0;
	return 1;
}

int main(){
	int i, j, h;
	double tmp, x, y, l;
	char covered;

	while (scanf("%d\n", &N) == 1 && N){
		for (i = 0; i < N; ++i) scanf("%d%d", &pt[i].x, &pt[i].y);
		scanf("%lf\n", &R); R *= R;

		covered = 0;
		for (i = 0; i < N; ++i){
			for (j = i + 1; j < N; ++j){
				h = sqr(pt[j].x - pt[i].x) + sqr(pt[j].y - pt[i].y);
				tmp = R * 4.0 - h;
				if (tmp < -eps) break;
				if (tmp < 0.0) tmp = 0.0;
				l = sqrt(tmp) * 0.5;

				x = pt[j].y - pt[i].y;
				y = pt[i].x - pt[j].x;
				tmp = 1.0 / sqrt(x*x + y*y);
				x *= tmp * l; y *= tmp * l;

				if (cover(double(pt[i].x + pt[j].x)*0.5 + x, double(pt[i].y + pt[j].y)*0.5 + y) ||
				    cover(double(pt[i].x + pt[j].x)*0.5 - x, double(pt[i].y + pt[j].y)*0.5 - y)){
					covered = 1;
					break;
				}
			}

			if (j < N) break;
			if (covered) break;
		}

		if (covered) printf("The polygon can be packed in the circle.\n");
		else printf("There is no way of packing that polygon.\n");
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
