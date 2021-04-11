/* @JUDGE_ID: 19899RK 10468 C++ "By Anadan" */ 
// Rigid Circle Packing
// Accepted (0.066 seconds with low memory spent)

#include <stdio.h>
#include <math.h>

int myscanf(double &x){
	int i;
	double y;

	while ((i = getchar()) != EOF && i != '.' && (i < '0' || i > '9'));
	if (i == EOF) return 0;
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

	return 1;
}

void myprintf(double x){
	int y, i;
	char str[35], *p = str + 27, *q = p + 1;

	if (x < 0.000005){
		printf("0.00000");
	}else{
		x = floor(x * 100000 + 0.5) * 0.00001;
		y = (int)floor(x);
		x -= y;

		*q++ = '.';
		for (i = 0; i < 5; ++i){
			x *= 10;
			*q++ = ((int)floor(x + 1e-12)) + '0';
			x -= floor(x);
		}
		*q = 0;

		if (y == 0) *p-- = '0';
		while (y){
			*p-- = '0' + (y % 10);
			y /= 10;
		}

		printf(p + 1);
	}
}

int main(){
	double r;
	const double pi = acos(0.0) * 2.0;
	const double a = acos((2.0 * (1.0 - sin(pi / 12.0)) - sqrt(2.0)) / sqrt(12.0 - 4.0 * sqrt(2.0)));
	const double b = acos(sqrt(12.0 - 4.0 * sqrt(2.0)) / 4);
	const double c9 = 3.0 + sqrt(2.0) + sqrt(1.5) + sqrt(0.5 + sqrt(2.0));
	const double c10 = 6.0 + 2 * cos(pi - a - b);

	while (myscanf(r)){
		myprintf(c9 * r);
		putchar(' ');
		myprintf(c10 * r);
		putchar('\n');
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
