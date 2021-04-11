/* @JUDGE_ID: 19899RK 10421 C++ "By Anadan" */ 
// Critical Wave
// Accepted (0.793 seconds using as much as 412 kbytes)

#include <stdio.h>
#include <stdlib.h>

struct Point{
	int x, y;
}pt[1000];

int sort_function(const void *a, const void *b){
	Point *pa = (Point *)a, *pb = (Point *)b;
	if (pa->y < pb->y) return -1;
	if (pa->y > pb->y) return 1;
	if (pa->x < pb->x) return -1;
	return 1;
}

int main(){
	int N, i, j, k, l, cur, max;

	while (scanf("%d\n", &N) == 1){
		for (i = 0; i < N; ++i) scanf("%d%d\n", &pt[i].x, &pt[i].y);
		qsort(pt, N, sizeof(Point), sort_function);

		max = 0;
		for (i = 0; i < N; ++i){
			k = i;
			cur = 1;

			for (j = i + 1; j < N; ++j) if (pt[j].y >= pt[i].y + 2) break;
			l = j;
			while (1){
				for (; j < N && pt[j].y == pt[i].y + 2; ++j){
					if (pt[j].x > pt[i].x){
						++cur;
						break;
					}
				}
				if (j == N || pt[j].y != pt[i].y + 2) break;

				for (++i; i < N && pt[i].y == pt[i - 1].y; ++i){
					if (pt[i].x > pt[j].x){
						++cur;
						break;
					}
				}
				if (i == N || pt[i].y != pt[i - 1].y) break;
			}

			j = l; i = k;
			while (1){
				for (; j < N && pt[j].y == pt[i].y + 2; ++j){
					if (pt[j].x < pt[i].x){
						++cur;
						break;
					}
				}
				if (j == N || pt[j].y != pt[i].y + 2) break;

				for (++i; i < N && pt[i].y == pt[i - 1].y; ++i){
					if (pt[i].x < pt[j].x){
						++cur;
						break;
					}
				}
				if (i == N || pt[i].y != pt[i - 1].y) break;
			}

			for (++k; k < N && pt[k].y == pt[k - 1].y; ++k);
			i = k - 1;

			if (max < cur) max = cur;
		}

		printf("%d\n", max);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
