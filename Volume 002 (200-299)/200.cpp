/* @JUDGE_ID: 19899RK 200 C++ "By Anadan" */
// Rare Order
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

int N;
char letters[26], map[26][26];

int getindex(char c){
	int i;
	for (i = 0; i < N; ++i) if (letters[i] == c) return i;
	letters[N] = c;
	return N++;
}

int main(){
	int i, j, rest;
	char words[2][21], *p, *q;

	for (i = 0; i < N; ++i) memset(map[i], 0, 26);
	scanf("%s\n", words[0]);
	N = 0; i = 1;
	while (scanf("%s\n", words[i]) == 1 && words[i][0] != '#'){
		p = words[i ^ 1]; q = words[i];
		while (*p && *p == *q) ++p, ++q;
		if (*p) map[getindex(*q)][getindex(*p)] = 1;
		i ^= 1;
	}

	rest = N;
	while (rest){
		for (i = 0; i < N; ++i){
			if (!memchr(map[i], 1, N)){
				for (j = 0; j < N; ++j) map[j][i] = 0;
				map[i][i] = 1;
				putchar(letters[i]);
				--rest;
			}
		}
	}

	putchar('\n');

	return 0;
}
/* @END_OF_SOURCE_CODE */
