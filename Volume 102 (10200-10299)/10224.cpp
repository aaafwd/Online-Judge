/* @JUDGE_ID: 19899RK 10224 C++ "By Anadan" */ 
// Return of the Jedi
// Accepted (0.004 seconds with low memory spent)

#include <stdio.h>
#include <math.h>
#define SZ 440

int T;
struct Tree{
	double x, y, r;
}pt[12];

struct Point{
	int tree;
	double x, y;
}vertex[SZ];

int N;
double map[SZ][SZ];

inline double sqr(double x) { return x * x; }

void addedge(double &x1, double &y1, double &x2, double &y2, int t1, int t2){
	int i, j, k;
	double A, B, C, D;

	A = sqr(x2 - x1) + sqr(y2 - y1);

	for (i = 2; i < T; ++i){
		if (i == t1 || i == t2) continue;
		B = (x1 - pt[i].x) * (x2 - x1) + (y1 - pt[i].y) * (y2 - y1);
		C = sqr(x1 - pt[i].x) + sqr(y1 - pt[i].y) - sqr(pt[i].r);
		D = B * B - A * C;
		if (D < 0 || B > 0) continue;
		if ((A + B > 0 || sqr(A + B) <= D) && D <= B * B) return;
	}

	if (t1 == 0) j = 0;
	else if (t1 == 1) j = 1;
	else{
		for (i = 0; i <= N; ++i) map[i][N] = map[N][i] = -1.0;
		vertex[N].x = x1; vertex[N].y = y1; vertex[N].tree = t1;
		j = N++;
	}

	if (t2 == 1) k = 1;
	else{
		for (i = 0; i <= N; ++i) map[i][N] = map[N][i] = -1.0;
		vertex[N].x = x2; vertex[N].y = y2; vertex[N].tree = t2;
		k = N++;
	}

	map[j][k] = map[k][j] = sqrt(A);
	for (i = 2; i < N; ++i){
		if (vertex[i].tree == t1){
			B = (vertex[i].x - pt[t1].x) * (vertex[j].x - pt[t1].x) + (vertex[i].y - pt[t1].y) * (vertex[j].y - pt[t1].y);
			B /= sqr(pt[t1].r);
			if (B > 1.0) B = 1.0;
			if (B < -1.0) B = -1.0;
			C = acos(B);
			map[i][j] = map[j][i] = C * pt[t1].r;
		}

		if (vertex[i].tree == t2){
			B = (vertex[i].x - pt[t2].x) * (vertex[k].x - pt[t2].x) + (vertex[i].y - pt[t2].y) * (vertex[k].y - pt[t2].y);
			B /= sqr(pt[t2].r);
			if (B > 1.0) B = 1.0;
			if (B < -1.0) B = -1.0;
			C = acos(B);
			map[i][k] = map[k][i] = C * pt[t2].r;
		}
	}
}

double getminpath(){
	int i, j;
	double ro[SZ], min;
	char mask[SZ];

	mask[0] = 1;
	for (i = 1; i < N; ++i){
		mask[i] = 0;
		ro[i] = map[0][i];
	}

	if (ro[1] != -1.0) return ro[1];

	while (1){
		j = -1;
		for (i = 1; i < N; ++i){
			if (mask[i] || ro[i] == -1.0) continue;
			if (j == -1 || min > ro[i]){
				min = ro[i];
				j = i;
			}
		}

		if (j == 1) break;
		mask[j] = 1;
		for (i = 1; i < N; ++i){
			if (mask[i] || map[j][i] == -1.0) continue;
			if (ro[i] == -1 || ro[i] > ro[j] + map[j][i]){
				ro[i] = ro[j] + map[j][i];
			}
		}
	}

	return ro[1];
}

int main(){
	int set, i, j;
	double cosa, sina, L, x1, y1, x2, y2, a, b;

	pt[0].r = pt[1].r = 0.0;
	scanf("%d\n\n", &set);
	while (set--){
		map[0][0] = map[0][1] = map[1][0] = map[1][1] = -1.0;
		scanf("%d%lf%lf%lf%lf", &T, &pt[0].x, &pt[0].y, &pt[1].x, &pt[1].y);
		T += 2;
		for (i = 2; i < T; ++i){
			scanf("%lf%lf%lf\n", &pt[i].x, &pt[i].y, &pt[i].r);
			pt[i].r *= 0.5;
		}

		N = 2;
		for (i = 0; i < T; ++i){
			for (j = i + 1; j < T; ++j){
				L = sqrt(sqr(pt[i].x - pt[j].x) + sqr(pt[i].y - pt[j].y));
				a = (pt[j].x - pt[i].x) / L;
				b = (pt[j].y - pt[i].y) / L;

				cosa = (pt[i].r - pt[j].r) / L;
				sina = sqrt(1.0 - cosa * cosa);

				x1 = pt[i].x + pt[i].r * (a * cosa + b * sina);
				y1 = pt[i].y + pt[i].r * (-a * sina + b * cosa);
				x2 = pt[j].x + pt[j].r * (a * cosa + b * sina);
				y2 = pt[j].y + pt[j].r * (-a * sina + b * cosa);

				addedge(x1, y1, x2, y2, i, j);
				if (j == 1) continue;

				x1 = pt[i].x + pt[i].r * (a * cosa - b * sina);
				y1 = pt[i].y + pt[i].r * (a * sina + b * cosa);
				x2 = pt[j].x + pt[j].r * (a * cosa - b * sina);
				y2 = pt[j].y + pt[j].r * (a * sina + b * cosa);

				addedge(x1, y1, x2, y2, i, j);
				if (i < 2) continue;

				cosa = (pt[i].r + pt[j].r) / L;
				sina = sqrt(1.0 - cosa * cosa);

				x1 = pt[i].x + pt[i].r * (a * cosa + b * sina);
				y1 = pt[i].y + pt[i].r * (-a * sina + b * cosa);
				x2 = pt[j].x - pt[j].r * (a * cosa + b * sina);
				y2 = pt[j].y - pt[j].r * (-a * sina + b * cosa);

				addedge(x1, y1, x2, y2, i, j);

				x1 = pt[i].x + pt[i].r * (a * cosa - b * sina);
				y1 = pt[i].y + pt[i].r * (a * sina + b * cosa);
				x2 = pt[j].x - pt[j].r * (a * cosa - b * sina);
				y2 = pt[j].y - pt[j].r * (a * sina + b * cosa);

				addedge(x1, y1, x2, y2, i, j);
			}
		}

		L = getminpath() * 18.0;
		printf("%.2lf\n", L);

		if (set) putchar('\n');
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
