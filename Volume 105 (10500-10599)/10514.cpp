/* @JUDGE_ID: 19899RK 10514 C++ "By Anadan" */ 
// River Crossing
// Accepted (0.205 seconds using as much as 404 kbytes)

#include <stdio.h>
#include <math.h>

int r1, r2, N, m[11];
struct Point{
	int x, y;
}pt1[101], pt2[101], islands[11][20];

double map[15][15];

inline double sqr(double x) { return x * x; }

void setparams(Point *&poly, int &n, int i){
	if (i < N){
		poly = islands[i];
		n = m[i];
	}else if (i == N){
		poly = pt1;
		n = r1;
	}else{
		poly = pt2;
		n = r2;
	}
}

double getmindist(Point *p1, int n1, Point *p2, int n2){
	int i, j, k;
	double res = 1e10, tmp, a, b;

	for (i = 0; i < n1; ++i){
		for (j = 0; j < n2; ++j){
			k = (j + 1) % n2;
			tmp = sqrt(sqr(p1[i].x - p2[j].x) + sqr(p1[i].y - p2[j].y));
			if (res > tmp) res = tmp;

			if (k == 0 && (p2 == pt1 || p2 == pt2)) continue;

			a = p2[k].x - p2[j].x;
			b = p2[k].y - p2[j].y;
			tmp = a * (p1[i].x - p2[j].x) + b * (p1[i].y - p2[j].y);
			tmp /= (a * a + b * b);
			if (tmp < -1e-12 || tmp > 1 + 1e-12) continue;

			a = a * tmp + p2[j].x - p1[i].x;
			b = b * tmp + p2[j].y - p1[i].y;

			tmp = sqrt(a * a + b * b);
			if (res > tmp) res = tmp;
		}
	}

	return res;
}

int main(){
	int set, i, j, n1, n2;
	Point *poly1, *poly2;
	double t1, t2, ro[15];
	char mask[15];

	for (i = 0; i < 15; ++i) map[i][i] = 0.0;

	scanf("%d", &set);
	while (set--){
		scanf("%d%d%d", &r1, &r2, &N);
		for (i = 0; i < r1; ++i) scanf("%d%d", &pt1[i].x, &pt1[i].y);
		for (i = 0; i < r2; ++i) scanf("%d%d", &pt2[i].x, &pt2[i].y);

		for (i = 0; i < N; ++i){
			scanf("%d", m + i);
			for (j = 0; j < m[i]; ++j){
				scanf("%d%d", &islands[i][j].x, &islands[i][j].y);
			}
		}

		for (i = 0; i < N + 2; ++i){
			setparams(poly1, n1, i);
			for (j = i + 1; j < N + 2; ++j){
				setparams(poly2, n2, j);
				t1 = getmindist(poly1, n1, poly2, n2);
				t2 = getmindist(poly2, n2, poly1, n1);

				if (t1 > t2) t1 = t2;
				map[i][j] = map[j][i] = t1;
			}

			mask[i] = 0;
		}

		for (i = 0; i < N + 2; ++i) ro[i] = map[N][i];

		mask[N] = 1;
		while (1){
			j = -1;
			for (i = 0; i < N + 2; ++i){
				if (mask[i]) continue;
				if (j == -1 || t1 > ro[i]){
					t1 = ro[i];
					j = i;
				}
			}

			if (j == -1) break;
			mask[j] = 1;

			for (i = 0; i < N + 2; ++i){
				if (mask[i]) continue;
				if (ro[i] > ro[j] + map[i][j]){
					ro[i] = ro[j] + map[i][j];
				}
			}
		}

		printf("%.3lf\n", ro[N + 1]);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
