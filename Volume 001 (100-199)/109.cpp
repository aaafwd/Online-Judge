/* @JUDGE_ID: 19899RK 109 C++ "By Anadan" */
// SCUD Busters
// Accepted (0.000 seconds with low memory spent)

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Point{
	int x, y;
};

int xcm, ycm;
int convhull_sort_func(const void *a, const void *b){
	Point *pa = (Point *)a, *pb = (Point *)b;

	if (pa->x == xcm && pa->y == ycm) return 1;
	if (pb->x == xcm && pb->y == ycm) return -1;

	if (atan2(pa->x - xcm, pa->y - ycm) < atan2(pb->x - xcm, pb->y - ycm)) return -1;
	return 1;
}

int is_in_triangle(int x, int y, int x1, int y1, int x2, int y2){
	int s1 = (y1 - ycm)*(x1 - x2) - (x1 - xcm)*(y1 - y2);
	int s2 = (y  - ycm)*(x  - x2) - (x  - xcm)*(y  - y2);
	int s3 = (y1 - ycm)*(x1 - x ) - (x1 - xcm)*(y1 - y );
	int s4 = (y1 - y)*(x1 - x2) - (x1 - x)*(y1 - y2);

	if (s1 < 0) s1 = -s1;
	if (s2 < 0) s2 = -s2;
	if (s3 < 0) s3 = -s3;
	if (s4 < 0) s4 = -s4;

	if (s1 == s2 + s3 + s4) return 1;
	return 0;
}

Point *get_convex_hull(Point *ptr_sav, int N, int &N_res){
	int i;
	char changed;
	Point *ptr = (Point *)malloc(N * sizeof(Point));

	memcpy(ptr, ptr_sav, N * sizeof(Point));
	for (xcm = ycm = i = 0; i < N; ++i){
		xcm += ptr[i].x; ycm += ptr[i].y;
	}
	xcm = (xcm + N/2) / N; ycm = (ycm + N/2) / N;
	qsort((void *)ptr, N, sizeof(Point), convhull_sort_func);

	for (i = N - 1; i > 0; --i) if (ptr[i].x != xcm || ptr[i].y != ycm) break;
	N_res = i + 1;
	changed = 1;
	while (changed){
		changed = 0;
		for (i = 0; i < N_res; ++i){
			if (is_in_triangle(ptr[i].x, ptr[i].y, ptr[(i + N_res - 1) % N_res].x, ptr[(i + N_res - 1) % N_res].y, ptr[(i + 1) % N_res].x, ptr[(i + 1) % N_res].y)){
				memcpy(ptr + i, ptr + i + 1, (N_res - i - 1) * sizeof(Point));
				--N_res;
				if (i--) --i;
				changed = 1;
			}
		}
	}

	return ptr;
}

int is_in_polygon(int x, int y, Point *ptr, int N){
	int i, t1, t2;
	char sign;

	t1 = (ptr[N - 1].x - x) * (ptr[0].y - y);
	t2 = (ptr[0].x - x) * (ptr[N - 1].y - y);
	if (t1 == t2) sign = 0;
	else if (t1 > t2) sign = 1; else sign = -1;

	for (i = 0; i < N - 1; ++i){
		t1 = (ptr[i].x - x) * (ptr[i + 1].y - y);
		t2 = (ptr[i + 1].x - x) * (ptr[i].y - y);
		if (t1 == t2) continue;
		if (t1 > t2){
			if (sign == -1) return 0;
			sign = 1;
		}
		if (t1 < t2){
			if (sign == 1) return 0;
			sign = -1;
		}
	}

	return 1;
}

int getpolyarea2(Point *ptr, int N){
	int i, S = 0, tmp;

	for (i = 1; i < N - 1; ++i){
		tmp = (ptr[0].y - ptr[i].y) * (ptr[i + 1].x - ptr[i].x) - (ptr[i + 1].y - ptr[i].y) * (ptr[0].x - ptr[i].x);
		if (tmp < 0) tmp = -tmp;
		S += tmp;
	}

	return S;
}

int main(){
	int tot_kind, hull_size[20], N, i, j, k, S;
	char mask[20];
	Point pt[100], *hulls[20];

	tot_kind = 0;
	while (scanf("%d", &N) == 1 && N != -1){
		for (i = 0; i < N; ++i) scanf("%d%d", &pt[i].x, &pt[i].y);
		hulls[tot_kind] = get_convex_hull(pt, N, hull_size[tot_kind]);
		++tot_kind;
	}

	memset(mask, 0, tot_kind);
	while (scanf("%d%d", &i, &j) == 2){
		for (k = 0; k < tot_kind; ++k){
			if (mask[k]) continue;
			if (is_in_polygon(i, j, hulls[k], hull_size[k])) mask[k] = 1;
		}
	}

	for (S = i = 0; i < tot_kind; ++i){
		if (mask[i]) S += getpolyarea2(hulls[i], hull_size[i]);
	}

	printf("%.2lf\n", double(S) * 0.5);

	for (i = 0; i < tot_kind; ++i) free(hulls[i]);
	return 0;
}
/* @END_OF_SOURCE_CODE */
