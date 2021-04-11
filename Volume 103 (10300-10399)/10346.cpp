/* @JUDGE_ID: 19899RK 10346 C++ "By Anadan" */
// Peter's Smokes
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>

int main(){
	int n, k, res;

	while (scanf("%d%d", &n, &k) == 2){
		res = n;
		while (n >= k){
			res += n / k;
			n = (n / k) + (n % k);
		}
		printf("%d\n", res);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
