/* @JUDGE_ID: 19899RK 231 C++ "By Anadan" */
// Testing the CATCHER
// Accepted (0.014 seconds with low memory spent)

#include <stdio.h>
#include <string.h>
#define SZ 32768

int main(){
	int h[SZ], i, x, max, set = 0;

	while (scanf("%d\n", &x) == 1 && x != -1){
		for (i = 0; i < SZ; ++i) h[i] = 0;
		h[x] = 1;

		while (scanf("%d\n", &x) == 1 && x != -1){
			for (max = 0, i = x + 1; i < SZ; ++i){
				if (max < h[i]) max = h[i];
			}

			h[x] = max + 1;
		}

		for (max = 0, i = 0; i < SZ; ++i) if (max < h[i]) max = h[i];

		if (set) putchar('\n');
		printf("Test #%d:\n", ++set);
		printf("  maximum possible interceptions: %d\n", max);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
