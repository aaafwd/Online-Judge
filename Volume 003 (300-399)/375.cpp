/* @JUDGE_ID: 19899RK 375 C++ "By Anadan" */
// Inscribed Circles and Isosceles Triangles
// Accepted (0.370 seconds using as much as 396 kbytes)

#include <stdio.h>
#include <math.h>

int main(){
	long set;
	double B, H, C, r, d, pi = acos(0.0) * 2.0;

	scanf("%ld\n", &set);
	while (set--){
		scanf("%lf%lf", &B, &H);
		C = 0.0;
		d = sqrt(4.0*H*H/B/B + 1.0) + 1.0;
		r = H / d;
		while (r >= 0.000001){
			C += 2.0 * pi * r;
			H -= 2.0 * r;
			r = H / d;
		}
		printf("%13.6lf\n", C);
		if (set) printf("\n");
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
