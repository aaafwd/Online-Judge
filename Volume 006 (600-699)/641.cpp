/* @JUDGE_ID: 19899RK 641 C++ "By Anadan" */
// Do the Untwist
// Accepted (0.002 seconds with low memory spent)

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Point {
	int i, j;
} pt[70];

int sort_function(const void * a, const void * b) {
	if (((Point *)a)->j < ((Point *)b)->j) return -1;
	return 1;
}

int main() {
	int k, n, i;
	char str[71];
	char letters[29] = "_abcdefghijklmnopqrstuvwxyz.";

	while (scanf("%d", &k) == 1 && k) {
		scanf("%s\n", str);
		n = strlen(str);
		k %= n;
		for (i = 0; i < n; ++i) {
			pt[i].i = i;
			pt[i].j = (i * k) % n;
		}
		qsort((void *)pt, n, sizeof(Point), sort_function);

		for (i = 0; i < n; ++i) {
			putchar(letters[(int(strchr(letters, str[pt[i].i]) - letters) + pt[i].i) % 28]);
		}
		putchar('\n');
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
