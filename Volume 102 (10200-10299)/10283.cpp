/* @JUDGE_ID: 19899RK 10283 C++ "By Anadan" */
// The Kissing Circles
// Accepted (0.470 seconds using as much as 396 kbytes)

#include <stdio.h>
#include <math.h>

int main(){
	int R, N;
	double E, I, r, tmp, pi = acos(0.0) * 2.0;

	while (scanf("%d%d\n", &R, &N) == 2){
		if (N == 1) printf("%.10lf 0.0000000000 0.0000000000\n", double(R));
		else{
			tmp = sin(pi / N);
			r = tmp / (1.0 + tmp) * R;
			E = (pi*R*R/N - r*sqrt(1.0*R*R - 2.0*r*R) - 0.5*(2.0*pi/N + pi)*r*r) * N;
			if (N == 2) I = 0.0;
			else I = pi*R*R - pi*r*r*N - E;
			printf("%.10lf %.10lf %.10lf\n", r, I, E);
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
