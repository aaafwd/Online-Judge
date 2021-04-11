/* @JUDGE_ID: 19899RK 10389 C++ "By Anadan" */
// Subway
// Accepted (0.074 seconds with low memory spent)

#include <math.h>
#include <stdio.h>
#include <string.h>
#define SZ 220

int N;
double map[SZ][SZ];
struct Point{
	double x, y;
}pt[SZ];

inline double sqr(double x) { return x * x; }

double getminpath(){
	int i, j;
	double ro[SZ], min;
	char mask[SZ];

	memset(mask, 0, N);
	for (i = 1; i < N; ++i) ro[i] = map[0][i];

	while (1){
		for (min = -1, i = 1; i < N; ++i){
			if (mask[i] == 0){
				if (min == -1 || min > ro[i]){
					min = ro[i];
					j = i;
				}
			}
		}

		if (min == -1 || j == 1) break;
		mask[j] = 1;

		for (i = 1; i < N; ++i){
			if (mask[i] == 0 && map[j][i] != -1){
				if (ro[i] > ro[j] + map[j][i]) ro[i] = ro[j] + map[j][i];
			}
		}
	}

	return ro[1];
}

int main(){
	int set, off, i, j;
	char str[3000], *p;
	double x, y;

	scanf("%d\n\n", &set);
	while (set--){
		for (i = 0; i < SZ; ++i) for (j = 0; j < SZ; ++j) map[i][j] = -1.0;
		gets(str);
		sscanf(str, "%lf%lf%n", &x, &y, &off); pt[0].x = x; pt[0].y = y;
		sscanf(str + off, "%lf%lf", &x, &y); pt[1].x = x; pt[1].y = y;
		N = 2;
		while (gets(str) && sscanf(str, "%lf%lf%n", &x, &y, &off) == 2){
			pt[N].x = x; pt[N].y = y;

			p = str + off;
			for (++N; sscanf(p, "%lf%lf%n", &x, &y, &off) == 2; p += off, ++N){
				if (x < -0.5 || y < -0.5) break;
				pt[N].x = x; pt[N].y = y;
				map[N - 1][N] = map[N][N - 1] = sqrt(sqr(pt[N].x - pt[N - 1].x) + sqr(pt[N].y - pt[N - 1].y));
			}
		}

		for (i = 0; i < N; ++i) for (j = i + 1; j < N; ++j){
			if (map[i][j] == -1){
				map[i][j] = map[j][i] = sqrt((sqr(pt[i].x - pt[j].x) + sqr(pt[i].y - pt[j].y))) * 4;
			}
		}

		printf("%.0lf\n", getminpath() * 0.0015);
		if (set) putchar('\n');
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
