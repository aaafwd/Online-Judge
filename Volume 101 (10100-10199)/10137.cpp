/* @JUDGE_ID: 19899RK 10137 C++ "By Anadan" */ 
// The Trip
// Accepted (0.016 seconds with low memory spent)

#include <stdio.h>
#include <math.h>

int main(){
	int N, i, j, k, p[1000], sum, a, b;

	while (scanf("%d\n", &N) == 1 && N){
		sum = 0;
		for (i = 0; i < N; ++i){
			scanf("%d.%d", &j, &k);
			p[i] = j * 100 + k;
			sum += p[i];
		}

		if (!(sum % N)) j = k = sum / N;
		else{
			j = sum / N;
			k = j + 1;
		}

		a = b = 0;
		for (i = 0; i < N; ++i){
			if (p[i] < j) a += j - p[i];
			else if (p[i] > k) b += p[i] - k;
		}

		if (a < b) a = b;

		printf("$%.2lf\n", 0.01 * a);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
