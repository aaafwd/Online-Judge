/* @JUDGE_ID: 19899RK 10020 C++ "By Anadan" */
// Minimal coverage
// Accepted (0.789 seconds using as much as 2780 kbytes)

#include <stdio.h>
#include <stdlib.h>
#define SZ 100000

struct Segment{
	int x, y;
}pt[SZ], res[SZ];

int sort_function(const void *a, const void *b){
	Segment *sa = (Segment *)a, *sb = (Segment *)b;
	if (sa->x < sb->x) return -1;
	return 1;
}

int main(){
	int set, i, j, k, M, N, L, R, index;

	scanf("%d\n\n", &set);
	while (set--){
		N = 0;
		scanf("%d\n", &M);
		while (scanf("%d%d", &L, &R) == 2){
			if (L == 0 && R == 0) break;
			if (L >= R) continue;
			pt[N].x = L; pt[N].y = R;
			++N;
		}

		qsort(pt, N, sizeof(Segment), sort_function);
		L = i = index = 0;
		while (i < N){
			for (R = 0, j = i; j < N && pt[j].x <= L; ++j){
				if (R < pt[j].y) R = pt[j].y, k = j;
			}

			if (j == i){
				index = 0;
				break;
			}

			i = j; L = R;
			res[index++] = pt[k];
			if (R >= M) break;
		}

		if (L < M) index = 0;

		printf("%d\n", index);
		for (i = 0; i < index; ++i){
			printf("%d %d\n", res[i].x, res[i].y);
		}

		if (set) putchar('\n');
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
