/* @JUDGE_ID: 19899RK 588 C++ "By Anadan" */
// Video Surveillance
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>

int main(){
	long n, x0, y0, x, y, i;
	long xl, xr, yt, yb, set = 0, xs, ys;
	char inf1, inf2, inf3, inf4;

	while (scanf("%ld", &n) == 1){
		if (n == 0) break;
		scanf("%ld%ld", &x0, &y0);
		xs = x0; ys = y0;
		xl = xr = yt = yb = -1;
		inf1 = inf2 = inf3 = inf4 = 1;
		for (i = 1; i <= n; ++i){
			if (i == n) x = xs, y = ys;
			else scanf("%ld%ld", &x, &y);
			if (x0 == x){
				if (y0 < y){
					if (inf1 == 1) xl = x, inf1 = 0;
					else if (xl < x) xl = x;
				}else{
					if (inf2 == 1) xr = x, inf2 = 0;
					else if (xr > x) xr = x;
				}
			}else{
				if (x0 < x){
					if (inf3 == 1) yt = y, inf3 = 0;
					else if (yt > y) yt = y;
				}else{
					if (inf4 == 1) yb = y, inf4 = 0;
					else if (yb < y) yb = y;
				}
			}

			x0 = x; y0 = y;
		}

		printf("Floor #%ld\n", ++set);
		if (xr >= xl && yt >= yb) printf("Surveillance is possible.\n\n");
		else printf("Surveillance is impossible.\n\n");
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
