/* @JUDGE_ID: 19899RK 10783 C++ "By Anadan" */
// Odd Sum
// Accepted (0.002 seconds with low memory spent)

#include <stdio.h>

int main() {
	int set, cs = 0, a, b, res;

	scanf("%d", &set);
	while (set--) {
		scanf("%d%d", &a, &b);
		if (!(a & 1)) ++a;
		if (!(b & 1)) --b;
		if (a <= b) {
			res = (a+b) * ((b-a)/2+1) / 2;
		} else {
			res = 0;
		}
		printf("Case %d: %d\n", ++cs, res);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
