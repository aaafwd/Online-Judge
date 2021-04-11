/* @JUDGE_ID: 19899RK 10475 C++ "By Anadan" */ 
// Help the Leaders
// Accepted (0.100 seconds with low memory spent)

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int T, S, curr[5];
char theme[16][20], map[16][16];

int sort_function(const void *a, const void *b){
	int la = strlen((char *)a), lb = strlen((char *)b);
	if (la > lb) return -1;
	if (la < lb) return 1;
	return strcmp((char *)a, (char *)b);
}

void strtoupper(char *s){
	while (*s) *s++ = toupper(*s);
}

int getindex(char *s){
	int i;
	for (i = 0; strcmp(theme[i], s); ++i);
	return i;
}

void generate(int i, int t){
	int j;

	if (t == S){
		printf("%s", theme[curr[0]]);
		for (j = 1; j < S; ++j) printf(" %s", theme[curr[j]]);
		putchar('\n');
		return;
	}

	for (; i < T; ++i){
		for (j = 0; j < t; ++j){
			if (map[curr[j]][i]) break;
		}
		if (j < t) continue;

		curr[t] = i;
		generate(i + 1, t + 1);
	}
}

int main(){
	int set, i, j, P, count = 0;
	char s1[20], s2[20];

	scanf("%d\n", &set);
	while (set--){
		scanf("%d%d%d\n", &T, &P, &S);
		for (i = 0; i < T; ++i){
			scanf("%s\n", theme[i]);
			strtoupper(theme[i]);
		}
		qsort(theme, T, sizeof(theme[0]), sort_function);
		memset(map, 0, sizeof(map));

		while (P--){
			scanf("%s%s\n", s1, s2);
			strtoupper(s1);
			strtoupper(s2);
			i = getindex(s1);
			j = getindex(s2);
			map[i][j] = map[j][i] = 1;
		}

		printf("Set %d:\n", ++count);
		generate(0, 0);
		putchar('\n');
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
