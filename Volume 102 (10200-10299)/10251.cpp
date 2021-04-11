/* @JUDGE_ID: 19899RK 10251 C++ "By Anadan" */ 
// Min-Max Cake
// Accepted (0.002 seconds with low memory spent)

#include <stdio.h>
#include <math.h>

int main(){
	int set, ret;
	double L, H, dx, dy, min, tmp;
	char str[256];

	scanf("%d\n", &set);
	while (set--){
		gets(str);
		ret = sscanf(str, "%lf%lf%lf%lf", &L, &H, &dx, &dy);

		if (ret == 3){
			L = (acos(dx / L) * L * L - sqrt(L*L - dx*dx) * dx) * H;
			printf("%.3lf\n", L);
		}else if (ret == 4){
			if (dx < 0) dx = -dx;
			if (dy < 0) dy = -dy;

			min = (L * 0.5 - dx) * L;
			tmp = (L * 0.5 - dy) * L;
			if (min > tmp) min = tmp;
			tmp = (L - dx - dy) * (L - dx - dy) * 0.5;
			if (min > tmp) min = tmp;

			printf("%.3lf\n", min * H);

		}else while(1);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
