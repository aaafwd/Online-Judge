/* @JUDGE_ID: 19899RK 10921 C++ "By Anadan" */
// Find the Telephone
// Accepted (0.002 seconds with low memory spent)

#include <stdio.h>

char * convert(char * str) {
	int i;
	for (i = 0; str[i]; ++i) {
		if (str[i] == '0' || str[i] == '1' || str[i] == '-') continue;
		if (str[i] <= 'O') str[i] = (str[i] - 'A')/3 + '2';
		else if (str[i] <= 'S') str[i] = '7';
		else if (str[i] <= 'V') str[i] = '8';
		else str[i] = '9';
	}
	return str;
}

int main() {
	char str[1024];

	while (scanf("%s", str) == 1) {
		puts(convert(str));
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
