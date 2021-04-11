/* @JUDGE_ID: 19899RK 10451 C++ "By Anadan" */ 
// Ancient Village Sports
// Accepted (0.148 seconds using as much as 396 kbytes)

#include <stdio.h>
#include <math.h>

inline double sqr(double x) { return x * x; }

int main(){
	int set = 0, N;
	double A, s, s1;
	const double pi = acos(0.0) * 2.0;

	while (scanf("%d%lf\n", &N, &A) == 2 && N > 2){
		s = 2.0 * A / sin(2.0*pi / N) / N;
		s1 = s * sqr(cos(pi / N));
		printf("Case %d: %.5lf %.5lf\n", ++set, pi*s - A, A - pi*s1);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
