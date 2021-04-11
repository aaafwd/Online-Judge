/* @JUDGE_ID: 19899RK 10127 C++ "By Anadan" */
// Ones
// Accepted (0.010 seconds with low memory spent)

#include <stdio.h>

int main(){
	long n, rest, ones;

	while (scanf("%ld", &n) > 0){
		rest = ones = 0L;
		do{
			rest *= 10;
			rest = (rest + 1) % n;
			++ones;
		}while (rest);
		printf("%ld\n", ones);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
