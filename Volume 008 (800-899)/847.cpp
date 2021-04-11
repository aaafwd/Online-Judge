/* @JUDGE_ID: 19899RK 847 C++ "By Anadan" */
// A multiplication game
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>

int main(){
	int win;
	unsigned long N, p;

	while (scanf("%lu", &N) == 1){
		win = 1;
		p = 1L;

		while (1){
			if (p >= (N / 9) + ((N % 9) ? 1 : 0)) break;
			p *= 9;
			if (p >= (N >> 1) + ((N & 1) ? 1 : 0)){
				win = 0;
				break;
			}
			p <<= 1;
		}

		if (win) printf("Stan wins.\n");
		else printf("Ollie wins.\n");
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
