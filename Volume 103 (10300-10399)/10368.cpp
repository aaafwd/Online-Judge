/* @JUDGE_ID: 19899RK 10368 C++ "By Anadan" */
// Euclid's Game
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>

int main(){
	int i;
	long n, m;

	while (scanf("%ld%ld", &n, &m) == 2){
		if (n == 0 && m == 0) break;
		if (n < m) n ^= m ^= n ^= m;

		for (i = 0 ;; i ^= 1){
			if (n % m){
				if (n - m > m) break;
				n -= m;
				n ^= m ^= n ^= m;
			}else break;
		}

		if (i) printf("Ollie wins\n"); else printf("Stan wins\n");
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
