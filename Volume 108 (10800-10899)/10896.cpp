/* @JUDGE_ID: 19899RK 10896 C++ "By Anadan" */
// Known Plaintext Attack
// Accepted (0.002 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

char mask[32];

void check(char * s1, char * s2) {
	int k;

	if (strlen(s1) != strlen(s2)) return;
	k = (*s2++ - *s1++ + 26) % 26;
	while (*s1) {
		if ((*s1++ - 'a' + k) % 26 != *s2++ - 'a') return;
	}
	mask[k] = 1;
}

int main() {
	int set, i;
	char str[128], word[32], *p;

	scanf("%d", &set);
	while (getchar() != '\n');
	while (set--) {
		gets(str);
		gets(word);
		memset(mask, 0, sizeof(mask));

		p = strtok(str, " ");
		while (p) {
			check(word, p);
			p = strtok(NULL, " ");
		}

		for (i = 0; i < 32; ++i) {
			if (mask[i]) putchar('a'+i);
		}
		putchar('\n');
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
