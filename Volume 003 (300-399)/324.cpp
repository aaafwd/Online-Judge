/* @JUDGE_ID: 19899RK 324 C++ "By Anadan" */
// Factorial Frequencies
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>
#include <string.h>
#define MAXDIGITS 782

void multiply(char *s, int N){
	int rest = 0;

	while(*s){
		rest += N * (*s - '0');
		*s++ = '0' + (rest % 10);
		rest /= 10;
	}

	while (rest){
		*s++ = '0' + (rest % 10);
		rest /= 10;
	}
}

int main(){
	char str[MAXDIGITS], *p;
	int solves[367][10], i, j, N;

	memset(str, 0, MAXDIGITS); str[0] = '1';
	for (i = 0; i < 10; i++) solves[1][i] = 0; solves[1][1] = 1;
	for (N = 2; N < 367; N++){
		multiply(str, N);
		for (i = 0; i < 10; i++) solves[N][i] = 0;
		for (p = str; *p; p++) solves[N][*p - '0']++;
	}


	while (scanf("%d", &N) > 0){
		if (N == 0) break;
		printf("%d! --\n", N);
		for (i = 0; i < 5; i++){
			if (i) printf("    "); else printf("   ");
			printf("(%d)%5d", i, solves[N][i]);
		}
		printf("\n");
		for (i = 5; i < 10; i++){
			if (i > 5) printf("    "); else printf("   ");
			printf("(%d)%5d", i, solves[N][i]);
		}
		printf("\n");
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
