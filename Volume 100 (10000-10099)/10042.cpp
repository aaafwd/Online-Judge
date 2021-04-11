/* @JUDGE_ID: 19899RK 10042 C++ "By Anadan" */
// Smith Numbers
// Accepted (0.627 seconds using as much as 392 kbytes)

#include <stdio.h>
#include <math.h>

int getsum(long a){
	int sum = 0;
	while(a){
		sum += a % 10;
		a /= 10;
	}
	return sum;
}

int smith(long a){
	long i;
	int sum = getsum(a), tmp,  sum0 = sum;

	if (a == 2) return 0;
	while (!(a & 1)){
		a >>= 1;
		sum -= 2;
	}
	if (sum < 0) return 0;

	for (i = 3L; i <= sqrt(a); i += 2L){
		if (!(a % i)){
			tmp = getsum(i);
			while(!(a % i)){
				a /= i;
				sum -= tmp;
			}
			if (sum < 0) return 0;
		}
	}
	if (sum0 == sum) return 0;
	if (a > 1) sum -= getsum(a);
	if (sum == 0) return 1;
	return 0;
}

int main(){
	long N, i;
	scanf("%ld", &N);

	while (N--){
		scanf("%ld", &i);
		while(1){
			i++;
			if (smith(i)) break;
		}
		printf("%ld\n", i);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
