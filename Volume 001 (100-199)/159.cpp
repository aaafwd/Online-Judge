/* @JUDGE_ID: 19899RK 159 C++ "By Anadan" */
// Word Crosses
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

char words[4][11];

void printsp(int sp) { while (sp--) putchar(' '); }

int getindexes(int &i, int &j, int w){
	for (i = 0; words[w][i]; ++i){
		for (j = 0; words[w + 1][j]; ++j)
			if (words[w][i] == words[w + 1][j]) break;
		if (words[w + 1][j]) break;
	}

	return words[w][i];
}

int main(){
	char flag = 0;
	int i, j, k, l, m, n, min, max, sp;

	while (scanf("%s %s %s %s\n", words[0], words[1], words[2], words[3]) == 4 && words[0][0] != '#'){
		if (flag) putchar('\n'); else flag = 1;

		if (getindexes(i, j, 0) == 0 || getindexes(k, l, 2) == 0)
			printf("Unable to make two crosses\n");
		else{
			if (j > l) max = j, min = l;
			else max = l, min = j;
			if (j > l) sp = i, m = 1;
			else sp = strlen(words[0]) + 3 + k, m = 3;

			n = 0;
			while (max > min){
				printsp(sp);
				printf("%c\n", words[m][n++]);
				--max;
			}

			if (m == 1) m = 0; else m = n, n = 0;
			sp = strlen(words[0]) + 2 + k - i;
			while (min > 0){
				printsp(i);
				putchar(words[1][n++]);
				printsp(sp);
				printf("%c\n", words[3][m++]);
				--min;
			}

			printf("%s   %s\n", words[0], words[2]);
			++n; ++m;
			while (words[1][n]){
				printsp(i);
				putchar(words[1][n++]);
				if (words[3][m]){
					printsp(sp);
					printf("%c\n", words[3][m++]);
				}else putchar('\n');
			}

			sp += i + 1;
			while (words[3][m]){
				printsp(sp);
				printf("%c\n", words[3][m++]);
			}
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
