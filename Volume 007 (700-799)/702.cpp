/* @JUDGE_ID: 19899RK 702 C++ "By Anadan" */ 
// The Vindictive Coach
// Accepted (0.002 seconds with low memory spent)

#include <stdio.h>

typedef long long qword;

int main(){
	int N, m, i, j, x;
	qword arr[23][23];

	arr[1][1] = arr[2][2] = 1;
	arr[2][1] = 0;

	for (N = 3; N <= 22; ++N){
		for (x = 1; x <= N; ++x){
			arr[N][x] = 0;
			for (i = 1; i <= x - 1; ++i){
				for (j = i; j <= N - 2; ++j){
					arr[N][x] += arr[N - 2][j];
				}
			}
		}
	}

	while (scanf("%d%d\n", &N, &m) == 2){
		if (N < 3) puts("1");
		else if (m == 1) printf("%lld\n", arr[N - 1][2]);
		else printf("%lld\n", arr[N][m]);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
