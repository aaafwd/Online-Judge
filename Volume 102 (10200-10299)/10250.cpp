/* @JUDGE_ID: 19899RK 10250 C++ "By Anadan" */ 
// The Other Two Trees
// Accepted (0.119 seconds using as much as 384 kbytes)

#include <stdio.h>

int main(){
	double x1, y1, x2, y2;

	while (scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2) == 4){
		printf("%.10lf %.10lf %.10lf %.10lf\n", (x1+x2-y1+y2)*0.5, (y1+y2+x1-x2)*0.5, (x1+x2+y1-y2)*0.5, (y1+y2-x1+x2)*0.5);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
