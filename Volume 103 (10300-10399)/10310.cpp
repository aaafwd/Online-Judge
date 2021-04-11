/* @JUDGE_ID: 19899RK 10310 C++ "By Anadan" */ 
// Dog and Gopher
// Accepted (0.029 seconds with low memory spent)

#include <stdio.h>

inline double sqr(double x) { return x * x; }

int main(){
	int N, i;
	double x_gop, y_gop, x_dog, y_dog, x, y, tmp;

	while (scanf("%d\n", &N) == 1){
		scanf("%lf%lf%lf%lf\n", &x_gop, &y_gop, &x_dog, &y_dog);
		for (i = 0; i < N; ++i){
			scanf("%lf%lf\n", &x, &y);
			tmp = 4.0 * (sqr(x_gop - x) + sqr(y_gop - y)) - sqr(x_dog - x) - sqr(y_dog - y);
			if (tmp < 1e-10){
				printf("The gopher can escape through the hole at (%.3lf,%.3lf).\n", x, y);
				break;
			}
		}

		if (i < N) for (++i; i < N; ++i) scanf("%lf%lf\n", &x, &y);
		else printf("The gopher cannot escape.\n");
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
