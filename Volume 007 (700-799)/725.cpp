/* @JUDGE_ID: 19899RK 725 C++ "By Anadan" */
// Division
// Accepted (0.190 seconds using as much as 388 kbytes)

#include <stdio.h>

int repeated(long a, long b){
	int i, j = 0, k = 5;
	char nums[10];

	while(k--){
		nums[j] = a % 10;
		for (i = 0; i < j; i++) if (nums[i] == nums[j]) return 1;
		a /= 10;
		j++;

		nums[j] = b % 10;
		for (i = 0; i < j; i++) if (nums[i] == nums[j]) return 1;
		b /= 10;
		j++;
	}
	return 0;
}

int main(){
	char solved;
	long N, num = 0L, denom;

	while (scanf("%ld", &N) > 0){
		if (N == 0L) break;
		if (num) printf("\n");
		num = 1234L * N;
		solved = 0;
		for (denom = 1234L; denom <= 98765L; denom++, num += N){
			if (num > 98765L) break;
			if (repeated(num, denom)) continue;
			if (num % denom) continue;
			if (num / denom != N) continue;
			printf("%.5ld / %.5ld = %ld\n", num, denom, N);
			solved = 1;
		}
		if (!solved) printf("There are no solutions for %ld.\n", N);
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */
