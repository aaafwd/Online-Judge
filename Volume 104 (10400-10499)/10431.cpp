/* @JUDGE_ID: 19899RK 10431 C++ "By Anadan" */ 
// Normal Distribution
// Accepted (0.119 seconds using as much as 396 kbytes)

#include <stdio.h>
#include <math.h>

const double p = 0.2316419;
const double b[] = { 1.330274429, -1.821255978, 1.781477937, -0.356563782, 0.319381530 };
const double sqrt1_2pi = sqrt(0.25 / acos(0.0));

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
	int set = 0, N, M, i;
	double x, sx, sxx, q, t;

	while (scanf("%d\n", &N) == 1){
		sx = sxx = 0.0;
		for (i = 0; i < N; ++i){
			myscanf(x);
			sx += x;
			sxx += x * x;
		}

		sx /= N;
		sxx = sqrt((sxx - sx * sx * N) / (N - 1));

		if (set) putchar('\n');
		printf("Data Set #%d\nMean = %.4lf\nStandard Deviation = %.4lf\n", ++set, sx, sxx);

		scanf("%d\n", &M);
		while (M--){
			myscanf(x);
			x = (x - sx) / sxx;
			if (x < 0) x = -x;
			q = 0.0;
			t = 1.0 / (1.0 + p * x);
			for (i = 0; i < 5; ++i) q = (q + b[i]) * t;
			q *= sqrt1_2pi * exp(-x*x*0.5);
			printf("P(z) = %.4lf, Q(z) = %.4lf, T = %.4lf\n", 1.0 - q, q, q * N);
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
