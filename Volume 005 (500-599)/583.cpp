/* @JUDGE_ID: 19899RK 583 C++ "By Anadan" */
// Prime Factors
// Accepted (2.432 seconds using as much as 392 kbytes)

#include <stdio.h>
#include <math.h>

void func(int N){
	char flag = 0;
	int i, toi;

	printf("%d = ", N);
	if (N < 0){
		N = -N;
		printf("-1"); flag = 1;
	}

	toi = (int)sqrt(N);
	for (i = 2; i <= toi; i++){
		if (!(N % i)){
			while (!(N % i)){
				if (flag) printf(" x "); else flag = 1;
				printf("%d", i);
				N /= i;
			}

			toi = (int)sqrt(N);
		}
	}

	if (N > 1){
		if (flag) printf(" x ");
		printf("%d", N);
	}
	putchar('\n');
}

int main(){
	int N;
	while (scanf("%d", &N) > 0){
		if (N == 0) break;
		func(N);
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */
