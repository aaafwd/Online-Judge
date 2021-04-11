/* @JUDGE_ID: 19899RK 10499 C++ "By Anadan" */ 
// The Land of Justice
// Accepted (0.062 seconds with low memory spent)

#include <stdio.h>

int main(){
	int N;
	long long res;

	while (scanf("%d", &N) == 1 && N > 0){
		if (N == 1) puts("0%");
		else{
			res = N;
			res *= 25;
			printf("%lld%%\n", res);
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
