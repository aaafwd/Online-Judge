/* @JUDGE_ID: 19899RK 557 C++ "By Anadan" */
// Burger
// Accepted (0.040 seconds using as much as 780 kbytes)

#include <stdio.h>
#define MAX 100000

int main(){
	long set, i, n;
	double p, solves[MAX];

	solves[0] = 0.0; p = 1.0;
	for (i = 1L, n = 2L; i < MAX; i++, n += 2L){
		p *= 0.25 * double(n) * double(n - 1) / (double(i) * double(i));
		solves[i] = 1.0 - p;
	}

	scanf("%ld", &set);
	while (set--){
		scanf("%ld", &n);
		printf("%.4lf\n", solves[(n >> 1) - 1]);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
