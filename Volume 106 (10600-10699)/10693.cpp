/* @JUDGE_ID: 19899RK 10693 C++ "By Anadan" */
// Traffic Volume
// Accepted (0.002 seconds with low memory spent)

#include <stdio.h>
#include <math.h>

int main(){
	int L, f;
	double v;

	while (scanf("%d%d", &L, &f) == 2 && L){
		v = sqrt(2*L*f);
		printf("%.8lf %.8lf\n", v, v/L*1800);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
