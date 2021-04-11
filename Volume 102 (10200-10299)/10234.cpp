/* @JUDGE_ID: 19899RK 10234 C++ "By Anadan" */ 
// Frequent Substrings
// Accepted (6.480 seconds using as much as 392 kbytes)
// Too much time !

#include <ctype.h>
#include <stdio.h>
#include <string.h>

int strequal(char *a, char *b, char *c, char *d){
	while (a <= b) if (*a++ != *c++ || *b-- != *d--) return 0;
	return 1;
}

int getoccurrences(char *s, int len, int p){
	int res = 1;
	char *q, *t = s + p - 1;

	for (q = s + 1; q <= s + len - p; ++q){
		if (strequal(s, t, q, q + p - 1)) ++res;
	}

	return res;
}

int main(){
	int i, j, k, period, N, len, max;
	char str[1100], best[1100], *p;

	while (gets(str)){
		for (p = str; *p; ++p) *p = tolower(*p);
		len = int(p - str);

		if (scanf("%d", &N) < 1) break;
		while ((i = getchar()) != '\n' && i != EOF);
		while (N--){
			scanf("%d", &period); while ((i = getchar()) != '\n' && i != EOF);
			max = 0;
			for (i = 0; i <= len - period; ++i){
				if (max > len - period - i + 1) break;
				
				k = strncmp(best, str + i, period);
				if (max && k == 0) continue;
				if (max == len - period - i + 1 && k < 0) continue;

				j = getoccurrences(str + i, len - i, period);
				if (j > max || (j == max && k > 0)){
					max = j;
					strncpy(best, str + i, period);
				}
			}

			best[period] = 0;
			printf("%d %s\n", max, best);
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
