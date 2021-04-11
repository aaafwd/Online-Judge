/* @JUDGE_ID: 19899RK 616 C++ "By Anadan" */
// Coconuts, Revisited
// Accepted (0.068 seconds with low memory spent)

#include <stdio.h>
#include <math.h>
#define MAXS 6

int main(){
	int i, N, max;
	int init[MAXS] = { 10, 24, 764, 3120, 233274, 823536 };
	int delta[MAXS] = { 8, 81, 1024, 15625, 279936, 5764801 };

	while (scanf("%d", &N) > 0){
		if (N < 0) break;
		if (N == 3){
			printf("3 coconuts, 2 people and 1 monkey\n");
			continue;
		}

		printf("%d coconuts, ", N--);

		for (max = 0, i = MAXS - 1; i >= 0; i--){
			if (N >= init[i] && !((N - init[i]) % delta[i])){
				max = i + 2;
				break;
			}
		}

		if (max) printf("%d people and 1 monkey\n", max);
		else printf("no solution\n");
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */
