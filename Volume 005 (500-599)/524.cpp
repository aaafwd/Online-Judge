/* @JUDGE_ID: 19899RK 524 C++ "By Anadan" */
// Prime Ring Problem
// Accepted (4.270 seconds using as much as 400 kbytes)

#include <stdio.h>
#include <math.h>

int A[16], N;

int prime(int i){
	int j, toj = sqrt(i);
	if (i == 2) return 1;
	if (!(i & 1)) return 0;

	for (j = 3; j <= toj; j += 2){
		if (!(i % j)) return 0;
	}
	return 1;
}

int isOk(int i){
	for (int j = 0; j < i; j++) if (A[j] == A[i]) return 0;
	if (i == 0) return prime(A[0] + 1);

	if (i == N - 1){
		if (!prime(A[i] + A[i - 1])) return 0;
		if (!prime(A[i] + 1)) return 0;
		return 1;
	}

	return prime(A[i] + A[i - 1]);
}

void func(int i){
	for (A[i] = 2; A[i] <= N + 1; A[i]++){
		if (!isOk(i)) continue;
		if (i == N - 1){
			printf("1");
			for (int j = 0; j < N; j++) printf(" %d", A[j]);
			printf("\n");
			break;
		}
		func(i + 1);
	}
}

int main(){
	int i = 0;
	while(scanf("%d", &N) > 0){
		if (i) printf("\n");
		printf("Case %d:\n", ++i);
		if (!(--N)) printf("1\n"); else func(0);
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */
