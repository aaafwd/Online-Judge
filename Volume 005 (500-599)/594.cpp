/* @JUDGE_ID: 19899RK 594 C++ "By Anadan" */
// One Little, Two Little, Three Little Endians
// Accepted (0.010 seconds with low memory spent)

#include <stdio.h>

int main(){
	long N;
	while (scanf("%ld", &N) > 0){
		printf("%ld converts to ", N);
		N = ((N & 0x000000FF) << 24) | ((N & 0x0000FF00) << 8) |
		    ((N & 0x00FF0000) >> 8) | ((N & 0xFF000000) >> 24);
		printf("%ld\n", N);
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */
