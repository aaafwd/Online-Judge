/* @JUDGE_ID: 19899RK 834 C++ "By Anadan" */
// Continued Fractions
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>

int main(){
	int n, m, p;

	while (scanf("%d%d", &n, &m) == 2){
		p = n / m;
		printf("[%d", p);
		n -= p * m;
		if (n){
			p = m / n;
			printf(";%d", p);
			m -= p * n;
			while (m){
				p = n / m;
				printf(",%d", p);
				n -= p * m;
				if (n){
					p = m / n;
					printf(",%d", p);
					m -= p * n;
				}else break;
			}
		}

		printf("]\n");
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
