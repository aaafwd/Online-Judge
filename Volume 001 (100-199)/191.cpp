/* @JUDGE_ID: 19899RK 191 C++ "By Anadan" */ 
// Intersection
// Accepted (0.010 seconds with low memory spent)

#include <stdio.h>

struct POINT{
	double x, y;
};

inline double sqr(double x) { return x*x; }

int isCrossed(POINT p1, POINT p2, POINT p3, POINT p4){
	double det = (p2.x - p1.x) * (p3.y - p4.y) - (p3.x - p4.x) * (p2.y - p1.y);
	double it1 = (p3.x - p1.x) * (p3.y - p4.y) - (p3.x - p4.x) * (p3.y - p1.y);
	double it2 = (p2.x - p1.x) * (p3.y - p1.y) - (p3.x - p1.x) * (p2.y - p1.y);

	if (det == 0){
		if (p1.x == p3.x && p1.y == p3.y) return 1;
		if (it1 || it2) return 0;

		double ro12 = sqr(p1.x - p2.x) + sqr(p1.y - p2.y);
		double ro34 = sqr(p3.x - p4.x) + sqr(p3.y - p4.y);
		double ro1x = sqr(p1.x - p3.x) + sqr(p1.y - p3.y);
		double ro2x = sqr(p2.x - p3.x) + sqr(p2.y - p3.y);

		if (ro1x + ro2x == ro12) return 1;
		ro2x = sqr(p1.x - p4.x) + sqr(p1.y - p4.y);
		if (ro1x + ro2x == ro34) return 1;
		ro1x = sqr(p2.x - p4.x) + sqr(p2.y - p4.y);
		if (ro1x + ro2x == ro12) return 1;
		ro2x = sqr(p2.x - p3.x) + sqr(p2.y - p3.y);
		if (ro1x + ro2x == ro34) return 1;

		return 0;
	}

	if (det < 0){
		if ((it1 > 0) || (it1 < det)) return 0;
		if ((it2 > 0) || (it2 < det)) return 0;
	}
	else{
		if ((it1 < 0) || (it1 > det)) return 0;
		if ((it2 < 0) || (it2 > det)) return 0;
	}
	return 1;
}

int inRectangle(double x1, double y1, double x2, double y2, double x, double y){
	if ((x < x1) || (x > x2)) return 0;
	if ((y < y2) || (y > y1)) return 0;
	return 1;
}

int main(){
	long N;
	double x1, y1, x2, y2, tmp;
	POINT p1, p2, p3, p4;
	scanf("%ld", &N);

	while (N--){
		scanf("%lf%lf%lf%lf%lf%lf%lf%lf", &p1.x, &p1.y, &p2.x, &p2.y, &x1, &y1, &x2, &y2);
		if (x1 > x2) { tmp = x1; x1 = x2; x2 = tmp; }
		if (y1 < y2) { tmp = y1; y1 = y2; y2 = tmp; }
		if (inRectangle(x1, y1, x2, y2, p1.x, p1.y))
			{ printf("T\n"); continue; }
		if (inRectangle(x1, y1, x2, y2, p2.x, p2.y))
			{ printf("T\n"); continue; }
		p3.x = x1; p3.y = y1;
		p4.x = x2; p4.y = y1;
		if (isCrossed(p1, p2, p3, p4)) { printf("T\n"); continue; }
		p4.x = x1; p4.y = y2;
		if (isCrossed(p1, p2, p3, p4)) { printf("T\n"); continue; }
		p3.x = x2; p3.y = y2;
		p4.x = x2; p4.y = y1;
		if (isCrossed(p1, p2, p3, p4)) { printf("T\n"); continue; }
		p4.x = x1; p4.y = y2;
		if (isCrossed(p1, p2, p3, p4)) { printf("T\n"); continue; }
		printf("F\n");
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
