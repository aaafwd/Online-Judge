/* @JUDGE_ID: 19899RK 10532 C++ "By Anadan" */
// Combination! Once Again
// Accepted (0.113 seconds using as much as 388 kbytes)

#include <stdio.h>

typedef unsigned long long qword;

int main(){
	int set = 0, N, M, i, j, k, r, arr[55];
	qword res[55], res1[55];
	
	while (scanf("%d%d", &N, &M) == 2 && N){
		for (i = 0; i < N; ++i) arr[i] =0;
		for (i = 0; i < N; ++i){
			scanf("%d", &j);
			++arr[j-1];
		}
		
		printf("Case %d:\n", ++set);
		while (M--){
			scanf("%d", &r);
			
			for (j = 0; j <= r; ++j) res[j] = res1[j] = (qword)0;
			res[0] = res1[0] = (qword)1;
			
			for (i = 0; i < N; ++i){
				res1[0] = (qword)1;
				for (j = 1; j <= r; ++j){
					res1[j] = (qword)0;
					for (k = 0; k <= j && k <= arr[i]; ++k){
						res1[j] += res[j-k];
					}
				}
				for (j = 1; j <= r; ++j) res[j] = res1[j];
			}
			
			printf("%llu\n", res[r]);
		}
	}
	
	return 0;
}
/* @END_OF_SOURCE_CODE */
