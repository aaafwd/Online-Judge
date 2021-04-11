/* @JUDGE_ID: 19899RK 10573 C++ "By Anadan" */
// Geometry Paradox
// Accepted (0.002 seconds with low memory spent)

#include <stdio.h>
#include <math.h>

int main(){
	int set, a, b, i;
	const double pi = acos(0.0) * 2.0;

	scanf("%d", &set);
	while (getchar() != '\n');

	while (set--){
		scanf("%d", &a);
		b = -1;
		while ((i = getchar()) != '\n'){
			if ('0' <= i && i <= '9'){
				ungetc(i, stdin);
				scanf("%d", &b);
				while (getchar() != '\n');
				break;
			}
		}

		if (b == -1){
			printf("%.4lf\n", pi * a * a * 0.125);
		}else{
			printf("%.4lf\n", pi * a * b * 2);
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
