/* @JUDGE_ID: 19899RK 478 C++ "By Anadan" */
// Points in Figures: Rectangles
// Accepted (0.070 seconds using as much as 400 kbytes)

#include <stdio.h>
#include <math.h>

struct shape{
	double x1, y1, x2, y2, x3, y3;
	char ch;
}pt[100];
int id = 0;
double x, y;

inline double sqr(double val) { return val*val; }

int contain(int i){
	int res = 0;
	double v1, v2, v3;

	switch (pt[i].ch){
	case 'r':
		if ((x <= pt[i].x1) || (x >= pt[i].x2)) break;
		if ((y <= pt[i].y2) || (y >= pt[i].y1)) break;
		res = 1;
		break;
	case 'c':
		if (sqr(x-pt[i].x1) + sqr(y-pt[i].y1) < sqr(pt[i].x2)) res = 1;
		break;
	case 't':
		v1 = ((pt[i].x1-x)*(pt[i].y2-y)) - ((pt[i].x2-x)*(pt[i].y1-y));
		v2 = ((pt[i].x2-x)*(pt[i].y3-y)) - ((pt[i].x3-x)*(pt[i].y2-y));
		v3 = ((pt[i].x3-x)*(pt[i].y1-y)) - ((pt[i].x1-x)*(pt[i].y3-y));
		if ((!v1) || (!v2) || (!v3)) break;
		if ((v1 < 0) && (v2 < 0) && (v3 < 0)) res = 1;
		if ((v1 > 0) && (v2 > 0) && (v3 > 0)) res = 1;
		break;
	default : break;
	}
	return res;
}

void swap(double *a, double *b){
	double tmp = *a; *a = *b; *b = tmp;
}
int main(){
	int i;
	long n = 1L;
	char ch;

	while (1){
		scanf("%c", &ch);
		if (ch == '*') break;
		if (ch == 'r'){
			scanf("%lf%lf%lf%lf\n", &pt[id].x1, &pt[id].y1, &pt[id].x2, &pt[id].y2);
			if (pt[id].x1 > pt[id].x2) swap(&pt[id].x1, &pt[id].x2);
			if (pt[id].y1 < pt[id].y2) swap(&pt[id].y1, &pt[id].y2);
		}
		else if (ch == 'c') scanf("%lf%lf%lf\n", &pt[id].x1, &pt[id].y1, &pt[id].x2);
		else if (ch == 't') scanf("%lf%lf%lf%lf%lf%lf\n", &pt[id].x1, &pt[id].y1, &pt[id].x2, &pt[id].y2, &pt[id].x3, &pt[id].y3);
		pt[id++].ch = ch;
	}

	while (scanf("%lf%lf", &x, &y) == 2){
		if ((x == 9999.9) && (y == 9999.9)) break;
		for (ch = 0, i = 0; i < id; i++){
			if (contain(i)){
				printf("Point %ld is contained in figure %d\n", n, i+1);
				ch = 1;
			}
		}
		if (!ch) printf("Point %ld is not contained in any figure\n", n);
		n++;
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
