/* @JUDGE_ID: 19899RK 10365 C++ "By Anadan" */
// Blocks
// Accepted (0.010 seconds with low memory spent)

#include <stdio.h>
#include <math.h>

int main(){
	int set, N, a, b, c, tmp, min;

	scanf("%d", &set);
	while (set--){
		scanf("%d", &N);
		min = -1;
		for (a = N; a > 0; --a){
			if (N % a) continue;
			tmp = N / a;
			for (b = tmp; b > 0; --b){
				if (tmp % b) continue;
				c = tmp / b;
				if (min == -1 || min > 2*(a*b + b*c + a*c))
					min = 2*(a*b + b*c + a*c);
			}
		}

		printf("%d\n", min);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
