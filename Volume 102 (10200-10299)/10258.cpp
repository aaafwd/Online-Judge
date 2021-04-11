/* @JUDGE_ID: 19899RK 10258 C++ "By Anadan" */ 
// Contest Scoreboard
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct People{
	int c, p, t;
}pt[100];

int sort_function(const void *a, const void *b){
	People *pa = (People *)a, *pb = (People *)b;
	if (pa->p > pb->p) return -1;
	if (pa->p < pb->p) return 1;
	if (pa->t > pb->t) return -1;
	if (pa->t < pb->t) return 1;
	if (pa->c < pb->c) return -1;
	return 1;
}

int main(){
	int set, penalty[101][10], c, p, t, i, j;
	char str[80], mask[101], solved[101][10], ch;

	scanf("%d\n\n", &set);
	while (set--){
		memset(mask, 0, sizeof(mask));
		memset(solved, 0, sizeof(solved));
		memset(penalty, 0, sizeof(penalty));
		while (gets(str) && str[0]){
			sscanf(str, "%d %d %d %c", &c, &p, &t, &ch);
			mask[c] = 1;
			if (ch == 'C'){
				if (!solved[c][p]){
					solved[c][p] = 1;
					penalty[c][p] += t;
				}
			}else if (ch == 'I'){
				if (!solved[c][p]){
					penalty[c][p] += 20;
				}
			}
		}

		c = 0;
		for (i = 1; i <= 100; ++i){
			if (mask[i] == 0) continue;
			pt[c].c = i;
			p = t = 0;
			for (j = 1; j <= 9; ++j){
				if (solved[i][j]){
					++p;
					t += penalty[i][j];
				}
			}

			pt[c].p = p;
			pt[c++].t = t;
		}

		qsort(pt, c, sizeof(People), sort_function);
		for (i = 0; i < c; ++i){
			printf("%d %d %d\n", pt[i].c, pt[i].p, pt[i].t);
		}

		if (set) putchar('\n');
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
