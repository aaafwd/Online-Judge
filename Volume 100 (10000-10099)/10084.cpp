/* @JUDGE_ID: 19899RK 10084 C++ "By Anadan" */ 
// Hotter Colder
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>

struct Point{
	double x, y;
};

int c;
struct Polygon{
	int N;
	Point p[100];
} poly[2];

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
	char str[21];
	double x1, y1, x2, y2, S;

	c = 0;
	poly[0].N = 4;
	poly[0].p[0].x = 0.0; poly[0].p[0].y = 0.0;
	poly[0].p[1].x = 0.0; poly[0].p[1].y = 10.0;
	poly[0].p[2].x = 10.0; poly[0].p[2].y = 10.0;
	poly[0].p[3].x = 10.0; poly[0].p[3].y = 0.0;
	x1 = y1 = 0.0;

	while (scanf("%lf%lf%s\n", &x2, &y2, str) == 3){
		if (str[0] == 'C') clippolygon((x1 + x2) * 0.5, (y1 + y2) * 0.5, (x1 + x2) * 0.5 + y2 - y1, (y1 + y2) * 0.5 + x1 - x2);
		else if (str[0] == 'H') clippolygon((x1 + x2) * 0.5, (y1 + y2) * 0.5, (x1 + x2) * 0.5 - y2 + y1, (y1 + y2) * 0.5 - x1 + x2);
		else{
			printf("0.00\n");
			break;
		}

		S = getarea(poly[c]);
		printf("%.2lf\n", S);
		if (S < 0.005) break;
		x1 = x2; y1 = y2;
	}

	while (scanf("%lf%lf%*s\n", &x2, &y2) == 2) printf("0.00\n");

	return 0;
}
/* @END_OF_SOURCE_CODE */
