/* @JUDGE_ID: 19899RK 10739 C++ "By Anadan" */
// String to Palindrome
// Accepted (0.111 seconds using as much as 2376 kbytes)

#include <stdio.h>
#include <string.h>

char str[1024];
short min[1000][1000];

int getmin(int i, int j) {
	int res, tmp;

	if (i >= j) return 0;
	if (min[i][j] != -1) return min[i][j];
	if (str[i] == str[j]) {
		min[i][j] = getmin(i+1, j-1);
		return min[i][j];
	}

	res = getmin(i+1, j-1) + 1;
	tmp = getmin(i+1, j) + 1; if (res > tmp) res = tmp;
	tmp = getmin(i, j-1) + 1; if (res > tmp) res = tmp;
	min[i][j] = res;

	return res;
}

int main() {
	int set, cs = 0;

	scanf("%d", &set);
	while (set--) {
		scanf("%s", str);
		memset(min, -1, sizeof(min));
		printf("Case %d: %d\n", ++cs, getmin(0, strlen(str)-1));
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
