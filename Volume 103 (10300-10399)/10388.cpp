/* @JUDGE_ID: 19899RK 10388 C++ "By Anadan" */ 
// Snap
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>
#include <stdlib.h>

int main(){
	int set, i, j, k, p[2], sp[2];
	char cards[2][101], stack[2][101];

	scanf("%d\n\n", &set);
	while (set--){
		scanf("%s%s", cards[0], cards[1]);

		sp[0] = sp[1] = p[0] = p[1] = 0;
		for (i = 0; i < 1000; ++i){
			stack[0][sp[0]++] = cards[0][p[0]++];
			stack[1][sp[1]++] = cards[1][p[1]++];
			if (stack[0][sp[0] - 1] == stack[1][sp[1] - 1]){
				k = (rand() / 141) & 1;
				for (j = 0; j < sp[k ^ 1]; ++j){
					stack[k][sp[k]++] = stack[k ^ 1][j];
				}

				if (k) fputs("Snap! for John: ", stdout);
				else fputs("Snap! for Jane: ", stdout);
				for (j = sp[k] - 1; j >= 0; --j) putchar(stack[k][j]);
				putchar('\n');

				sp[k ^ 1] = 0;
			}

			if (cards[0][p[0]] == 0){
				for (j = 0; j < sp[0]; ++j) cards[0][j] = stack[0][j];
				cards[0][j] = 0;
				p[0] = sp[0] = 0;
			}

			if (cards[1][p[1]] == 0){
				for (j = 0; j < sp[1]; ++j) cards[1][j] = stack[1][j];
				cards[1][j] = 0;
				p[1] = sp[1] = 0;
			}

			if (!cards[0][0] || !cards[1][0]) break;
		}

		if (i == 1000) puts("Keeps going and going ...");
		else if (cards[0][0]) puts("Jane wins.");
		else puts("John wins.");

		if (set) putchar('\n');
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
