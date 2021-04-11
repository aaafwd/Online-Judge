/* @JUDGE_ID: 19899RK 10146 C++ "By Anadan" */ 
// Dictionary
// Accepted (0.539 seconds using as much as 384 kbytes)

#include <stdio.h>

void printsp(int n) { while (n--) putchar(' '); }

int main(){
	int set, c, i, j;
	char words[2][11];

	scanf("%d\n\n", &set);
	while (set--){
		i = 0;
		c = 1;
		printf("%s\n", gets(words[0]));
		while (gets(words[c]) && words[c][0]){
			for (j = i + 1, i = 0; i < j && words[c][i] && words[c][i] == words[c ^ 1][i]; ++i);
			printsp(i);
			printf("%s\n", words[c]);
			c ^= 1;
		}

		if (set) putchar('\n');
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
