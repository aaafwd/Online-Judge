/* @JUDGE_ID: 19899RK 10398 C++ "By Anadan" */
// The Golden Pentagon
// Accepted (0.033 seconds with low memory spent)

#include <stdio.h>
#include <math.h>

const double q = 1.324717957244746;

int main(){
	int I, D;
	double S;

	while (scanf("%lf%d\n", &S, &I) == 2){
		D = floor(log10(S) + log10(q) * (I - 1) + 1.0);
		if (D >= 10) printf("%d\n", D);
		else printf("%.0lf\n", floor(S * pow(q, I - 1)));
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
