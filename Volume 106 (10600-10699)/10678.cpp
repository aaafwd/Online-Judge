/* @JUDGE_ID: 19899RK 10678 C++ "By Anadan" */
// The Grazing Cow
// Accepted (0.002 seconds with low memory spent)

#include <stdio.h>
#include <math.h>

int main(){
	int set, D, L;
	const double pi_4 = acos(0) / 2;

	scanf("%d", &set);
	while (set--){
		scanf("%d%d", &D, &L);
		printf("%.3lf\n", pi_4 * L * sqrt(L*L - D*D));
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
