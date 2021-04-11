/* @JUDGE_ID: 19899RK 10056 C++ "By Anadan" */
// What is the Probability?
// Accepted (0.020 seconds with low memory spent)

#include <stdio.h>

int main(){
	int set, N, I;
	double p, q, tmp, res;
	scanf("%d", &set);

	while (set--){
		scanf("%d %lf %d", &N, &p, &I);
		if (p == 0.0){
			printf("0.0000\n");
			continue;
		}
		q = 1.0 - p;
		tmp = 1.0;
		while (--I){
			tmp *= q;
			--N;
		}
		res = tmp * p;
		while (N--) tmp *= q;
		res /= (1.0 - tmp);
		printf("%.4lf\n", res);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
