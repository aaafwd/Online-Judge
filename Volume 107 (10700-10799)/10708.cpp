/* @JUDGE_ID: 19899RK 10708 C++ "By Anadan" */
// Cheetah
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>
#include <math.h>

int main() {
	int set, Cx, Cy, Px, Py, U, V, L;
	const double pi = acos(0) * 2;
	const double pi_180 = pi / 180;
	double a, w, f1, f2, tmp, C, T, X, Y, P;

	scanf("%d", &set);
	while (set--) {
		scanf("%d%d%d%d%lf%d%d%d", &Cx, &Cy, &Px, &Py, &P, &U, &V, &L);
		P *= pi_180;

		w = ((Py - Cy) * cos(P) + (Cx - Px) * sin(P)) * U / double(V);
		a = sqrt((Cx-Px)*(Cx-Px) + (Py-Cy)*(Py-Cy));

		if (fabs(w) > a - 1e-8 || fabs(Py-Cy) > a - 1e-8) {
			puts("sorry, buddy");
			continue;
		} else {
			f1 = asin(w/a);
			f2 = atan2(Py-Cy, Cx-Px);

			C = pi - f1 - f2;
			if (C < 0) C += pi+pi;
		}

		tmp = sqrt(V*V + U*U - 2.0*V*U*cos(C-P));
		if (fabs(tmp) < 1e-8) { puts("sorry, buddy"); continue; }
		T = a / tmp;
		if (T > L - 1e-8) { puts("sorry, buddy"); continue; }

		tmp = T*V;
		X = Cx + tmp*cos(C);
		Y = Cy + tmp*sin(C);

		tmp = T*U;
		f1 = Px + tmp*cos(P);
		f2 = Py + tmp*sin(P);

		if (fabs(X-f1) > 1e-8 || fabs(Y-f2) > 1e-8) {
			puts("sorry, buddy");
		} else {
			C /= pi_180;
			if (fabs(C) < 0.005 - 1e-12) C = 0;
			printf("%.2lf %.2lf %.2lf %.2lf\n", C, T, X, Y);
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
