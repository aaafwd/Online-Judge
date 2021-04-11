/* @JUDGE_ID: 19899RK 10427 C++ "By Anadan" */ 
// Naughty Sleepy Boys
// Accepted (0.021 seconds with low memory spent)

#include <stdio.h>

int main(){
	int N, i, j, k;

	while (scanf("%d\n", &N) == 1){
		for (i = 9, j = 1; N > i * j; i *= 10, ++j) N -= i * j;
		i /= 9;
		k = (N - 1) / j;
		i += k;
		N -= j * k;
		for (k = j - N; k; k--) i /= 10;
		printf("%d\n", i % 10);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
