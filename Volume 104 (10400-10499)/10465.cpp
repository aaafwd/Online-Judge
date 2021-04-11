/* @JUDGE_ID: 19899RK 10465 C++ "By Anadan" */ 
// Homer Simpson
// Accepted (0.211 seconds using as much as 384 kbytes)

#include <stdio.h>

int main(){
	int m, n, t, i, j, k, max, rest;

	while (scanf("%d%d%d\n", &m, &n, &t) == 3){
		max = 0;
		rest = 20000;
		for (i = 0; m*i <= t; ++i){
			j = (t - m*i) / n;
			k = m*i + n*j;
			if (rest > t - k || (rest == t - k && max < i + j)){
				max = i + j;
				rest = t - k;
			}
		}

		if (rest) printf("%d %d\n", max, rest);
		else printf("%d\n", max);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
