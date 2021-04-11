/* @JUDGE_ID: 19899RK 604 C++ "By Anadan" */
// The Boggle Game
// Accepted (0.180 seconds using as much as 440 kbytes)

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char map1[6][6], map2[6][6], words[6700][5], cur[5];
int index, vowels;

int sort_function(const void *a, const void *b){
	return strcmp((char *)a, (char *)b);
}

void generate_words(int i, int j, int n){
	char c = map1[i][j], flag = 0;

	cur[n] = c;
	if (n == 3){
		if (strchr("AOEIUY", c)){
			if (vowels == 1) strcpy(words[index++], cur);
		}else if (vowels == 2) strcpy(words[index++], cur);
		return;
	}

	if (strchr("AOEIUY", c)){
		if (vowels >= 2) return;
		++vowels;
		flag = 1;
	}

	map1[i][j] = 0;

	if (map1[i - 1][j])     generate_words(i - 1, j, n + 1);
	if (map1[i - 1][j - 1]) generate_words(i - 1, j - 1, n + 1);
	if (map1[i - 1][j + 1]) generate_words(i - 1, j + 1, n + 1);
	if (map1[i + 1][j])     generate_words(i + 1, j, n + 1);
	if (map1[i + 1][j - 1]) generate_words(i + 1, j - 1, n + 1);
	if (map1[i + 1][j + 1]) generate_words(i + 1, j + 1, n + 1);
	if (map1[i][j - 1])     generate_words(i, j - 1, n + 1);
	if (map1[i][j + 1])     generate_words(i, j + 1, n + 1);

	if (flag) --vowels;
	map1[i][j] = c;
}

int getword(int i, int j, char *s){
	char c;
	if (*s == 0) return 1;
	c = map2[i][j];
	map2[i][j] = 0;

	if (map2[i - 1][j] == *s     && getword(i - 1, j, s + 1))     return (map2[i][j] = c, 1);
	if (map2[i - 1][j - 1] == *s && getword(i - 1, j - 1, s + 1)) return (map2[i][j] = c, 1);
	if (map2[i - 1][j + 1] == *s && getword(i - 1, j + 1, s + 1)) return (map2[i][j] = c, 1);
	if (map2[i + 1][j] == *s     && getword(i + 1, j, s + 1))     return (map2[i][j] = c, 1);
	if (map2[i + 1][j - 1] == *s && getword(i + 1, j - 1, s + 1)) return (map2[i][j] = c, 1);
	if (map2[i + 1][j + 1] == *s && getword(i + 1, j + 1, s + 1)) return (map2[i][j] = c, 1);
	if (map2[i][j - 1] == *s     && getword(i, j - 1, s + 1))     return (map2[i][j] = c, 1);
	if (map2[i][j + 1] == *s     && getword(i, j + 1, s + 1))     return (map2[i][j] = c, 1);

	map2[i][j] = c;
	return 0;
}

int exists(char *s){
	int i, j;

	for (i = 1; i < 5; ++i) for (j = 1; j < 5; ++j)
		if (map2[i][j] == *s && getword(i, j, s + 1)) return 1;

	return 0;
}

int main(){
	int i, j;
	char solved = -1;

	cur[4] = 0;
	for (i = 0; i < 6; ++i) map1[0][i] = map1[i][0] = map1[5][i] =
				map2[0][i] = map2[i][0] = map2[5][i] = 0;

	while (1){
		for (i = 1; i < 5; ++i){
			for (j = 1; j < 5; ++j)
				if (scanf("%1s", &map1[i][j]) < 1) return 0;
			for (j = 1; j < 5; ++j)
				if (scanf("%1s", &map2[i][j]) < 1) return 0;
		}

		if (map1[1][1] == '#') return 0;
		index = vowels = 0;
		for (i = 1; i < 5; ++i) for (j = 1; j < 5; ++j)
			generate_words(i, j, 0);

		if (solved != -1) printf("\n");
		solved = 0;
		if (index){
			qsort((void *)words, index, sizeof(words[0]), sort_function);
			if (exists(words[0])){
				printf("%s\n", words[0]);
				solved = 1;
			}
			for (i = 1; i < index; ++i){
				if (!strcmp(words[i - 1], words[i])) continue;
				if (exists(words[i])){
					printf("%s\n", words[i]);
					solved = 1;
				}
			}
		}

		if (!solved) printf("There are no common words for this pair of boggle boards.\n");
	}
}
/* @END_OF_SOURCE_CODE */
