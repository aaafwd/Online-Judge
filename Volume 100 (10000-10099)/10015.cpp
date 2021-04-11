/* @JUDGE_ID: 19899RK 10015 C++ "By Anadan" */
// Joseph's Cousin
// Accepted (0.030 seconds with low memory spent)

#include <math.h>
#include <stdio.h>
#include <string.h>

int isprime(unsigned int a){
	unsigned int i, toi = (unsigned int)sqrt(a);
	for (i = 3; i <= toi; i += 2) if (!(a % i)) return 0;
	return 1;
}

int main(){
	unsigned int flags[3501], ms[3500], i, n, pos, *curm;

	for (ms[0] = 1, i = 3, n = 1 ;; i += 2){
		if (isprime(i)){
			ms[n++] = i - 1;
			if (n == 3500) break;
		}
	}

	while (scanf("%u", &n) > 0){
		if (n == 0) break;
		for (i = 0; i < n; i++) flags[i] = i;
		for (curm = ms, pos = 0, i = n; i > 1; i--, curm++){
			pos = (pos + *curm) % i;
			memcpy(flags + pos, flags + pos + 1, sizeof(int)*(i - pos - 1));
		}
		printf("%u\n", flags[0] + 1);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
