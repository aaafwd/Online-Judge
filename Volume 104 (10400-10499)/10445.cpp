/* @JUDGE_ID: 19899RK 10445 C++ "By Anadan" */ 
// Make Polygon
// Accepted (0.002 seconds with low memory spent)

#include <stdio.h>
#include <math.h>

struct Point{
	int x, y;
}pt[20];

int getorient(int N){
	int i, S = 0, tmp;

	for (i = 1; i < N - 1; ++i){
		tmp = (pt[0].y - pt[i].y) * (pt[i + 1].x - pt[i].x) - (pt[i + 1].y - pt[i].y) * (pt[0].x - pt[i].x);
		S += tmp;
	}

	return S;
}

int main(){
	int N, i, j, k, orient;
	double tmp, a, b, min, max;
	const double i_180_pi = 90.0 / acos(0.0);

	while (scanf("%d\n", &N) == 1 && N > 2){
		for (i = 0; i < N; ++i) scanf("%d%d\n", &pt[i].x, &pt[i].y);
		min = max = -1.0;
		orient = getorient(N);
		for (i = 0; i < N; ++i){
			j = (i + 1) % N;
			k = (j + 1) % N;

			tmp = (pt[i].x - pt[j].x) * (pt[k].x - pt[j].x) + (pt[i].y - pt[j].y) * (pt[k].y - pt[j].y);
			a = (pt[i].x - pt[j].x) * (pt[i].x - pt[j].x) + (pt[i].y - pt[j].y) * (pt[i].y - pt[j].y);
			b = (pt[k].x - pt[j].x) * (pt[k].x - pt[j].x) + (pt[k].y - pt[j].y) * (pt[k].y - pt[j].y);

			k = (pt[k].x - pt[j].x) * (pt[j].y - pt[i].y) - (pt[k].y - pt[j].y) * (pt[j].x - pt[i].x);
			tmp = acos(tmp / sqrt(a * b)) * i_180_pi;

			if ((orient > 0) ^ (k < 0)) tmp = 360.0 - tmp;
			if (max == -1 || max < tmp) max = tmp;
			if (min == -1 || min > tmp) min = tmp;
		}

		printf("%.6lf %.6lf\n", min, max);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
