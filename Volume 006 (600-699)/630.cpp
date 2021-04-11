/* @JUDGE_ID: 19899RK 630 C++ "By Anadan" */
// Anagrams (II)
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

int anagrams(const char * s1, const char * s2) {
	char *p, str[21];
	strcpy(str, s1);

	for(; *s2; ++s2) {
		if ((p = strchr(str, *s2)) == NULL) return 0;
		*p = ' ';
	}
	for (p = str; *p; ++p) if (*p != ' ') return 0;
	return 1;
}

int main() {
	int i, j, N, set;
	char str[21], dict[1000][21];

	scanf("%d", &set);
	while (set--) {
		scanf("%d", &N);
		for (i = 0; i < N; ++i) scanf("%s", dict[i]);

		while (scanf("%s", str) == 1) {
			if (str[0] == 'E') break;
			printf("Anagrams for: %s\n", str);
			for (i = j = 0; i < N; ++i) {
				if (anagrams(str, dict[i])) {
					printf("%3d) %s\n", ++j, dict[i]);
				}
			}
			if (!j) printf("No anagrams for: %s\n", str);
		}
		if (set) putchar('\n');
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
