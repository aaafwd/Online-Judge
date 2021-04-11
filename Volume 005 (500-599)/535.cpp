/* @JUDGE_ID: 19899RK 535 C++ "By Anadan" */
// Globetrotter
// Accepted (0.076 seconds with low memory spent)

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct City{
	char name[31];
	double x, y, z;
}pt[101];

const double R = 6378.0;

int sort_function(const void *a, const void *b){
	return strcmp(((City *)a)->name, ((City *)b)->name);
}

int main(){
	int N = 0;
	double a, b;
	const double coeff = 3.141592653589793 / 180.0;
	City c1, c2, *p1, *p2;

	while (scanf("%s", pt[N].name) == 1 && pt[N].name[0] != '#'){
		scanf("%lf%lf\n", &a, &b);
		a *= coeff; b *= coeff;
		pt[N].x = cos(a) * cos(b);
		pt[N].y = cos(a) * sin(b);
		pt[N].z = sin(a);
		++N;
	}

	qsort(pt, N, sizeof(City), sort_function);

	while (scanf("%s%s", c1.name, c2.name) == 2){
		if (!strcmp(c1.name, "#") && !strcmp(c2.name, "#")) break;
		printf("%s - %s\n", c1.name, c2.name);
		p1 = (City *)bsearch(&c1, pt, N, sizeof(City), sort_function);
		p2 = (City *)bsearch(&c2, pt, N, sizeof(City), sort_function);
		if (p1 && p2){
			a = p1->x * p2->x + p1->y * p2->y + p1->z * p2->z;
			if (fabs(a) < 1e-12) a = 0.0;
			if (fabs(a - 1.0) < 1e-12) a = 1.0;
			printf("%.0lf km\n", acos(a) * R);
		}else printf("Unknown\n");
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
