/* @JUDGE_ID: 19899RK 428 C++ "By Anadan" */ 
// Swamp County Roofs
// Accepted (0.006 seconds with low memory spent)

#include <stdio.h>
#include <math.h>

int main(){
	int lots = 0, i;
	double lot_sz, a, b, h, fi, roof, flor, t_roof, t_flor, t_lot;
	const double pi_180 = acos(0.0) / 90.0;

	printf("Roof Area     Floor Area     %% Covered\n");
	printf("---------     ----------     ---------\n");
	t_roof = t_flor = t_lot = 0.0;
	while (scanf("%lf", &lot_sz) == 1){
		roof = flor = 0.0;

		while (scanf("%lf%lf%lf%lf", &a, &b, &h, &fi) == 4){
			h *= (a + b) * 0.5;
			roof += h;
			flor += h * cos(fi * pi_180);

			while ((i = getchar()) == ' ');
			if (i == '\n') while ((i = getchar()) == ' ');
			if (i == '\n' || i == EOF) break;
			ungetc(i, stdin);
		}

		t_roof += roof; t_flor += flor; t_lot += lot_sz; ++lots;
		printf("%9.2lf%15.2lf%13.2lf%%\n", roof, flor, flor / lot_sz * 100.0);
	}

	printf("\nTotal surface area of roofs %11.2lf\n", t_roof);
	printf("Total area covered by roofs %11.2lf\n", t_flor);
	printf("Percentage of total area covered by roofs %7.2lf%%\n", t_flor / t_lot * 100.0);
	printf("Average roof surface area per lot %15.2lf\n", t_roof / lots);
	printf("Average floor space covered per lot %13.2lf\n", t_flor / lots);

	return 0;
}
/* @END_OF_SOURCE_CODE */
