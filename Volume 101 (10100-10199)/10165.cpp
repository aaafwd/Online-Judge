/* @JUDGE_ID: 19899RK 10165 C++ "By Anadan" */ 
// Stone Game
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>

int main(){
	int N, i, nim_xor;

	while (scanf("%d\n", &N) == 1 && N){
		nim_xor = 0;
		while (N--){
			scanf("%d\n", &i);
			nim_xor ^= i;
		}

		puts((nim_xor) ? ("Yes") : ("No"));
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
