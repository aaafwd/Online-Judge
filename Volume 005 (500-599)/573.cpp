/* @JUDGE_ID: 19899RK 573 C++ "By Anadan" */
// The Snail
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>
#include <math.h>

int main(){
	int D, F, days;
	double curh, df, H, U;

	while (scanf("%lf%lf%d%d", &H, &U, &D, &F) == 4 && H){
		days = 0;
		curh = 0.0;
		df = 0.01 * U * F;

		while (1){
			++days;
			curh += U;
			if (curh > H){
				printf("success on day %d\n", days);
				break;
			}

			curh -= D;
			if (curh < 0){
				printf("failure on day %d\n", days);
				break;
			}

			U -= df;
			if (U <= 0.0){
				days += (int)ceil(curh / D + 1e-12);
				printf("failure on day %d\n", days);
				break;
			}
		}
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */
