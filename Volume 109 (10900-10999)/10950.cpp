/* @JUDGE_ID: 19899RK 10950 C++ "By Anadan" */
// Bad Code
// Accepted (0.164 seconds using as much as 396 kbytes)

#include <stdio.h>
#include <string.h>

struct Letter {
	char code[3];
} pt[26];
int N, count;
char curr[256];

void generate(char * str, int len) {
	int i, j;

	if (count >= 100) return;

	if (!*str) {
		curr[len] = 0;
		puts(curr);
		++count;
		return;
	}

	if (*str == '0') ++str;

	for (i = 0; i < 26; ++i) {
		j = strlen(pt[i].code);
		if (j == 0) continue;
		if (strncmp(str, pt[i].code, j) == 0) {
			curr[len] = i + 'a';
			generate(str+j, len+1);
		}
	}
}

int main() {
	int i, set = 0;
	char s1[2], s2[4], str[256];

	while (scanf("%d", &N) == 1 && N) {
		for (i = 0; i < 26; ++i) pt[i].code[0] = 0;
		for (i = 0; i < N; ++i) {
			scanf("%s%s", s1, s2);
			strcpy(pt[s1[0]-'a'].code, s2);
		}
		scanf("%s", str);
		printf("Case #%d\n", ++set);
		count = 0;
		generate(str, 0);
		puts("");
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
