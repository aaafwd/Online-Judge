/* @JUDGE_ID: 19899RK 431 C++ "By Anadan" */ 
// Trial of the Millennium
// Accepted (0.350 seconds using as much as 492 kbytes)

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Evidence{
	int score, t;
	char str[81];
}pt[100];

int main(){
	int set, i, j, T, E, score, t, maxscore[101][241];

	memset(maxscore[0], 0, sizeof(maxscore[0]));
	scanf("%d\n\n", &set);
	while (set--){
		E = 0;
		scanf("%d", &T);
		while (getchar() != '\n');

		while (1){
			while ((i = getchar()) == ' ');
			if (i == '\n' || i == EOF) break;
			ungetc(i, stdin);
			scanf("%d%d", &score, &t);
			pt[E].score = score; pt[E].t = t;
			while ((i = getchar()) == ' ');
			pt[E].str[0] = i;
			gets(pt[E++].str + 1);
			memcpy(maxscore[E], maxscore[E - 1], sizeof(maxscore[0]));

			for (i = 0; i <= T - t; ++i) if (maxscore[E][i + t] < maxscore[E - 1][i] + score){
				maxscore[E][i + t] = maxscore[E - 1][i] + score;
			}
		}

		for (j = i = 0; i <= T; ++i) if (maxscore[E][j] < maxscore[E][i]) j = i;
		if (maxscore[E][j] == 0) printf("There is not enough time to present any evidence. Drop the charges.\n");
		else{
			printf("Score  Time  Description\n");
			printf("-----  ----  -----------\n");

			t = j;
			score = maxscore[E][j];
			for (i = E - 1; i >= 0; --i){
				if (maxscore[i][j] != maxscore[i + 1][j]){
					printf("%3d%7d   %s\n", pt[i].score, pt[i].t, pt[i].str);
					j -= pt[i].t;
				}
			}

			printf("\nTotal score: %d points\n", score);
			printf(" Total time: %d hours\n", t);
		}

		if (set) putchar('\n');
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
