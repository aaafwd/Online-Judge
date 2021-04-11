/* @JUDGE_ID: 19899RK 10355 C++ "By Anadan" */
// Superman
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>
#include <math.h>

long x1, y1, z1, x2, y2, z2, x, y, z, r, A;

double getpercent(){
	long B, C, D;
	double t1, t2;

	C = (x1 - x)*(x1 - x) + (y1 - y)*(y1 - y) + (z1 - z)*(z1 - z) - r*r;
	if (A){
		B = (x2 - x1)*(x1 - x) + (y2 - y1)*(y1 - y) + (z2 - z1)*(z1 - z);
		D = B*B - A*C;
		if (D <= 0) return 0.0;
		t2 = sqrt(D) / double(A);
		t1 = -double(B) / double(A) - t2;
		t2 -= double(B) / double(A);
		if (t2 <= 0.0) return 0.0;
		if (t2 <= 1.0){
			if (t1 <= 0.0) return t2;
			return t2 - t1;
		}else{
			if (t1 <= 0.0) return 1.0;
			if (t1 <= 1.0) return 1.0 - t1;
			return 0.0;
		}
	}else{
		if (C <= 0) return 1.0;
		return 0.0;
	}
}

int main(){
	long N, i;
	double t;
	char str[10];

	while (scanf("%s\n", str) == 1){
		scanf("%ld%ld%ld%ld%ld%ld%ld", &x1, &y1, &z1, &x2, &y2, &z2, &N);
		t = 0.0;
		A = (x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1) + (z2 - z1)*(z2 - z1);
		for (i = 0; i < N; ++i){
			scanf("%ld%ld%ld%ld", &x, &y, &z, &r);
			t += getpercent();
		}

		printf("%s\n%.2lf\n", str, t * 100.0);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
