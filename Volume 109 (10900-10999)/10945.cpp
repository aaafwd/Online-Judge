/* @JUDGE_ID: 19899RK 10945 C++ "By Anadan" */
// Mother Bear
// Accepted (0.006 seconds with low memory spent)

#include <stdio.h>
#include <string.h>
#include <ctype.h>

char str[1024*16];
int pos;

void getline() {
	int i;

	pos = 0;
	while ((i = getchar()) != '\n' && i != EOF) {
		if (isalpha(i)) str[pos++] = i;
	}
	str[pos] = 0;
}

int main() {
	int i;
	while (1) {
		getline();
		if (strcmp(str, "DONE") == 0) break;
		i = 0;
		--pos;
		while (i < pos) {
			if (tolower(str[i]) != tolower(str[pos])) break;
			++i; --pos;
		}
		if (i < pos) puts("Uh oh..");
		else puts("You won't be eaten!");
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
