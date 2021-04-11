/* @JUDGE_ID: 19899RK 10823 C++ "By Anadan" */
// Of Circles and Squares
// Accepted (0.066 seconds with low memory spent)

#include <stdio.h>

struct Shape {
	char type;
	int x, y, sz, r, g, b;
} pt[100];
int N;
double red, green, blue;

inline int sqr(int x) { return x * x; }

void calcColor(int x, int y) {
	int i, tx, ty, count = 0, r = 0, g = 0, b = 0;

	for (i = 0; i < N; ++i) {
		if (pt[i].type == 'c') {
			tx = sqr(pt[i].x - x) + sqr(pt[i].y - y) - sqr(pt[i].sz);
			if (tx == 0) {
				red = green = blue = 0;
				return;
			}
			if (tx < 0) {
				r += pt[i].r;
				g += pt[i].g;
				b += pt[i].b;
				++count;
			}
		} else {
			tx = x - pt[i].x;
			ty = y - pt[i].y;
			if (0 <= tx && 0 <= ty && tx <= pt[i].sz && ty <= pt[i].sz) {
				if (tx == 0 || ty == 0 || tx == pt[i].sz || ty == pt[i].sz) {
					red = green = blue = 0;
					return;
				}
				r += pt[i].r;
				g += pt[i].g;
				b += pt[i].b;
				++count;
			}
		}
	}

	if (count) {
		red   = double(r) / count;
		green = double(g) / count;
		blue  = double(b) / count;
	} else {
		red = green = blue = 255;
	}
}

void myscanf(int &x){
	int i, sgn = 0;

	while ((x = getchar()) != EOF && x != '-' && (x < '0' || x > '9'));
	if (x == '-') { sgn = 1; x = getchar(); }

	x -= '0';
	while ((i = getchar()) != EOF && '0' <= i && i <= '9') x = x * 10 + i - '0';
	if (sgn) x = -x;
}

int main() {
	int set, cs = 0, i, M, x, y;
	char str[16];

	scanf("%d", &set);
	while (set--) {
		scanf("%d%d", &N, &M);
		for (i = 0; i < N; ++i) {
			scanf("%s", str);
			if (str[0] == 'S' || str[0] == 's') pt[i].type = 's';
			else pt[i].type = 'c';
			myscanf(pt[i].x);
			myscanf(pt[i].y);
			myscanf(pt[i].sz);
			myscanf(pt[i].r);
			myscanf(pt[i].g);
			myscanf(pt[i].b);
		}

		printf("Case %d:\n", ++cs);
		while (M--) {
			scanf("%d%d", &x, &y);
			calcColor(x, y);
			printf("(%.0lf, %.0lf, %.0lf)\n", red + 1e-12, green + 1e-12, blue + 1e-12);
		}

		if (set) putchar('\n');
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
