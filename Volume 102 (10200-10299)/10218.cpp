/* @JUDGE_ID: 19899RK 10218 C++ "By Anadan" */
// Let's Dance!!
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>
#include <math.h>

int main() {
	int M, W, C, i;
	double p, res, tmp, coeff;

	while (scanf("%d%d%d", &M, &W, &C) == 3 && (M || W)) {
		if (W) {
			p = double(M) / (M + W);
			coeff = p/(1-p); coeff *= coeff;
			res = tmp = pow(1-p, C);
			for (i = 2; i <= C; i += 2) {
				tmp *= (C-i+1) * (C-i+2);
				tmp /=  i*(i-1);
				tmp *= coeff;
				res += tmp;
			}
		} else {
			if (C & 1) res = 0; else res = 1;
		}
		printf("%.7lf\n", res);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
