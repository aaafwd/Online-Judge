/* @JUDGE_ID: 19899RK 10316 C++ "By Anadan" */ 
// Airline Hub
// Accepted (1.248 seconds using as much as 432 kbytes)

#include <stdio.h>
#include <math.h>

struct Point{
	double a, b, x, y, z;
}pt[1000];

int main(){
	int N, i, j, k;
	double min, curr, tmp;
	const double coeff = acos(0.0) / 90.0;

	while (scanf("%d\n", &N) == 1){
		for (i = 0; i < N; ++i){
			scanf("%lf%lf", &pt[i].a, &pt[i].b);
			pt[i].x = cos(coeff * pt[i].a);
			pt[i].y = pt[i].x * sin(coeff * pt[i].b);
			pt[i].x *= cos(coeff * pt[i].b);
			pt[i].z = sin(coeff * pt[i].a);
		}

		k = -1;
		for (i = N - 1; i >= 0; --i){
			curr = -1.0;
			for (j = 0; j < N; ++j){
				tmp = acos(pt[i].x * pt[j].x + pt[i].y * pt[j].y + pt[i].z * pt[j].z);
				if (curr < tmp) curr = tmp;
			}

			if (k == -1 || min > curr + 1e-12){
				min = curr;
				k = i;
			}
		}

		printf("%.2lf %.2lf\n", pt[k].a, pt[k].b);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
