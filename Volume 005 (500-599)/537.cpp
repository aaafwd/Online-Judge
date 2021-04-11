/* @JUDGE_ID: 19899RK 537 C++ "By Anadan" */
// Artificial Intelligence?
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>

int main(){
	int set, c, p = 0, k;
	char fp, fu, fi;
	double P, U, I;

	scanf("%d", &set);
	while (getchar() != '\n');
	for (k = 1; k <= set; ++k){
		printf("Problem #%d\n", k);
		fp = fu = fi = 0;

		while ((c = getchar()) != '\n'){
			if (c == '='){
				if (p == 'P'){
					scanf("%lf", &P), fp = 1;
					c = getchar();
					if (c == 'm') P *= 0.001;
					else if (c == 'k') P *= 1000.0;
					else if (c == 'M') P *= 1000000.0;
				}
				else if (p == 'U'){
					scanf("%lf", &U), fu = 1;
					c = getchar();
					if (c == 'm') U *= 0.001;
					else if (c == 'k') U *= 1000.0;
					else if (c == 'M') U *= 1000000.0;
				}
				else if (p == 'I'){
					scanf("%lf", &I), fi = 1;
					c = getchar();
					if (c == 'm') I *= 0.001;
					else if (c == 'k') I *= 1000.0;
					else if (c == 'M') I *= 1000000.0;
				}
				else return 1;
			}else p = c;
		}

		if (fp == 0) printf("P=%.2lfW\n\n", U*I);
		else if (fu == 0) printf("U=%.2lfV\n\n", P/I);
		else if (fi == 0) printf("I=%.2lfA\n\n", P/U);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
