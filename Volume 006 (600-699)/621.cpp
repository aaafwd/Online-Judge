/* @JUDGE_ID: 19899RK 621 C++ "By Anadan" */
// Secret Research
// Accepted (0.002 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

int getresult(char *str) {
	int len = strlen(str);

	if (len < 3) return 0;
	if (str[len - 1] == '5' && str[len - 2] == '3') return 1;
	if (str[0] == '9' && str[len - 1] == '4') return 2;
	if (str[0] == '1' && str[1] == '9' && str[2] == '0') return 3;
	return 0;
}

int main() {
	int set;
	char str[1024];

	scanf("%d", &set);
	while (set--) {
		scanf("%s", str);
		printf("%c\n", "+-*?"[getresult(str)]);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
