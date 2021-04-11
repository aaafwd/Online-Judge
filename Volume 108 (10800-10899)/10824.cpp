/* @JUDGE_ID: 19899RK 10824 C++ "By Anadan" */
// Regular Polygon
// Accepted (0.145 seconds using as much as 448 kbytes)

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define EPS 1e-8

double angle[2000];

int sort_function(const void *a, const void *b) {
	if (fabs(*(double *)a - *(double *)b) < EPS) return 0;
	if (*(double *)a < *(double *)b) return -1;
	return 1;
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
	int set = 0, i, j, k, low, N, res;
	double x, y, limit, tmp, *ptr;
	const double pi2 = acos(0) * 4;

	while (scanf("%d", &N) == 1 && N) {
		for (i = 0; i < N; ++i) {
			myscanf(x); myscanf(y);
			// scanf("%lf%lf", &x, &y);
			angle[i] = atan2(y, x);
			if (fabs(angle[i]) < EPS) angle[i] = 0;
			else if (angle[i] < 0) angle[i] += pi2;
		}
		qsort(angle, N, sizeof(double), sort_function);

		printf("Case %d:\n", ++set);
		res = 0;
		for (i = 3; i <= N; ++i) {
			res = 0;
			limit = pi2 / i;
			for (j = 0; j < N; ++j) {
				if (angle[j] > limit - EPS) break;

				low = j;
				tmp = angle[j];
				for (k = 1; k < i; ++k) {
					tmp += limit;
					ptr = (double*)bsearch(&tmp, angle+low, N-low, sizeof(double), sort_function);
					if (!ptr) break;
					low = ptr - angle;
				}
				if (k == i) ++res;
			}
			if (res) printf("%d %d\n", i, res);
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
