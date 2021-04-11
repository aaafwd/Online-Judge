/* @JUDGE_ID: 19899RK 10706 C++ "By Anadan" */
// Number Sequence
// Accepted (0.045 seconds with low memory spent)

#include <stdio.h>

int getlen(int x){
	int res = 0;
	while (x) { x /= 10; ++res; }
	return res;
}

int main(){
	int set, N, k, len;

	scanf("%d", &set);
	while (set--){
		scanf("%d", &N);
		k = 1; len = 1;
		while (N > len){
			N -= len;
			len += getlen(++k);
		}
		k = 1; len = 1;
		while (N > len){
			N -= len;
			len = getlen(++k);
		}
		len -= N;
		while (len--) k /= 10;
		printf("%d\n", k % 10);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
