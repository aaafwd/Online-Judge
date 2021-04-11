/* @JUDGE_ID: 19899RK 10170 C++ "By Anadan" */ 
// The Hotel with Infinite Rooms
// Accepted (0.064 seconds with low memory spent)

#include <stdio.h>
#include <math.h>

typedef long long qword;

int main(){
	qword S, D, i, j;
	double tmp;

	while (scanf("%lld%lld\n", &S, &D) == 2){
		i = (S*2 - 1) * (S*2 - 1) + D * 8;
		tmp = sqrt(i);
		j = (qword)tmp;
		if (j * j == i) printf("%lld\n", S + (j - S*2 - 1) / 2);
		else printf("%.0lf\n", ceil(0.5 * (tmp - S*2 - 1)) + double(S));
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
