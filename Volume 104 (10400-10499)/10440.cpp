/* @JUDGE_ID: 19899RK 10440 C++ "By Anadan" */ 
// Ferry Loading II
// Accepted (0.002 seconds with low memory spent)

#include <stdio.h>

int main(){
	int set, n, m, t, k, i, tmp, leave[1440];

	scanf("%d\n", &set);
	while (set--){
		scanf("%d%d%d\n", &n, &t, &m);
		k = (m + n - 1) / n;
		tmp = m - (k - 1) * n;
		while (--tmp) scanf("%*d");
		scanf("%d", leave);
		for (i = 1; i < k; ++i){
			for (tmp = n; --tmp;) scanf("%*d");
			scanf("%d", leave + i);
		}

		t <<= 1;
		for (i = 1; i < k; ++i) if (leave[i] < leave[i - 1] + t) leave[i] = leave[i - 1] + t;
		printf("%d %d\n", leave[k - 1] + t/2, k);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
