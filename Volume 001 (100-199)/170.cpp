/* @JUDGE_ID: 19899RK 170 C++ "By Anadan" */ 
// Clock Patience
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

char cardnames[] = "KQJT98765432A";
inline int getindex(char *p) { return int(strchr(cardnames, *p) - cardnames); }

int main(){
	char piles[13][4][3], np[13], last[3], i, j, cur;

	while (scanf("%s", piles[0][3]) == 1 && piles[0][3][0] != '#'){
		np[0] = 4;
		for (i = 1; i < 13; ++i){
			scanf("%s", piles[i][3]);
			np[i] = 4;
		}

		for (j = 2; j >= 0; --j) for (i = 0; i < 13; ++i){
			scanf("%s", piles[i][j]);
		}

		j = cur = 0;
		while (1){
			++j;
			i = getindex(piles[cur][--np[cur]]);
			strcpy(last, piles[cur][np[cur]]);
			if (np[i] == 0) break;
			cur = i;
		}

		printf("%.2d,%s\n", j, last);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
