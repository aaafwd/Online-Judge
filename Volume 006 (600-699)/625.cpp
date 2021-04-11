/* @JUDGE_ID: 19899RK 625 C++ "By Anadan" */
// Compression
// Accepted (0.004 seconds with low memory spent)

#include <stdio.h>
#include <string.h>
#define SZ 2000

const char keywords[16][10] = {
	"var", "end", "for", "then", "else", "case", "goto",
	"const", "label", "while", "begin", "until", "repeat",
	"downto", "function", "procedure"
};

int N;
char ident[SZ][40];

int getkeyword(char *str) {
	int i;
	for (i = 0; i < 16; ++i) if (strcmp(keywords[i], str) == 0) return i;
	return -1;
}

int getindex(char *str) {
	int i;
	for (i = 0; i < N; ++i) if (strcmp(ident[i], str) == 0) return i;
	strcpy(ident[N++], str);
	return -1;
}

inline int _isalnum(int i) {
	if (('0' <= i && i <= '9') || ('a' <= i && i <= 'z') || ('A' <= i && i <= 'Z')) return 1;
	else return 0;
}

int main() {
	int i, j, set;
	char str[40], *p;

	scanf("%d", &set);
	while (getchar() != '\n');
	while (getchar() != '\n');

	while (set--) {
		N = 0;
		while ((i = getchar()) != EOF) {
			if (_isalnum(i)) {
				p = str;
				*p++ = i;
				while (_isalnum(i = getchar())) *p++ = i;
				*p = 0;

				j = getkeyword(str);
				if (j == -1) {
					if (p >= str + 3) j = getindex(str);
					if (j == -1) {
						printf("%s", str);
						putchar(i);
						continue;
					}
					
					j += 16;
				}

				if (j == 1 && i == '.') {
					printf("&1.\n");
					while ((i = getchar()) != '\n' && i != EOF);
					break;
				}

				printf("&%d", j);
			}

			putchar(i);
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
