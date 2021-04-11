/* @JUDGE_ID: 19899RK 661 C++ "By Anadan" */
// Blowing Fuses
// Accepted (0.010 seconds with low memory spent)

#include <stdio.h>

int main(){
	char flags[20];
	long set = 0L;
	int n, m, c, i, j, ci[20], max, cur;

	while (scanf("%d%d%d", &n, &m, &c) == 3){
		if ((!n) && (!m) && (!c)) break;
		for (i = 0; i < n; i++){
			scanf("%d", ci + i);
			flags[i] = 0;
		}
		for (max = cur = i = 0; i < m; i++){
			scanf("%d", &j); j--;
			if (flags[j]) cur -= ci[j];
			else cur += ci[j];
			if (cur > max) max = cur;
			flags[j] ^= 1;
		}
		printf("Sequence %ld\n", ++set);
		if (max > c) printf("Fuse was blown.\n\n");
		else printf("Fuse was not blown.\nMaximal power consumption was %d amperes.\n\n", max);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
