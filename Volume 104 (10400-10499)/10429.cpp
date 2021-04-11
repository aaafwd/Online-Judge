/* @JUDGE_ID: 19899RK 10429 C++ "By Anadan" */ 
// Mohr's Circle
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>
#include <math.h>

int main(){
	int set = 0, sx, sy, t;
	double r, acd, oc;
	const double i_90_pi = 45.0 / acos(0.0);

	while (scanf("%d%d%d", &sx, &sy, &t) == 3){
		if (t) scanf("%*s");

		r = sqrt((sx - sy) * (sx - sy) + 4 * t * t) * 0.5;
		oc = double(sx + sy) * 0.5;
		if (sx == sy) acd = 45.0;
		else acd = fabs(atan2(t, sx - oc)) * i_90_pi;

		if (set) putchar('\n');
		printf("Element : %d\n", ++set);
		printf("Position of maximum normal stresses : %.2lf deg\n", acd);
		printf("Maximum normal stresses : %.2lf MPa and %.2lf MPa\n\n", oc + r, oc - r);
		printf("Position of maximum shear stresses : %.2lf deg\n", acd + 45.0);
		printf("Maximum shear stress (xy plane) : %.2lf MPa\n", r);
		printf("Normal stress at this condition : %.2lf MPa\n", oc);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
