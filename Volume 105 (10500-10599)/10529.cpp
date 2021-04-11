/* @JUDGE_ID: 19899RK 10529 C++ "By Anadan" */
// Dumb Bones
// Accepted (2.693 seconds using as much as 396 kbytes)

#include <stdio.h>

int main(){
	int N, i, j;
	double pl, pr, res[1001], tmp;

	res[0] = 0;
	while (scanf("%d", &N) == 1 && N){
		scanf("%lf%lf", &pl, &pr);
		for (i = 1; i <= N; ++i){
			for (j = 0; j < i; ++j){
				tmp = res[j] + res[i - 1 - j] + (1 + pl * res[j] + pr * res[i - 1 - j]) / (1 - pl - pr);
				if (j == 0) res[i] = tmp;
				else if (res[i] > tmp) res[i] = tmp;
			}
		}

		printf("%.2lf\n", res[N]);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
