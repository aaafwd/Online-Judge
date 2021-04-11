/* @JUDGE_ID: 19899RK 10545 C++ "By Anadan" */
// Maximal Quadrilateral
// Accepted (0.002 seconds with low memory spent)

#include <stdio.h>
#include <math.h>

int main() {
	int set, cs = 0, P, A, B, C;
	double res;

	scanf("%d", &set);
	while (set--) {
		scanf("%d%d%d", &P, &A, &B);
		C =  P*P + 4*A*B - 2*P*(A+B);
		if (C <= 0) printf("Case %d: Eta Shombhob Na.\n", ++cs);
		else {
			res = sqrt(double(C)*A*B/P/P);
			printf("Case %d: %.6lf\n", ++cs, res);
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
