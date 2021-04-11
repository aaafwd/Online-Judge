/* @JUDGE_ID: 19899RK 10385 C++ "By Anadan" */
// Duathlon
// Accepted (0.002 seconds with low memory spent)

#include <stdio.h>
#include <math.h>

struct People{
	double a, b;
}pt[20];
int N;
double margin, r_best;

void setmargin(double r){
	int i;
	double mint, tmp;

	mint = pt[0].a + pt[0].b * r;
	for (i = 1; i < N - 1; ++i){
		tmp = pt[i].a + pt[i].b * r;
		if (mint > tmp) mint = tmp;
	}

	tmp = pt[i].a + pt[i].b * r;
	if (mint < tmp - 1e-12) return;

	tmp = fabs(mint - tmp);
	if (margin == -1 || margin < tmp){
		margin = tmp;
		r_best = r;
	}
}

int main(){
	int t, i, j;
	double v1, v2;

	while (scanf("%d", &t) == 1){
		scanf("%d", &N);
		for (i = 0; i < N; ++i){
			scanf("%lf%lf", &v1, &v2);
			v1 /= 3600; v2 /= 3600;
			pt[i].a = t / v2;
			pt[i].b = 1 / v1 - 1 / v2;
		}

		margin = -1.0;
		setmargin(0);
		setmargin(t);
		for (i = 0; i < N; ++i){
			for (j = i + 1; j < N; ++j){
				if (fabs(pt[j].b - pt[i].b) < 1e-12) continue;
				v1 = (pt[i].a - pt[j].a) / (pt[j].b - pt[i].b);
				setmargin(v1);
			}
		}

		if (margin == -1) puts("The cheater cannot win.");
		else printf("The cheater can win by %.0lf seconds with r = %.2lfkm and k = %.2lfkm.\n", margin, r_best, t - r_best);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
