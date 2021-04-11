/* @JUDGE_ID: 19899RK 10100 C++ "By Anadan" */ 
// Longest Match
// Accepted (0.008 seconds with low memory spent)

#include <stdio.h>
#include <ctype.h>
#include <string.h>

void nopunct(char *s){
	while (*s){
		if (!isalnum(*s)) *s = ' ';
		++s;
	}
}

int main(){
	int set = 0, i, off, N, match[501];
	char str1[1001], str2[1001], *p;
	static char words[501][21];

	while (gets(str1) && gets(str2)){
		if (!str1[0] || !str2[0]){
			printf("%2d. Blank!\n", ++set);
			continue;
		}

		nopunct(str1);
		nopunct(str2);

		for (N = 0, p = str1; sscanf(p, "%s%n", words[N], &off) == 1; ++N) p += off;
		for (i = 0; i <= N; ++i) match[i] = 0;

		for (p = str2; sscanf(p, "%s%n", str1, &off) == 1; p += off){
			for (i = 0; i < N; ++i){
				if (!strcmp(words[i], str1)){
					match[i + 1] = match[i] + 1;
				}else if (match[i + 1] < match[i]) match[i + 1] = match[i];
			}
		}

		printf("%2d. Length of longest match: %d\n", ++set, match[N]);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
