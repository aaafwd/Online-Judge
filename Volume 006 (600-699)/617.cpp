/* @JUDGE_ID: 19899RK 617 C++ "By Anadan" */ 
// Nonstop Travel
// Accepted (0.002 seconds with low memory spent)

#include <stdio.h>
#include <math.h>

struct Light{
	double L, G, R;
}pt[6];

int main(){
	int N, i, j, set = 0;
	char mask[61], solved;
	double t;

	while (scanf("%d\n", &N) == 1 && N != -1){
		for (i = 0; i < N; ++i){
			scanf("%lf%lf%lf%lf\n", &pt[i].L, &pt[i].G, &t, &pt[i].R);
			pt[i].G += t;
		}

		solved = 0;
		for (i = 30; i <= 60; ++i){
			for (j = 0; j < N; ++j){
				t = fmod(pt[j].L / double(i) * 3600.0, pt[j].G + pt[j].R);
				if (t > pt[j].G + 1e-12) break;
			}

			if (j < N) mask[i] = 0;
			else mask[i] = solved = 1;
		}

		printf("Case %d: ", ++set);
		if (solved){
			for (i = 30; i <= 60; ++i){
				if (!mask[i]) continue;
				for (j = i + 1; j <= 60; ++j) if (!mask[j]) break;
				--j;
				if (solved) solved = 0; else printf(", ");
				printf("%d", i);
				if (i != j) printf("-%d", j);
				i = j;
			}
			putchar('\n');
		}else printf("No acceptable speeds.\n");
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
