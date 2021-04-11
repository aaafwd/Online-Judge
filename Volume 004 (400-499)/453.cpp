/* @JUDGE_ID: 19899RK 453 C++ "By Anadan" */
// Intersecting Circles
// Accepted (0.230 seconds using as much as 408 kbytes)

#include <stdio.h>
#include <math.h>

int intersect_circle(long double x1, long double y1, long double r1,
		     long double x2, long double y2, long double r2, long double *solves)
{
	long double A, B, C, R, x, y;
	const long double EPS = 1e-10;

	if (x1 == x2 && y1 == y2){
		if (r1 == r2){
			if (r1 == 0.0){
				solves[0] = x1;
				solves[1] = y1;
				return 1;
			}
			return -1;
		}
		return 0;
	}

	A = (x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2);
	if (r1 == 0.0){
		if (fabs(A - r2*r2) < EPS){
			solves[0] = x1;
			solves[1] = y1;
			return 1;
		}
		return 0;
	}

	if (r2 == 0.0){
		if (fabs(A - r1*r1) < EPS){
			solves[0] = x2;
			solves[1] = y2;
			return 1;
		}
		return 0;
	}

	R = 0.5 * (r2*r2 - r1*r1 + x1*x1 + y1*y1 - x2*x2 - y2*y2);
	B = (y1 - y2)*R + (x1 - x2) * ((x1 - x2)*y1 - (y1 - y2)*x1);
	C = (R - (x1 - x2)*x1)*(R - (x1 - x2)*x1) + (x1 - x2)*(x1 - x2)*(y1*y1 - r1*r1);

	C = B*B - A*C;
	if (C < -EPS) return 0;
	if (C < EPS){
		if (fabs(x1 - x2) < 1e-8){
			y = solves[1] = solves[3] = B / A;
			C = r1*r1 - (y - y1)*(y - y1);
			if (C < -EPS) return 0;
			if (C < EPS){
				solves[0] = x1;
				return 1;
			}
			solves[0] = x1 - sqrt(C);
			solves[2] = x1 + sqrt(C);
			return 2;
		}
		C = 0.0;
	}

	y = solves[1] = (B - sqrt(C)) / A;
	solves[0] = (R - (y1 - y2)*y) / (x1 - x2);
	y = (B + sqrt(C)) / A;
	x = (R - (y1 - y2)*y) / (x1 - x2);

	if (solves[0] > x + EPS){
		solves[2] = solves[0];
		solves[3] = solves[1];
		solves[0] = x;
		solves[1] = y;
	}else{
		solves[2] = x;
		solves[3] = y;
	}

	return 2;
}

int correctit(int i, long double *solves){
	if (i < 1) return i;
	solves[0] *= 1000.0;
	solves[0] = (floor(solves[0] + 0.5)) * 0.001;
	solves[1] *= 1000.0;
	solves[1] = (floor(solves[1] + 0.5)) * 0.001;
	if (i == 1) return 1;
	solves[2] *= 1000.0;
	solves[2] = (floor(solves[2] + 0.5)) * 0.001;
	solves[3] *= 1000.0;
	solves[3] = (floor(solves[3] + 0.5)) * 0.001;
	if (fabs(solves[0] - solves[2]) < 1e-5 && fabs(solves[1] - solves[3]) < 1e-5){
		return 1;
	}
	return 2;
}

int main(){
	int i;
	long double x1, y1, r1, x2, y2, r2, solves[4];

	while(scanf("%Lf%Lf%Lf%Lf%Lf%Lf", &x1, &y1, &r1, &x2, &y2, &r2) == 6){
		i = intersect_circle(x1, y1, r1, x2, y2, r2, solves);
		i = correctit(i, solves);
		if (i == -1) printf("THE CIRCLES ARE THE SAME\n");
		else if (i == 0) printf("NO INTERSECTION\n");
		else if (i == 1) printf("(%.3Lf,%.3Lf)\n", solves[0], solves[1]);
		else printf("(%.3Lf,%.3Lf)(%.3Lf,%.3Lf)\n", solves[0], solves[1], solves[2], solves[3]);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
