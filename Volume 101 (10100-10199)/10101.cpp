/* @JUDGE_ID: 19899RK 10101 C++ "By Anadan" */
// Bangla Numbers
// Accepted (0.180 seconds using as much as 396 kbytes)

#include <stdio.h>
#include <math.h>

int func(double d, int flag = 0){
	double tmp;

	tmp = floor(d / 10000000.0);
	if (tmp > 10e-12){
		if (flag) printf(" "); else flag = 1;
		printf("%.0lf kuti", tmp);
	}
	d = fmod(d, 10000000.0);

	tmp = floor(d / 100000.0);
	if (tmp > 10e-12){
		if (flag) printf(" "); else flag = 1;
		printf("%.0lf lakh", tmp);
	}
	d = fmod(d, 100000.0);

	tmp = floor(d / 1000.0);
	if (tmp > 10e-12){
		if (flag) printf(" "); else flag = 1;
		printf("%.0lf hajar", tmp);
	}
	d = fmod(d, 1000.0);

	tmp = floor(d / 100.0);
	if (tmp > 10e-12){
		if (flag) printf(" "); else flag = 1;
		printf("%.0lf shata", tmp);
	}
	d = fmod(d, 100.0);
	if (d > 10e-12){
		if (flag) printf(" "); else flag = 1;
		printf("%.0lf", d);
	}
	return flag;
}

int main(){
	int set = 0, flag1, flag2;
	double d1, d2, tmp;

	while (scanf("%lf", &d2) > 0){
		printf("%4d. ", ++set);
		flag1 = func(floor(d2 / 10000000.0), 0);
		if (flag1) printf(" kuti");
		d2 = fmod(d2, 10000000.0);
		flag2 = func(d2, flag1);
		if (flag1 == 0 && flag2 == 0) printf("0");
		printf("\n");
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
