/* @JUDGE_ID: 19899RK 10481 C++ "By Anadan" */ 
// The Gift Wrappers of Hollywood
// Accepted (0.016 seconds with low memory spent)

#include <stdio.h>
#include <math.h>

void myscanf(double &x){
	int i;
	double y;

	while ((i = getchar()) != EOF && i != '.' && (i < '0' || i > '9'));
	if (i != '.'){
		x = i - '0';
		while ((i = getchar()) != EOF && i != '.' && '0' <= i && i <= '9'){
			x = x * 10 + i - '0';
		}
	}else x = 0.0;

	if (i == '.'){
		y = 0.1;
		while ((i = getchar()) != EOF && '0' <= i && i <= '9'){
			x += y * (i - '0');
			y *= 0.1;
		}
	}
}

int main(){
	int set, i;
	double L;
	const double coeff = sqrt(4.0 / sqrt(3.0));
	const double r4  = 0.9805979290912716891;
	const double r11 = 1.4845015099848237592;

	scanf("%d", &set);
	for (i = 1; i <= set; ++i){
		myscanf(L);
		L = coeff * sqrt(L);
		printf("Case %d: %.12lf %.12lf\n", i, L * r4, L * r11);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
