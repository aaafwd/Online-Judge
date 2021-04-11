/* @JUDGE_ID: 19899RK 10488 C++ "By Anadan" */ 
// A Swimming Gopher
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>
#include <math.h>

int main(){
	int N;
	double D, L, xs, ys, xt, yt, tmp;

	while (scanf("%lf%lf%lf%lf%lf%lf", &D, &L, &xs, &ys, &xt, &yt) == 6){
		N = floor((ys - L) / D) - floor((yt - L) / D);
		if (N < 0) N = -N;
		if (ys < yt) ys += L * N * 2; else ys -= L * N * 2;
		tmp = sqrt((xt - xs) * (xt - xs) + (yt - ys) * (yt - ys));
		printf("The gopher has to swim %.2lf meters and walk %.2lf meters.\n", L * N * 2, tmp);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
