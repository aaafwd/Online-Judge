/* @JUDGE_ID: 19899RK 10333 C++ "By Anadan" */ 
// The Tower of ASCII
// Accepted (0.018 seconds with low memory spent)

#include <stdio.h>

void printch(int c, int n) { while (n--) putchar(c); }

int main(){
	int H, W, i, j, last, dots, left, set = 0;

	while (scanf("%d\n", &H) == 1){
		for (W = 1; W <= H; ++W) H -= W;
		last = H + --W;
		left = (W - 1) << 1;

		printf("Tower #%d\n", ++set);
		for (dots = i = 0; i < W - 1; ++i){
			printch(' ', left);
			printf("#**"); printch('.', dots); printf("**#\n");
			dots += 4;
			for (j = 0; j < i; ++j){
				printch(' ', left);
				putchar('#'); printch('.', dots); printf("#\n");
			}
			left -= 2;
		}

		printf("#**"); printch('.', dots); printf("#\n");
		dots += 2;
		for (j = 1; j < last; ++j){
			putchar('#'); printch('.', dots); printf("#\n");
		}

		putchar('\n');
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
