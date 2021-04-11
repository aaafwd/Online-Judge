/* @JUDGE_ID: 19899RK 517 C++ "By Anadan" */ 
// Word
// Accepted (0.086 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

int N, mask[16385];
char rules[8][5], word[16];

void normalize(char *s){
	int i, j;
	static char str[32];

	strcpy(str, s);
	strcpy(str + N, s);

	for (j = i = 0; i < N; ++i){
		if (strncmp(str + i, str + j, N) < 0) j = i;
	}

	for (i = 0; i < N; ++i) s[i] = str[i + j];
}

int getindex(char *s){
	int res = 0;

	if (s[0] == 'b') return 16384;
	while (*s){
		res <<= 1;
		if (*s++ == 'b') res |= 1;
	}

	return res;
}

int setstep(){
	int i, j;
	static char str[32];

	for (i = 0; i < N; ++i){
		for (j = 0; j < 8; ++j){
			if (word[i] == rules[j][1] && word[(i + 1) % N] == rules[j][2] && word[(i + N - 2) % N] == rules[j][0]){
				str[i] = rules[j][3];
			}
		}
	}

	for (i = 0; i < N; ++i) word[i] = str[i];
	normalize(word);
	return getindex(word);
}

void outprint(int index, int step){
	if (step == 0) return;
	outprint(index >> 1, step - 1);
	putchar('a' + (index & 1));
}

int main(){
	int i, j, s;

	while (scanf("%d", &N) == 1){
		scanf("%s", word);
		for (i = 0; i < 8; ++i) scanf("%s", rules[i]);
		
		scanf("%d", &s);
		memset(mask, -1, sizeof(mask));
		normalize(word);
		j = getindex(word);
		mask[j] = 0;

		for (i = 1; i <= s; ++i){
			j = setstep();
			if (mask[j] == -1) mask[j] = i;
			else break;
		}

		if (i <= s){
			i = mask[j] + (s - mask[j]) % (i - mask[j]);
			for (j = 0; mask[j] != i; ++j);
		}

		if (j == 16384) while (N--) putchar('b');
		else outprint(j, N);
		putchar('\n');
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
