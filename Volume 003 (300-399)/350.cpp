/* @JUDGE_ID: 19899RK 350 C++ "By Anadan" */ 
// Pseudo-Random Numbers
// Accepted (0.020 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

int main(){
	char flags[10000];
	long Z, I, M, L, C, N = 0L;

	while (scanf("%ld%ld%ld%ld", &Z, &I, &M, &L) == 4){
		if ((!Z) && (!I) && (!M) && (!L)) break;
		printf("Case %ld: ", ++N);
		memset(flags, 0, 10000);
		C = 0L;
		while (1){
			L = (Z*L + I) % M;
			if (flags[L]) break;
			flags[L] = 1;
			C++;
		}
		printf("%ld\n", C);
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */
