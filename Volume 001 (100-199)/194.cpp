/* @JUDGE_ID: 19899RK 194 C++ "By Anadan" */
// Triangle
// Accepted (0.020 seconds with low memory spent)

#include <stdio.h>
#include <math.h>

long double a, A, b, B, c, C;
const long double pi_2 = acos(0.0);
const long double pi = pi_2 * 2.0;
const long double eps = 0.00000001;

int func1(); int func2(); int func3();

int correct_angles(){
	int i = 0;

	if (A >= pi || B >= pi || C >= pi) return -1;
	if (A == 0.0 || B == 0.0 || C == 0.0) return -1;
	if (A > -0.5) ++i; if (B > -0.5) ++i; if (C > -0.5) ++i;
	if (i == 3 && fabs(A + B + C - pi) > eps * 3.0) return -1;

	if (i == 2){
		if (A < -0.5) A = pi - B - C;
		else if (B < -0.5) B = pi - A - C;
		else C = pi - A - B;
		return 3;
	}

	return i;
}

int func1(){
	long double tmp;
	if (correct_angles() <= 1) return 1;

	if (a > -0.5){
		if (B <= 0.0 || C <= 0.0) return 1;
		tmp = a / sin(A);
		b = tmp * sin(B);
		c = tmp * sin(C);
	}else if (b > -0.5){
		if (A <= 0.0 || C <= 0.0) return 1;
		tmp = b / sin(B);
		a = tmp * sin(A);
		c = tmp * sin(C);
	}else{
		if (A <= 0.0 || B <= 0.0) return 1;
		tmp = c / sin(C);
		a = tmp * sin(A);
		b = tmp * sin(B);
	}

	return 0;
}

int func2(){
	long double tmp;

func2_begin:

	if (correct_angles() <= 0) return 1;
	if (a > -0.5){
		if (b > -0.5){
			if (C < -0.5){
				if (B >= 0.0){
					tmp = sin(B) * a / b;
					if (fabs(tmp) > 1.0) return 1;
					if (tmp == 0.0) return 1;
					tmp = asin(tmp);
					if (fabs(tmp - pi_2) < eps){
						A = pi_2;
						C = pi_2 - B;
						c = sqrt(a*a - b*b);
					}else{
						A = tmp;
						if (B < A) return -1;
						C = pi - A - B;
						goto func2_begin;
					}
				}else{
					tmp = sin(A) * b / a;
					if (fabs(tmp) > 1.0) return 1;
					if (tmp == 0.0) return 1;
					tmp = asin(tmp);
					if (fabs(tmp - pi_2) < eps){
						B = pi_2;
						C = pi_2 - A;
						c = sqrt(b*b - a*a);
					}else{
						B = tmp;
						if (A < B) return -1;
						C = pi - A - B;
						goto func2_begin;
					}
				}
			}else{
				c = sqrt(a*a + b*b - 2.0*a*b*cos(C));
				if (c < eps) return 1;
			}
		}else{
			if (B < -0.5){
				if (C >= 0.0){
					tmp = sin(C) * a / c;
					if (fabs(tmp) > 1.0) return 1;
					if (tmp == 0.0) return 1;
					tmp = asin(tmp);
					if (fabs(tmp - pi_2) < eps){
						A = pi_2;
						B = pi_2 - C;
						b = sqrt(a*a - c*c);
					}else{
						A = tmp;
						if (C < A) return -1;
						B = pi - A - C;
						goto func2_begin;
					}
				}else{
					tmp = sin(A) * c / a;
					if (fabs(tmp) > 1.0) return 1;
					if (tmp == 0.0) return 1;
					tmp = asin(tmp);
					if (fabs(tmp - pi_2) < eps){
						C = pi_2;
						B = pi_2 - A;
						b = sqrt(c*c - a*a);
					}else{
						C = tmp;
						if (A < C) return -1;
						B = pi - A - C;
						goto func2_begin;
					}
				}
			}else{
				b = sqrt(a*a + c*c - 2.0*a*c*cos(B));
				if (b < eps) return 1;
			}
		}
	}else{
		if (A < -0.5){
			if (C >= 0.0){
				tmp = sin(C) * b / c;
				if (fabs(tmp) > 1.0) return 1;
				if (tmp == 0.0) return 1;
				tmp = asin(tmp);
				if (fabs(tmp - pi_2) < eps){
					B = pi_2;
					A = pi_2 - C;
					a = sqrt(b*b - c*c);
				}else{
					B = tmp;
					if (C < B) return -1;
					A = pi - B - C;
					goto func2_begin;
				}
			}else{
				tmp = sin(B) * c / b;
				if (fabs(tmp) > 1.0) return 1;
				if (tmp == 0.0) return 1;
				tmp = asin(tmp);
				if (fabs(tmp - pi_2) < eps){
					C = pi_2;
					A = pi_2 - B;
					a = sqrt(c*c - b*b);
				}else{
					C = tmp;
					if (B < C) return -1;
					A = pi - B - C;
					goto func2_begin;
				}
			}
		}else{
			a = sqrt(b*b + c*c - 2.0*b*c*cos(A));
			if (a < eps) return 1;
		}
	}

	return func3();
}

int func3(){
	long double tmp;

	tmp = (b*b + c*c - a*a) / (2.0 * b * c);
	if (fabs(tmp) >= 1.0) return 1;
	tmp = acos(tmp);
	if (A > -0.5 && fabs(tmp - A) > eps) return 1;
	A = tmp;

	tmp = (a*a + c*c - b*b) / (2.0 * a * c);
	if (fabs(tmp) >= 1.0) return 1;
	tmp = acos(tmp);
	if (B > -0.5 && fabs(tmp - B) > eps) return 1;
	B = tmp;

	tmp = (a*a + b*b - c*c) / (2.0 * a * b);
	if (fabs(tmp) >= 1.0) return 1;
	tmp = acos(tmp);
	if (C > -0.5 && fabs(tmp - C) > eps) return 1;
	C = tmp;

	return 0;
}

int main(){
	int tmp, set;

	scanf("%d\n", &set);
	while (set--){
		scanf("%Lf%Lf%Lf%Lf%Lf%Lf", &a, &A, &b, &B, &c, &C);
		tmp = 0;
		if (a > -0.5) tmp++;
		if (b > -0.5) tmp++;
		if (c > -0.5) tmp++;

		switch (tmp){
			case 1: tmp = func1(); break;
			case 2: tmp = func2(); break;
			case 3: tmp = func3(); break;
			default: tmp = 1; break;
		}

		if (tmp > 0) printf("Invalid input.\n");
		else if (tmp < 0) printf("More than one solution.\n");
		else printf("%.6Lf %.6Lf %.6Lf %.6Lf %.6Lf %.6Lf\n", a, A, b, B, c, C);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
