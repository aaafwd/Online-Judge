/* @JUDGE_ID: 19899RK 10203 C++ "By Anadan" */ 
// Snow Clearing
// Accepted (0.002 seconds with low memory spent)

#include <stdio.h>
#include <math.h>

int main(){
	int set, it;
	double t, x1, y1, x2, y2;
	char str[81];

	scanf("%d\n\n", &set);
	while (set--){
		t = 0.0;
		scanf("%*d%*d"); gets(str);
		while (gets(str) && sscanf(str, "%lf%lf%lf%lf", &x1, &y1, &x2, &y2) == 4){
			t += sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
		}

		t *= 0.006;
		it = (int)floor(t + 0.5);

		printf("%d:%.2d\n", it / 60, it % 60);
		if (set) putchar('\n');
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
