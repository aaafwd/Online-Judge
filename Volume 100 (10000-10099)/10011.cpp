/* @JUDGE_ID: 19899RK 10011 C++ "By Anadan" */ 
// Where Can You Hide?
// Accepted (0.221 seconds using as much as 396 kbytes)

#include <stdio.h>
#include <math.h>

inline double sqr (double x) { return x * x; }

void myscanf(double &x){
	int i, sgn = 0;
	double y;

	while ((i = getchar()) != EOF && i != '.' && i != '-' && (i < '0' || i > '9'));
	if (i == '-'){
		sgn = 1;
		i = getchar();
	}

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

	if (sgn) x = -x;
}

int main(){
	int set;
	double x, y, r, l, u, v, x1, y1, x2, y2, t1, t2, res;

	scanf("%d\n\n", &set);
	while (set--){
		myscanf(x); myscanf(y); myscanf(r); myscanf(u); myscanf(v);

		l = sqrt(x * x + y * y);
		t1 = sqrt(1.0 - r * r / (x * x + y * y));
		t2 = r / l;

		x1 = t1 * x + t2 * y;
		y1 = -t2 * x + t1 * y;
		x2 = t1 * x - t2 * y;
		y2 = t2 * x + t1 * y;

		t1 = u * y1 - v * x1;
		t2 = u * y2 - v * x2;

		if (fabs(t1) < 1e-12 || fabs(t2) < 1e-12 || t1 > 0 ||
		    u * u + v * v <= l * l - r * r + 1e-12 || t2 < 0){
			puts("0.000");
			continue;
		}

		res = sqrt(sqr(x - u) + sqr(y - v)) - r;
		if (fabs(res) < 1e-12){
			puts("0.000");
			continue;
		}

		t1 = 1.0 / sqrt(x1 * x1 + y1 * y1);
		x1 *= t1; y1 *= t1;
		x2 *= t1; y2 *= t1;

		t1 = sqrt(u * u + v * v - sqr(u * x1 + v * y1));
		t2 = sqrt(u * u + v * v - sqr(u * x2 + v * y2));

		if (res > t1) res = t1;
		if (res > t2) res = t2;

		printf("%.3lf\n", res);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
