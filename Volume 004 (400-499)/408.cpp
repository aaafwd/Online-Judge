/* @JUDGE_ID: 19899RK 408 C++ "By Anadan" */
// Uniform Generator
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>
#include <math.h>

int nomnoj(long a, long  b){
	long i;
	if (a > b) { a ^= b; b ^= a; a ^= b; }
	for (i = 2; i <= sqrt(a); i++){
		if (!(a % i)){
			if (!(b % i)) return 0;
			while (!(a % i)) a /= i;
		}
	}
	if (a > 1 && (!(b % a))) return 0;
	return 1;
}

int main(){
	long step, mod;
	while (scanf("%ld%ld", &step, &mod) == 2){
		if (mod == 1L || nomnoj(step, mod))
			printf("%10ld%10ld    Good Choice\n\n", step, mod);
		else printf("%10ld%10ld    Bad Choice\n\n", step, mod);
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */
