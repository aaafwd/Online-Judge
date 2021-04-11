/* @JUDGE_ID: 19899RK 10245 C++ "By Anadan" */
// The Closest Pair Problem
// Accepted (0.918 seconds using as much as 1192 kbytes)

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define SZ 10000
#define MAXDIST 100000000

struct Point {
	int index;
	double x, y;
} ptx[SZ], pty[SZ];
int buf[SZ];

inline double sqr(double x) { return x * x; }

int sortxy(const void *a, const void *b) {
	Point *pa = (Point*)a, *pb = (Point*)b;
	if (pa->x < pb->x) return -1;
	return 1;
}

int sortyx(const void *a, const void *b) {
	Point *pa = (Point*)a, *pb = (Point*)b;
	if (pa->y < pb->y) return -1;
	return 1;
}

double calcMinDist(int * idx, int * idy, int N) {
	int i, j, k;
	double tmp, res, mid;

	if (N < 20) {
		res = -1;
		for (i = 0; i < N; ++i) {
			for (j = i + 1; j < N; ++j) {
				tmp = sqr(ptx[idx[i]].x - ptx[idx[j]].x) + sqr(ptx[idx[i]].y - ptx[idx[j]].y);
				if (res < 0 || res > tmp) res = tmp;
			}
		}
		return res;
	}

	int * nindex = new int[(N+1)/2];

	k = ptx[idx[N/2]].index;
	for (i = j = 0; i < N; ++i) if (pty[idy[i]].index < k) nindex[j++] = idy[i];
	res = calcMinDist(idx, nindex, N/2);

	for (i = j = 0; i < N; ++i) if (pty[idy[i]].index >= k) nindex[j++] = idy[i];
	tmp = calcMinDist(idx+N/2, nindex, (N+1)/2);
	if (res > tmp) res = tmp;

	mid = ptx[idx[N/2]].x;
	for (i = j = 0; i < N; ++i) {
		if (sqr(pty[idy[i]].x - mid) <= res) {
			buf[j] = idy[i];
			k = j - 7;
			if (k < 0) k = 0;
			while (k < j) {
				tmp = sqr(pty[buf[k]].x - pty[buf[j]].x) + sqr(pty[buf[k]].y - pty[buf[j]].y);
				if (res > tmp) res = tmp;
				++k;
			}
			++j;
		}
	}

	delete[] nindex;
	return res;
}

void myscanf(double &x){
	int i, sgn = 0;
	double y;

	while ((i = getchar()) != EOF && i != '.' && i != '-' && (i < '0' || i > '9'));
	if (i == '-'){
		sgn = 1;
		i = getchar();
	}

	if (i != '.'){
		x = i - '0';
		while ((i = getchar()) != EOF && i != '.' && '0' <= i && i <= '9'){
			x = x * 10 + i - '0';
		}
	}else x = 0.0;

	if (i == '.'){
		y = 0.1;
		while ((i = getchar()) != EOF && '0' <= i && i <= '9'){
			x += y * (i - '0');
			y *= 0.1;
		}
	}

	if (sgn) x = -x;
}

int main() {
	int N, i, idx[SZ];
	double dist;

	for (i = 0; i < SZ; ++i) idx[i] = i;

	while (scanf("%d", &N) == 1 && N) {
		for (i = 0; i < N; ++i) {
			myscanf(ptx[i].x);
			myscanf(ptx[i].y);
		}
		if (N == 1) { puts("INFINITY"); continue; }

		qsort(ptx, N, sizeof(Point), sortxy);
		for (i = 0; i < N; ++i) {
			ptx[i].index = i;
			pty[i] = ptx[i];
		}
		qsort(pty, N, sizeof(Point), sortyx);
		dist = calcMinDist(idx, idx, N);

		if (dist+1e-12 < MAXDIST) printf("%.4lf\n", sqrt(dist));
		else puts("INFINITY");
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
