/* @JUDGE_ID: 19899RK 10357 C++ "By Anadan" */ 
// Playball !!!
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>
#include <math.h>

int N, t, x, y;
struct Player{
	int x, y, v;
}pt[20];

inline int sqr(int x) { return x * x; }

int caught(){
	int i;
	double tmp;

	for (i = 0; i < N; ++i){
		if (pt[i].v == 0){
			if (x == pt[i].x && y == pt[i].y) return 1;
		}else{
			tmp = sqr(x - pt[i].x) + sqr(y - pt[i].y);
			if (tmp < sqr(t * pt[i].v)) return 1;
		}
	}

	return 0;
}

int main(){
	int M, i, a, b, c, d, e, f, g;
	double tmp;

	while (getchar() != '=');
	scanf("%d", &N);
	for (i = 0; i < N; ++i) scanf("%d%d%d", &pt[i].x, &pt[i].y, &pt[i].v);

	while (getchar() != '=');
	scanf("%d", &M);
	for (i = 1; i <= M; ++i){
		scanf("%d%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f, &g);

		if (c < 0) t = 0.0;
		else if (a == 0) t = double(-c) / double(b);
		else{
			tmp = double(b) * b - 4.0 * a * c;
			if (tmp < 0) tmp = 0; else tmp = sqrt(tmp);

			if (a > 0) tmp = double(-b + tmp) * 0.5 / double(a);
			else tmp = double(-b - tmp) * 0.5 / double(a);

			t = floor(tmp);
			if (t < 0) t = 0;

			while (a * t * t + b * t + c > 0) ++t;
		}

		x = t * d + e;
		y = t * f + g;

		printf("Ball %d was ", i);
		if (x < 0 || y < 0) fputs("foul at ", stdout);
		else if (caught()) fputs("caught at ", stdout);
		else fputs("safe at ", stdout);
		printf("(%d,%d)\n", x, y);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
