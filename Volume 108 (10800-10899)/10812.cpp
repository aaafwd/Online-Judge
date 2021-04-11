/* @JUDGE_ID: 19899RK 10812 C++ "By Anadan" */
// Beat the Spread!
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>

int main(){
	int set, s, d;

	scanf("%d", &set);
	while (set--) {
		scanf("%d%d", &s, &d);
		if (((s+d)&1) || s < d) puts("impossible");
		else printf("%d %d\n", (s+d)>>1, (s-d)>>1);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
