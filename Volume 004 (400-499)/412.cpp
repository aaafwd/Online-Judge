/* @JUDGE_ID: 19899RK 412 C++ "By Anadan" */
// A Pi
// Accepted (0.664 seconds using as much as 392 kbytes)

#include <stdio.h>
#include <math.h>

int gcd1(int a, int b){
	while (a && b) if (a > b) a %= b; else b %= a;
	if (a == 1 || b == 1) return 1;
	return 0;
}

int main(){
	double a_pi;
	int i, j, N, arr[50], mnoj;

	while(scanf("%d", &N) > 0){
		if (N == 0) break;
		for (mnoj = i = 0; i < N; i++){
			scanf("%d", arr + i);
			for (j = 0; j < i; j++){
				if (gcd1(arr[i], arr[j])) ++mnoj;
			}
		}

		if (mnoj){
			a_pi = sqrt(3.0 * N * (N-1) / double (mnoj));
			printf("%.6lf\n", a_pi);
		}else printf("No estimate for this data set.\n");
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */
