/* @JUDGE_ID: 19899RK 609 C++ "By Anadan" */
// Metal Cutting
// Accepted (3.697 seconds using as much as 404 kbytes)

#include <stdio.h>
#include <string.h>
#include <math.h>

double min;
char mask[8];
int x[8], y[8], n, m, p;

struct Point{
	double x, y;
};

struct Polygon{
	int N;
	Point p[15];
};

Point getintersection(Point p1, Point p2, double x3, double y3, double x4, double y4){
	double det = (p2.x - p1.x) * (y3 - y4) - (x3 - x4) * (p2.y - p1.y);
	double it1 = (x3 - p1.x) * (y3 - y4) - (x3 - x4) * (y3 - p1.y);
	Point res;
	res.x = p1.x + (p2.x - p1.x) * it1 / det;
	res.y = p1.y + (p2.y - p1.y) * it1 / det;
	return res;
}

int inleft(double x, double y, double x0, double y0, double x1, double y1){
	double tmp = (x-x0)*(y1-y0) - (x1-x0)*(y-y0);
	if (tmp > -1e-12) return 0;
	return 1;
}

double clippolygon(double x1, double y1, double x2, double y2, Polygon &in, Polygon &out){
	int i, j, N = 0, c = 0;
	double res;
	Point p[2];

	for (i = 0; i < in.N; ++i){
		if (i == in.N - 1) j = 0; else j = i + 1;
		if (inleft(in.p[i].x, in.p[i].y, x1, y1, x2, y2)){
			if (inleft(in.p[j].x, in.p[j].y, x1, y1, x2, y2)) continue;
			p[c++] = out.p[N++] = getintersection(in.p[i], in.p[j], x1, y1, x2, y2);
			out.p[N++] = in.p[j];
		}else{
			if (inleft(in.p[j].x, in.p[j].y, x1, y1, x2, y2)){
				p[c++] = out.p[N++] = getintersection(in.p[i], in.p[j], x1, y1, x2, y2);
			}else{
				out.p[N++] = in.p[j];
			}
		}
	}

	out.N = N;
	res = sqrt((p[0].x-p[1].x)*(p[0].x-p[1].x) + (p[0].y-p[1].y)*(p[0].y-p[1].y));
	return res;
}

void generate(int n, double curlen, Polygon &in){
	int i, j;
	double tmp;
	Polygon out;

	if (n == p){
		if (min > curlen) min = curlen;
		return;
	}

	for (i = 0; i < p; ++i){
		if (mask[i] == 0){
			mask[i] = 1;
			if (i == p - 1) j = 0; else j = i + 1;
			tmp = clippolygon(x[i], y[i], x[j], y[j], in, out);
			generate(n + 1, curlen + tmp, out);
			mask[i] = 0;
		}
	}
}

int main(){
	int i, set;
	Polygon poly;

	scanf("%d\n\n", &set);
	while (set--){
		scanf("%d%d%d", &n, &m, &p);
		for (i = 0; i < p; ++i) scanf("%d%d", x + i, y + i);
		min = 30000.0;

		poly.N = 4;
		poly.p[0].x = 0.0; poly.p[0].y = 0.0;
		poly.p[1].x = 0.0; poly.p[1].y = double(m);
		poly.p[2].x = double(n); poly.p[2].y = double(m);
		poly.p[3].x = double(n); poly.p[3].y = 0.0;
		memset(mask, 0, 8);
		generate(0, 0.0, poly);
		printf("Minimum total length = %.3lf\n", min);

		if (set) putchar('\n');
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
