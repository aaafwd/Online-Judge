/* @JUDGE_ID: 19899RK 264 C++ "By Anadan" */
// Count on Cantor
// Accepted (0.020 seconds using as much as 396 kbytes)

#include <stdio.h>
#include <math.h>

int main(){
	double N, row, tmp;

	while (scanf("%lf", &N) > 0){
		printf("TERM %.0lf IS ", N);
		row = ceil(0.5 * (sqrt(8.0*N + 1.0) - 1.0));
		if (fmod(row, 2.0))  tmp = row - N + 0.5*row*(row - 1) + 1.0;
		else tmp = N - 0.5*row*(row - 1);
		printf("%.0lf/%.0lf\n", tmp, row + 1.0 - tmp);
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */
