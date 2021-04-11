/* @JUDGE_ID: 19899RK 10406 C++ "By Anadan" */
// Cutting tabletops
// Accepted (0.002 seconds with low memory spent)

#include <stdio.h>
#include <math.h>

struct Point{
	double x, y;

	Point operator - (Point &p){
		Point res;
		res.x = x - p.x;
		res.y = y - p.y;
		return res;
	}

	Point operator + (Point &p){
		Point res;
		res.x = x + p.x;
		res.y = y + p.y;
		return res;
	}

	void operator += (Point &p){
		x += p.x;
		y += p.y;
	}

	void operator *= (double d){
		x *= d;
		y *= d;
	}

	void normalize(){
		double tmp = sqrt(x*x + y*y);
		if (tmp > 1e-12){
			x /= tmp; y /= tmp;
		}
	}

}pt[100], pt1[100];

double getpolyarea(Point *ptr, int N){
	int i;
	double S = 0, tmp;

	for (i = 1; i < N - 1; ++i){
		tmp = (ptr[0].y - ptr[i].y) * (ptr[i + 1].x - ptr[i].x) - (ptr[i + 1].y - ptr[i].y) * (ptr[0].x - ptr[i].x);
		S += tmp * 0.5;
	}

	return fabs(S);
}

int main(){
	int N, i, j, k;
	double d, x, y, cs, tmp;
	Point p1, p2;

	while (scanf("%lf%d", &d, &N) == 2 && N){
		for (i = 0; i < N; ++i){
			scanf("%lf%lf", &x, &y);
			pt[i].x = x; pt[i].y = y;
		}

		for (i = 0; i < N; ++i){
			j = (i + 1) % N;
			k = (i + N - 1) % N;
			p1 = pt[j] - pt[i];
			p2 = pt[k] - pt[i];
			p1.normalize();
			p2.normalize();
			cs = p1.x * p2.x + p1.y * p2.y;
			tmp = d / sqrt(1.0 - cs*cs + 1e-12);
			pt1[i] = p1 + p2;
			pt1[i] *= tmp;
			pt1[i] += pt[i];
		}

		printf("%.3lf\n", getpolyarea(pt1, N));
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
