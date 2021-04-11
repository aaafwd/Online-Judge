/* @JUDGE_ID: 19899RK 10450 C++ "By Anadan" */ 
// World Cup Noise
// Accepted (0.002 seconds with low memory spent)

#include <stdio.h>

int main(){
	int set = 0, N, i;
	long long a[51], b[51];

	a[1] = b[1] = 1;
	for (i = 2; i < 51; ++i){
		a[i] = b[i - 1];
		b[i] = a[i - 1] + b[i - 1];
	}

	scanf("%d", &N);
	while(N--){
		scanf("%d\n", &i);
		printf("Scenario #%d:\n%lld\n\n", ++set, a[i] + b[i]);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
