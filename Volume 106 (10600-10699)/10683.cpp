/* @JUDGE_ID: 19899RK 10683 C++ "By Anadan" */
// The decadary watch
// Accepted (0.475 seconds using as much as 388 kbytes)

#include <stdio.h>

int main() {
	int hh, mm, ss, cc;
	const double coeff = 1 / 0.864;

	while (scanf("%2d%2d%2d%2d", &hh, &mm, &ss, &cc) == 4) {
		cc += 100*ss + 100*60*mm + 100*60*60*hh;
		cc = int(cc * coeff);
		hh = cc / 1000000;
		cc -= hh * 1000000;
		mm = cc / 10000;
		cc -= mm * 10000;
		ss = cc / 100;
		cc -= ss * 100;
		printf("%01d%02d%02d%02d\n", hh, mm, ss, cc);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
