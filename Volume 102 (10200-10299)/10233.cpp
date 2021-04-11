/* @JUDGE_ID: 19899RK 10233 C++ "By Anadan" */
// Dermuba Triangle
// Accepted (0.006 seconds with low memory spent)

#include <stdio.h>
#include <math.h>

struct Point {
	double x, y;
};

const double coeff1 = sqrt(3) / 2;
const double coeff2 = coeff1 / 3;
const double coeff3 = coeff2 * 2;
inline double sqr(double x) { return x * x; }

Point getPoint(int N) {
	Point res;
	int line = int(floor(sqrt(N)));

	N -= line*line;
	res.x = coeff1 * line;
	if (N & 1) res.x += coeff2;
	else res.x += coeff3;
	res.y = (line - N)*0.5;

	return res;
}

int main() {
	int i, j;
	double res;

	while (scanf("%d%d", &i, &j) == 2) {
		Point p1 = getPoint(i);
		Point p2 = getPoint(j);
		res = sqrt(sqr(p1.x - p2.x) + sqr(p1.y - p2.y));
		printf("%.3lf\n", res);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
