/* @JUDGE_ID: 19899RK 694 C++ "By Anadan" */
// The Collatz Sequence
// Accepted (0.360 seconds using as much as 396 kbytes)

#include <stdio.h>
#include <math.h>

long cyclelen(double A, double L){
	long res = 1L;
	if (A > L) return 0L;

	while (A > 1){
		if (fmod(A, 2.0)){
			if (3.0 * A + 1.0 > L) break;
			A += 0.5 * (A + 1);
			res += 2L;
		}else{
			A *= 0.5;
			if (A > L) break;
			res++;
		}
	}
	return res;
}

int main(){
	double A, L;
	long set = 0L;
	while (scanf("%lf%lf", &A, &L) > 0){
		if ((A < 0L) && (L < 0L)) break;
		printf("Case %ld: A = %.0lf, limit = %.0lf, ", ++set, A, L);
		printf("number of terms = %ld\n", cyclelen(A, L));
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */
