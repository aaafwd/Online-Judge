/* @JUDGE_ID: 19899RK 10466 C++ "By Anadan" */ 
// How Far?
// Accepted (0.143 seconds using as much as 400 kbytes)

#include <stdio.h>
#include <math.h>

struct Body{
	double r, t, x, y;
}pt[50];

void myscanf(int &x){
	int i;

	while ((x = getchar()) != EOF && (x < '0' || x > '9'));
	x -= '0';
	while ((i = getchar()) != EOF && '0' <= i && i <= '9'){
		x = x * 10 + i - '0';
	}
}

int main(){
	int N, i, j;
	double T, a;
	const double pi2 = acos(0.0) * 4.0;

	while (scanf("%d%d\n", &N, &j) == 2){
		T = j;
		for (i = 0; i < N; ++i){
			myscanf(j); pt[i].r = j;
			myscanf(j); pt[i].t = j;
		}
		a = pi2 * T / pt[0].t;
		pt[0].x = pt[0].r * cos(a);
		pt[0].y = pt[0].r * sin(a);
		printf("%.4lf", pt[0].r);

		for (i = 1; i < N; ++i){
			a = pi2 * T / pt[i].t;
			pt[i].x = pt[i - 1].x + pt[i].r * cos(a);
			pt[i].y = pt[i - 1].y + pt[i].r * sin(a);
			printf(" %.4lf", sqrt(pt[i].x*pt[i].x + pt[i].y*pt[i].y));
		}

		putchar('\n');
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
