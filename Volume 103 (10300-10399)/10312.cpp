/* @JUDGE_ID: 19899RK 10312 C++ "By Anadan" */ 
// Expression Bracketing
// Accepted (0.002 seconds with low memory spent)

#include <stdio.h>

typedef long long qword;

int main(){
	int i, j;
	qword b[27], c[27];

	// b-array - not binary expressions
	// c-array - only binary expressions (Catalan numbers)
	b[1] = b[2] = 0;
	c[2] = 1;
	for (i = 3; i < 27; ++i){
		c[i] = c[i - 1] * (i * 4 - 6) / i;
		b[i] = b[i - 1] * 3 + c[i - 1];
		for (j = i - 2; j > 1; --j){
			b[i] += (b[i - j] + c[i - j]) * (b[j] * 2 + c[j]) + c[j] * b[i - j];
		}
	}

	while (scanf("%d\n", &i) == 1) printf("%lld\n", b[i]);

	return 0;
}
/* @END_OF_SOURCE_CODE */
