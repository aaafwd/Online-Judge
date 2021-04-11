/* @JUDGE_ID: 19899RK 10217 C++ "By Anadan" */
// A Dinner with Schwarzenegger !!!
// Accepted (0.016 seconds with low memory spent)

#include <stdio.h>
#include <math.h>

int main(){
	int N;
	double res, intres;

	while (scanf("%d\n", &N) == 1){
		res = (sqrt(1 + N * 4) - 1.0) * 0.5;
		intres = floor(res);
		if (intres * intres - intres < N) ++intres;
		printf("%.2lf %.0lf\n", res, intres);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
