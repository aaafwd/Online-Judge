/* @JUDGE_ID: 19899RK 516 C++ "By Anadan" */
// Prime Land
// Accepted (0.040 seconds with low memory spent)

#include <stdio.h>
#include <math.h>

void func(int N){
	int i, j = 0, pi[6], ei[6], index = 0;

	while (!(N & 1)) { N >>= 1; j++; }
	if (j) { pi[index] = 2; ei[index] = j; index++; }

	for (i = 3; i <= sqrt(N); i += 2){
		j = 0;
		while (!(N % i)) { N /= i; j++; }
		if (j) { pi[index] = i; ei[index] = j; index++; }
	}

	if (N > 1) printf("%d 1", N);
	else { index--; printf("%d %d", pi[index], ei[index]); }
	for (i = index - 1; i >= 0; i--){
		printf(" %d %d", pi[i], ei[i]);
	}
	printf("\n");
}

int main(){
	int N, off, i, j;
	char str[256], *p;

	while (gets(str)){
		N = 1; p = str;
		sscanf(str, "%d", &i);
		if (i == 0) break;
		while (sscanf(p, "%d%d%n", &i, &j, &off) > 1){
			while (j--) N *= i;
			p += off;
		}
		func(N - 1);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
