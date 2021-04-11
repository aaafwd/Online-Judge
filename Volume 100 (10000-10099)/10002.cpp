/* @JUDGE_ID: 19899RK 10002 C++ "By Anadan" */ 
// Center of Masses
// Accepted (0.613 seconds using as much as 404 kbytes)

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

struct Point{
	int x, y;
	double fi;
}pt[100];

int sort_function(const void *a, const void *b){
	if (((Point *)a)->fi < ((Point *)b)->fi) return -1;
	return 1;
}

int getarea(int i, int j, int k){
	return abs((pt[j].x - pt[i].x)*(pt[k].y - pt[i].y) - (pt[k].x - pt[i].x)*(pt[j].y - pt[i].y));
}

int main(){
	int N, i;
	double x, y, m, cx, cy, cm;

	while (scanf("%d\n", &N) == 1 && N > 2){
		cx = cy = 0.0;
		for (i = 0; i < N; ++i){
			scanf("%d%d", &pt[i].x, &pt[i].y);
			cx += pt[i].x; cy += pt[i].y;
		}

		cx /= N; cy /= N;
		for (i = 0; i < N; ++i){
			pt[i].fi = atan2(pt[i].y - cy, pt[i].x - cx);
		}
		qsort(pt, N, sizeof(Point), sort_function);

		cx = double(pt[1].x + pt[2].x + pt[0].x) / 3.0;
		cy = double(pt[1].y + pt[2].y + pt[0].y) / 3.0;
		cm = (double)getarea(0, 1, 2);
		for (i = 3; i < N; ++i){
			x = double(pt[i].x + pt[i - 1].x + pt[0].x) / 3.0;
			y = double(pt[i].y + pt[i - 1].y + pt[0].y) / 3.0;
			m = (double)getarea(0, i - 1, i);
			cx = (cm * cx + m * x) / (cm + m);
			cy = (cm * cy + m * y) / (cm + m);
			cm += m;
		}

		printf("%.3lf %.3lf\n", cx, cy);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
