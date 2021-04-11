/* @JUDGE_ID: 19899RK 10323 C++ "By Anadan" */
// Factorial! You Must be Kidding!!!
// Accepted (0.070 seconds with low memory spent)

#include <stdio.h>

int main(){
	long n;
	while (scanf("%ld", &n) > 0){
		if (n > 13) printf("Overflow!\n");
		else if (n == 8) printf("40320\n");
		else if (n == 9) printf("362880\n");
		else if (n == 10) printf("3628800\n");
		else if (n == 11) printf("39916800\n");
		else if (n == 12) printf("479001600\n");
		else if (n < 0){
			if (n & 1) printf("Overflow!\n");
			else printf("Underflow!\n");
		}
		else if (n < 8) printf("Underflow!\n");
		else printf("6227020800\n");
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
