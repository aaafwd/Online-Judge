/* @JUDGE_ID: 19899RK 137 C++ "By Anadan" */
// Polygons
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>

struct Point{
	double x, y;
};

int c;
struct Polygon{
	int N;
	Point p[100];
} poly[2], clipper;

double getarea(Polygon &p){
	int i;
	double tmp, S = 0;

	for (i = 1; i < p.N - 1; ++i){
		tmp = (p.p[0].y - p.p[i].y) * (p.p[i + 1].x - p.p[i].x) - (p.p[i + 1].y - p.p[i].y) * (p.p[0].x - p.p[i].x);
		if (tmp < 0) tmp = -tmp;
		S += tmp * 0.5;
	}

	return S;
}

int inleft(double x, double y, double x0, double y0, double x1, double y1){
	double tmp = (x-x0)*(y1-y0) - (x1-x0)*(y-y0);
	if (tmp > -1e-12) return 0;
	return 1;
}

Point getintersection(Point p1, Point p2, double x3, double y3, double x4, double y4){
	double det = (p2.x - p1.x) * (y3 - y4) - (x3 - x4) * (p2.y - p1.y);
	double it1 = (x3 - p1.x) * (y3 - y4) - (x3 - x4) * (y3 - p1.y);
	Point res;
	res.x = p1.x + (p2.x - p1.x) * it1 / det;
	res.y = p1.y + (p2.y - p1.y) * it1 / det;
	return res;
}

void clippolygon(double x1, double y1, double x2, double y2){
	int i, j, N, nc = c ^ 1;

	for (N = i = 0; i < poly[c].N; ++i){
		if (i == poly[c].N - 1) j = 0; else j = i + 1;
		if (inleft(poly[c].p[i].x, poly[c].p[i].y, x1, y1, x2, y2)){
			if (inleft(poly[c].p[j].x, poly[c].p[j].y, x1, y1, x2, y2)) continue;
			poly[nc].p[N++] = getintersection(poly[c].p[i], poly[c].p[j], x1, y1, x2, y2);
			poly[nc].p[N++] = poly[c].p[j];
		}else{
			if (inleft(poly[c].p[j].x, poly[c].p[j].y, x1, y1, x2, y2)){
				poly[nc].p[N++] = getintersection(poly[c].p[i], poly[c].p[j], x1, y1, x2, y2);
			}else{
				poly[nc].p[N++] = poly[c].p[j];
			}
		}
	}

	poly[nc].N = N;
	c = nc;
}

int main(){
	int i, j, x, y;
	double res;

	while (scanf("%d", &poly[0].N) == 1 && poly[0].N){
		for (i = 0; i < poly[0].N; ++i){
			scanf("%d%d", &x, &y);
			poly[0].p[i].x = x; poly[0].p[i].y = y;
		}

		scanf("%d", &clipper.N);
		for (i = 0; i < clipper.N; ++i){
			scanf("%d%d", &x, &y);
			clipper.p[i].x = x; clipper.p[i].y = y;
		}

		res = getarea(poly[0]) + getarea(clipper);
		c = 0;
		for (i = 0; i < clipper.N; ++i){
			if (i == clipper.N - 1) j = 0; else j = i + 1;
			clippolygon(clipper.p[i].x, clipper.p[i].y, clipper.p[j].x, clipper.p[j].y);
		}

		res -= getarea(poly[c]) * 2.0;
		printf("%8.2lf", res);
	}

	putchar('\n');

	return 0;
}
/* @END_OF_SOURCE_CODE */
