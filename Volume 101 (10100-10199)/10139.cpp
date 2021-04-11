/* @JUDGE_ID: 19899RK 10139 C++ "By Anadan" */
// Factovisors
// Accepted (0.010 seconds with low memory spent)

#include <stdio.h>
#include <math.h>

int divides(long n, long m){
	int powers[12], index = 0;
	long divisors[12], i;

	if (m == 0L) return 0;
	if (m == 1L) return 1;
	if (n <= 1L) return 0;
	for (i = 2L; i <= sqrt(m); i++){
		if (!(m % i)){
			powers[index] = 0;
			divisors[index] = i;
			do { powers[index]++; m /= i; } while (!(m % i));
			++index;
		}
	}
	if (m > 1L){
		divisors[index] = m; powers[index++] = 1;
	}

	for (--index; index >= 0; index--){
		i = n;
		while (i){
			i /= divisors[index];
			powers[index] -= i;
			if (powers[index] <= 0) break;
		}
		if (powers[index] > 0) return 0;
	}
	return 1;
}

int main(){
	long n, m;

	while (scanf("%ld%ld", &n, &m) == 2){
		if (divides(n, m)) printf("%ld divides %ld!\n", m, n);
		else printf("%ld does not divide %ld!\n", m, n);
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */
