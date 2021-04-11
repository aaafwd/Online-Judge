/* @JUDGE_ID: 19899RK 10713 C++ "By Anadan" */
// Map
// Accepted (0.008 seconds with low memory spent)

#include <stdio.h>
#include <math.h>

const double eps = 1e-12;
double r, x1, yy1, x2, y2, x3, y3, res;
int o_dir1, o_dir2;
char output[1024];

const double vdx[] = {0,0,1,-1,1,-1,-1,1};
const double vdy[] = {1,-1,0,0,1,-1,1,-1};
const char *direction[] = { "north", "south", "east", "west",
"northeast", "southwest", "northwest", "southeast" };

inline double dist(double a1, double b1, double a2, double b2) {
	return sqrt((a2-a1)*(a2-a1) + (b2-b1)*(b2-b1));
}

int intersect(double x1, double yy1, int dir1, double x2, double y2, int dir2) {
	double det = -vdx[dir1]*vdy[dir2] + vdx[dir2]*vdy[dir1];
	double it1 = -(x2-x1)*vdy[dir2] + vdx[dir2]*(y2-yy1);
	double it2 = -vdx[dir1]*(y2-yy1) + (x2-x1)*vdy[dir1];

	if (fabs(det) < eps) return 0;
	if (det < 0) {
		det = -det; it1 = -it1; it2 = -it2;
	}

	o_dir1 = dir1;
	if (it1 < 0) o_dir1 ^= 1;

	o_dir2 = dir2;
	if (it2 < 0) o_dir2 ^= 1;

	x3 = x1 + vdx[dir1]*it1/det;
	y3 = yy1 + vdy[dir1]*it1/det;

	return 1;
}

void solve(int dir) {
	int j;
	double tmp, d1, d2;

	for (j = 0; j < 8; ++j) {
		if (!intersect(x1, yy1, dir, x2, y2, j)) continue;
		if (x3*x3 + y3*y3 <= r*r + eps) {
			d1 = dist(x1, yy1, x3, y3);
			d2 = dist(x2, y2, x3, y3);
			tmp = d1 + d2;
			if (res < 0 || res > tmp) {
				res = tmp;
				sprintf(output, "%s %.10lf\n%s %.10lf", direction[o_dir1], d1, direction[o_dir2], d2);
			}
		}
	}
}

int main() {
	int i, set = 0;
	double dx, dy;

	while (scanf("%lf%lf%lf%lf%lf", &r, &x1, &yy1, &x2, &y2) == 5 && r >= -0.1) {
		if (set++) putchar('\n');

		dx = x2-x1;
		dy = y2-yy1;
		if (fabs(dy) < eps) {
			if (dx > 0) printf("east %.10lf\n", dx);
			else printf("west %.10lf\n", -dx);
			continue;
		}
		if (fabs(dx) < eps) {
			if (dy > 0) printf("north %.10lf\n", dy);
			else printf("south %.10lf\n", -dy);
			continue;
		}
		if (fabs(dx-dy) < eps) {
			if (dx > 0) printf("northeast %.10lf\n", sqrt(2.0)*dx);
			else printf("southwest %.10lf\n", -sqrt(2.0)*dx);
			continue;
		}
		if (fabs(dx+dy) < eps) {
			if (dx > 0) printf("southeast %.10lf\n", sqrt(2.0)*dx);
			else printf("northwest %.10lf\n", -sqrt(2.0)*dx);
			continue;
		}

		res = -1;
		for (i = 0; i < 8; ++i) {
			solve(i);
		}
		puts(output);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
