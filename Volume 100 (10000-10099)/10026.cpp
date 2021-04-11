/* @JUDGE_ID: 19899RK 10026 C++ "By Anadan" */
// Shoemaker's Problem
// Accepted (0.008 seconds with low memory spent)

#include <stdio.h>
#include <stdlib.h>

struct Jobs {
	int T, S, i;
} pt[1024];

int sort_function(const void *a, const void *b) {
	Jobs *ja = (Jobs *)a, *jb = (Jobs *)b;
	if (jb->S * ja->T < ja->S * jb->T) return -1;
	if (jb->S * ja->T > ja->S * jb->T) return  1;
	if (ja->i < jb->i) return -1;
	return 1;
}

int main() {
	int set, i, N;

	scanf("%d", &set);
	while (set--) {
		scanf("%d", &N);
		for (i = 0; i < N; ++i) {
			scanf("%d%d", &pt[i].T, &pt[i].S);
			pt[i].i = i;
		}
		qsort(pt, N, sizeof(pt[0]), sort_function);

		for (i = 0; i < N; ++i) {
			if (i) putchar(' ');
			printf("%d", pt[i].i+1);
		}
		putchar('\n');

		if (set) putchar('\n');
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
