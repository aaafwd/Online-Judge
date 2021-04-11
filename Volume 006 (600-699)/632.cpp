/* @JUDGE_ID: 19899RK 632 C++ "By Anadan" */ 
// Compression (II)
// Accepted (0.260 seconds using as much as 8320 kbytes)

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SZ 2000

int sort_function(const void *a, const void *b){
	return strcmp((char *)a, (char *)b);
}

int main(){
	int set, N, i, j, k, c;
	char str[4000], *s;
	static char map[SZ][SZ];

	scanf("%d\n", &set);
	while (set--){
		scanf("%d", &N);
		for (s = str, i = 0; i < N; ++i){
			while ((c = getchar()) == '\n');
			*s++ = c;
		}

		memcpy(s, str, N); s[N] = 0;
		for (s = str, i = 0; i < N; ++i){
			memcpy(map[i], s++, N);
			map[i][N] = 0;
		}

		qsort(map, N, sizeof(map[0]), sort_function);

		str[N + 1] = 0;
		i = N;
		while ((s = (char *)bsearch(str + 1, map, i, sizeof(map[0]), sort_function)) != NULL){
			i = int(s - (char *)map) / sizeof(map[0]);
		}
		if (strncmp(str, str + 1, N) == 0) ++i;

		printf("%d\n", i);

		c = N / 50;
		for (k = i = 0; i < c; ++i){
			for (j = 0; j < 50; ++j) putchar(map[k++][N - 1]);
			putchar('\n');
		}
		while (k < N) putchar(map[k++][N - 1]);
		putchar('\n');

		if (set) putchar('\n');
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
