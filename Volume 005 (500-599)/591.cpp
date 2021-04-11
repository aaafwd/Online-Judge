/* @JUDGE_ID: 19899RK 591 C++ "By Anadan" */ 
// Box of Bricks
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>

int main(){
	long set = 0L;
	int i, j, n, len;
	int h[50];
	
	while (scanf("%d", &n) > 0){
		if (n == 0) break;
		for (len = i = 0; i < n; i++){
			scanf("%d", &h[i]);
			len += h[i];
		}
		len /= n;
		for (i = j = 0; i < n; i++){
			if (h[i] < len) j += len - h[i];
		}
		printf("Set #%ld\n", ++set);
		printf("The minimum number of moves is %d.\n\n", j);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
