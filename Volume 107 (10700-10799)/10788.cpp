/* @JUDGE_ID: 19899RK 10788 C++ "By Anadan" */
// Parenthesizing Palindromes
// Accepted (0.002 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

char str[128], map[128][128];

int getmap(int i, int j) {
	int k;

	if (map[i][j] != -1) return map[i][j];
	if (i > j) return 1;
	if (i == j) return 0;

	map[i][j] = 0;
	for (k = j; k > i; --k) {
		if (str[i] != str[k]) continue;
		int t1 = getmap(i+1, k-1);
		int t2 = getmap(k+1, j);

		if (t1 && t2) {
			if (map[i][j] || t1 == 2 || t2 == 2) {
				map[i][j] = 2;
				break;
			}
			map[i][j] = 1;
		}
	}

	return map[i][j];
}

int main() {
	int set, cs = 0, i;

	scanf("%d", &set);
	while (set--) {
		scanf("%s", str);
		memset(map, -1, sizeof(map));

		i = strlen(str);
		if (i & 1) i = 0; else i = getmap(0, i - 1);

		printf("Case %d: ", ++cs);
		if (i == 0) puts("Invalid");
		else if (i == 1) puts("Valid, Unique");
		else if (i == 2) puts("Valid, Multiple");
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
