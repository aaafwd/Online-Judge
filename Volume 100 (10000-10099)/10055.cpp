/* @JUDGE_ID: 19899RK 10055 C++ "By Anadan" */
// Hashmat the brave warrior 
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>

int main(){
	double a, b;

	while (scanf("%lf%lf", &a, &b) == 2){
		if (a > b) printf("%.0lf\n", a-b);
		else printf("%.0lf\n", b-a);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
