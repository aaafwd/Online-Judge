/* @JUDGE_ID: 19899RK 10240 C++ "By Anadan" */ 
// The n-Dimensional Cities
// Accepted (0.010 seconds with low memory spent)

#include <stdio.h>
#include <math.h>

int main(){
	int dim, dist, d, n1, n2;
	double res;

	// Turan's theorem: max_edges(N) = N*N / 4
	while (scanf("%d%d%d\n", &dim, &dist, &d) == 3){
		++dim;
		n2 = dim * dim / 4;
		printf("%d ", n2);
		n1 = n2 / 2; n2 -= n1;
		res = 0.5 * double(dist) / d;
		if (res > 1.0) res = 1.0;
		res = asin(res) * 2.0 * d * n1 + double(n2) * dist;
		printf("%.0lf\n", res);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
