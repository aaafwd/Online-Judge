/* @JUDGE_ID: 19899RK 10025 C++ "By Anadan" */ 
// The ? 1 ? 2 ? ... ? n = k problem
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>
#include <math.h>

int main(){
	int set, n, k, s;

	scanf("%d\n\n", &set);
	while (set--){
		scanf("%d\n", &k);
		if (k < 0) k = -k;
		if (k){
			n = (int)ceil(sqrt(k + k + 0.25) - 0.5);
			s = ((n + 1) >> 1) & 1;
			while ((k - s) & 1) s += ++n;
			printf("%d\n", n);
		}else printf("3\n");

		if (set) putchar('\n');
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
