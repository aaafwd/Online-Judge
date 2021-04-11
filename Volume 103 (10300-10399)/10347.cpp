/* @JUDGE_ID: 19899RK 10347 C++ "By Anadan" */
// Medians
// Accepted (0.010 seconds with low memory spent)

#include <stdio.h>
#include <math.h>

int main(){
	double m1, m2, m3, S, a, b, c, p, area;

	while (scanf("%lf%lf%lf", &m1, &m2, &m3) == 3){
		m1 *= 2.0; m2 *= 2.0; m3 *= 2.0;
		S = (m1*m1 + m2*m2 + m3*m3) * 2.0 / 3.0;
		if (S <= m1*m1 || S <= m2*m2 || S <= m3*m3) area = -1.0;
		else{
			a = sqrt((S - m1*m1) / 3.0);
			b = sqrt((S - m2*m2) / 3.0);
			c = sqrt((S - m3*m3) / 3.0);
			if (a >= b + c || b >= a + c || c >= a + b) area = -1.0;
			else{
				p = (a + b + c) * 0.5;
				area = sqrt(p * (p - a) * (p - b) * (p - c));
				if (area < 1e-12) area = -1.0;
			}
		}

		printf("%.3lf\n", area);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
