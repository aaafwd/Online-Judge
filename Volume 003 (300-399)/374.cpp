/* @JUDGE_ID: 19899RK 374 C++ "By Anadan" */
// Big Mod
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>

int main(){
	long B, P, M, R, R1;

	while (scanf("%ld%ld%ld", &B, &P, &M) == 3){
		B %= M;
		R1 = B;
		if (M == 1L) R = 0L; else R = 1L;
		while (P){
			while (!(P & 1L)){
				R1 = (R1 * R1) % M;
				P >>= 1;
			}
			R = (R * R1) % M;
			P--;
		}
		printf("%ld\n", R);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
