/* @JUDGE_ID: 19899RK 10547 C++ "By Anadan" */
// Hidden Truth in Recurrence
// Accepted (0.018 seconds with low memory spent)

#include <stdio.h>

typedef unsigned long long qword;

int main(){
	int set = 0, t, m;
	qword k, n, res, rt;

	while (scanf("%llu%llu%d", &k, &n, &t) == 3 && t){
		for (m = 1; t--; m *= 10);

		k %= m;
		res = 1;
		rt = k;
		while (n){
			if (n & 1){
				res = (res * rt) % m;
				--n;
			}else{
				rt = (rt * rt) % m;
				n >>= 1;
			}
		}

		printf("Case #%d: %llu\n", ++set, res);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
