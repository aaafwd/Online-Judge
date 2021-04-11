/* @JUDGE_ID: 19899RK 10574 C++ "By Anadan" */
// Counting Rectangles
// Accepted (1.385 seconds using as much as 628 kbytes)

#include <stdio.h>
#include <stdlib.h>

struct Point{
	int x, y, i;
}ptx[5000], pty[5000];
int N;

int sort_function_x(const void *a, const void *b){
	Point *pa = (Point *)a, *pb = (Point *)b;
	if (pa->x < pb->x) return -1;
	if (pa->x > pb->x) return 1;
	if (pa->y < pb->y) return -1;
	if (pa->y > pb->y) return 1;
	return 0;
}

int sort_function_y(const void *a, const void *b){
	Point *pa = (Point *)a, *pb = (Point *)b;
	if (pa->y < pb->y) return -1;
	if (pa->y > pb->y) return 1;
	if (pa->x < pb->x) return -1;
	if (pa->x > pb->x) return 1;
	return 0;
}

int get_squares(){
	int i, j, a, b, res = 0;

	for (i = 0; i < N; ++i){
		for (j = i + 1; j < N; ++j){
			if (ptx[i].x != ptx[j].x) break;
			if (ptx[i].y == ptx[j].y) continue;
			a = ptx[i].i + 1;
			b = ptx[j].i + 1;
			while (a < N && b < N && pty[a].y == ptx[i].y && pty[b].y == ptx[j].y){
				if (pty[a].x < pty[b].x) ++a;
				else if (pty[a].x > pty[b].x) ++b;
				else{
					++a; ++b; ++res;
				}
			}
		}
/*
		for (j = i + 1; j < N; ++j){
			if (pt[i].x != pt[j].x) break;
			if (pt[i].y == pt[j].y) continue;
			sz = pt[j].y - pt[i].y;

			tmp.x = pt[i].x + sz;
			tmp.y = pt[i].y;
			if (!bsearch(&tmp, pt, N, sizeof(Point), sort_function)) continue;

			tmp.y = pt[j].y;
			if (!bsearch(&tmp, pt, N, sizeof(Point), sort_function)) continue;

			++res;
		}
*/
	}

	return res;
}

int main(){
	int set, cs = 0, i;
	Point tmp, *p;

	scanf("%d", &set);
	while (set--){
		scanf("%d", &N);
		for (i = 0; i < N; ++i){
			scanf("%d%d", &ptx[i].x, &ptx[i].y);
			pty[i] = ptx[i];
		}
		qsort(ptx, N, sizeof(Point), sort_function_x);
		qsort(pty, N, sizeof(Point), sort_function_y);
		for (i = 0; i < N; ++i){
			tmp = ptx[i];
			p = (Point *)bsearch(&tmp, pty, N, sizeof(Point), sort_function_y);
			ptx[i].i = int(p - pty);
		}
		for (i = 0; i < N; ++i){
			tmp = pty[i];
			p = (Point *)bsearch(&tmp, ptx, N, sizeof(Point), sort_function_y);
			pty[i].i = int(p - ptx);
		}

		printf("Case %d: %d\n", ++cs, get_squares());
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
