/* @JUDGE_ID: 19899RK 10220 C++ "By Anadan" */
// I Love Big Numbers !
// Accepted (0.070 seconds using as much as 380 kbytes)

#include <stdio.h>

long multiply(char *p, int n){
	int rest = 0, tmp;
	long sum = 0L;

	while (*p){
		rest += n * (*p - '0');
		tmp = rest % 10;
		*p++ = '0' + tmp;
		rest /= 10;
		sum += tmp;
	}
	while (rest){
		tmp = rest % 10;
		*p++ = '0' + tmp;
		rest /= 10;
		sum += tmp;
	}
	*p = 0;

	return sum;
}

int main(){
	int n;
	long solves[1001];
	char factorial[2600];

	solves[0] = solves[1] = 1L;
	factorial[0] = '1'; factorial[1] = 0;
	for (n = 2; n < 1001; n++) solves[n] = multiply(factorial, n);

	while (scanf("%d\n", &n) > 0) printf("%ld\n", solves[n]);
	return 0;
}
/* @END_OF_SOURCE_CODE */
