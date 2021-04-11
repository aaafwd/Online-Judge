/* @JUDGE_ID: 19899RK 754 C++ "By Anadan" */ 
// Treasure Hunt
// Accepted (0.004 seconds with low memory spent)

#include <stdio.h>

int N, min;
double x, y;
struct Line{
	int x1, y1, x2, y2;
}pt[30];

void setmindoors(int wx, int wy){
	int i, tmp, res = 1;
	double dtmp;

	for (i = 0; i < N; ++i){
		tmp = (wx - pt[i].x1) * (pt[i].y2 - pt[i].y1) - (pt[i].x2 - pt[i].x1) * (wy - pt[i].y1);
		dtmp = (x - pt[i].x1) * (pt[i].y2 - pt[i].y1) - (pt[i].x2 - pt[i].x1) * (y - pt[i].y1);
		if ((tmp < 0 && dtmp > 0) || (tmp > 0 && dtmp < 0)) ++res;
	}

	if (min > res) min = res;
}

int main(){
	int set, i;

	scanf("%d\n\n", &set);
	while (set--){
		scanf("%d\n", &N);
		for (i = 0; i < N; ++i) scanf("%d%d%d%d\n", &pt[i].x1, &pt[i].y1, &pt[i].x2, &pt[i].y2);
		scanf("%lf%lf\n", &x, &y);
		
		min = N + 1;
		for (i = 0; i < N; ++i){
			setmindoors(pt[i].x1, pt[i].y1);
			setmindoors(pt[i].x2, pt[i].y2);
		}

		printf("Number of doors = %d\n", min);
		if (set) putchar('\n');
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
