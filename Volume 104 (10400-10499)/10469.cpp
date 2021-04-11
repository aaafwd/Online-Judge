/* @JUDGE_ID: 19899RK 10469 C++ "By Anadan" */ 
// To Carry or not to Carry
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>

int main(){
	unsigned int a, b;

	while (scanf("%u%u\n", &a, &b) == 2){
		printf("%u\n", a ^ b);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
