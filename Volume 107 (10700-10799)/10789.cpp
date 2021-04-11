/* @JUDGE_ID: 19899RK 10789 C++ "By Anadan" */
// Prime Frequency
// Accepted (0.016 seconds with low memory spent)

#include <stdio.h>
#include <string.h>
#define SZ 2048

char mask[SZ];

void primesSieve() {
	int i, j;
	memset(mask, 0, sizeof(mask));
	mask[0] = mask[1] = 1;
	for (i = 2; i < SZ; ++i) {
		if (mask[i]) continue;
		for (j = i+i; j < SZ; j += i) mask[j] = 1;
	}
}

int main() {
	int set, cs = 0, i, flag, lets[256];
	char str[SZ];

	primesSieve();
	scanf("%d", &set);
	while (set--) {
		scanf("%s", str);
		memset(lets, 0, sizeof(lets));
		for (i = 0; str[i]; ++i) ++lets[str[i]];

		printf("Case %d: ", ++cs);
		for (flag = i = 0; i < 256; ++i) {
			if (mask[lets[i]]) continue;
			flag = 1;
			putchar(i);
		}
		if (flag) putchar('\n');
		else puts("empty");
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
