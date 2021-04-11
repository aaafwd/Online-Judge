/* @JUDGE_ID: 19899RK 531 C++ "By Anadan" */
// Compromise
// Accepted (0.096 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

int main(){
	int n1, n2, map[101][101], i, j, k, stack[101], sp;
	char words1[101][31], words2[101][31];

	while (1){
		n1 = n2 = 0;
		while (1){
			if (scanf("%s", words1[n1]) < 1) return 0;
			if (words1[n1][0] == '#') break;
			++n1;
		}
		while (1){
			if (scanf("%s", words2[n2]) < 1) return 0;
			if (words2[n2][0] == '#') break;
			++n2;
		}

		for (i = 0; i <= n2; ++i) map[0][i] = 0;
		for (i = 1; i <= n1; ++i){
			map[i][0] = 0;
			for (j = 1; j <= n2; ++j){
				if (strcmp(words1[i - 1], words2[j - 1])){
					map[i][j] = map[i - 1][j];
					if (map[i][j] < map[i][j - 1]) map[i][j] = map[i][j - 1];
				}else{
					map[i][j] = map[i - 1][j - 1] + 1;
				}
			}
		}

		k = n2; sp = 0; i = n1;
		while (i > 0 && k > 0){
			if (map[i][k] == map[i][k - 1]) --k;
			else if (map[i][k] == map[i - 1][k]) --i;
			else{
				stack[sp++] = --i;
				--k;
			}
		}

		if (sp) printf("%s", words1[stack[--sp]]);
		while (sp--) printf(" %s", words1[stack[sp]]);
		putchar('\n');
	}
}
/* @END_OF_SOURCE_CODE */
