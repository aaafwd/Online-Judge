/* @JUDGE_ID: 19899RK 441 C++ "By Anadan" */ 
// Lotto
// Accepted (0.010 seconds with low memory spent)

#include <stdio.h>

int S[15], k, outp[6];

void func(int n, int i){
	for (; i < k - 5 + n; i++){
		outp[n] = S[i];
		if (n == 5){
		   	printf("%d %d %d ", outp[0], outp[1], outp[2]);
		   	printf("%d %d %d\n", outp[3], outp[4], outp[5]);
		}else func(n + 1, i + 1);
	}
}

int main(){
	int i = 0;
	while (scanf("%d", &k) > 0){
		if (k == 0) break;
		if (i) printf("\n");
		for (i = 0; i < k; i++) scanf("%d", &S[i]);
		func(0, 0);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
