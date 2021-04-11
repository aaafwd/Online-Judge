/* @JUDGE_ID: 19899RK 10777 C++ "By Anadan" */
// God! Save me
// Accepted (0.006 seconds with low memory spent)

#include <stdio.h>

int main() {
	int set, cs = 0, N, i;
	double x, Ex, p, sump;

	scanf("%d", &set);
	while (set--) {
		scanf("%d", &N);
		sump = Ex = 0;
		for (i = 0; i < N; ++i) {
			scanf("%lf%lf", &x, &p);
			if (x > 0) {
				sump += p;
				Ex += x * p;
			} else {
				Ex -= x * p;
			}
		}

		if (sump == 0) printf("Case %d: God! Save me\n", ++cs);
		else printf("Case %d: %.2lf\n", ++cs, Ex/sump);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
