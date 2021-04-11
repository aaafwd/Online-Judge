/* @JUDGE_ID: 19899RK 10922 C++ "By Anadan" */
// 2 the 9s
// Accepted (0.064 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

int degree(int sum) {
	int resum = 0;
	if (sum % 9) return 0;
	if (sum == 9) return 1;
	while (sum) {
		resum += sum % 10;
		sum /= 10;
	}
	return degree(resum)+1;
}

int main() {
	int i, sum;
	char str[1024];

	while (scanf("%s", str) == 1 && strcmp(str, "0")) {
		for (i = sum = 0; str[i]; ++i) {
			sum += str[i] - '0';
		}
		if (sum % 9) {
			printf("%s is not a multiple of 9.\n", str);
		} else {
			printf("%s is a multiple of 9 and has 9-degree %d.\n", str, degree(sum));
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
