/* @JUDGE_ID: 19899RK 427 C++ "By Anadan" */ 
// FlatLand Piano Movers
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>
#include <math.h>

inline double pow3(double x) { return x * x * x; }

int main(){
	int off, h, w, a, b, d;
	char str[81], *p;
	double e1, e2, e, tmp;
	const double pi_2 = acos(0.0), eps = 1e-10;

	while (gets(str) && sscanf(str, "%d,%d%n", &h, &w, &off) == 2){
		if (h < w) h ^= w ^= h ^= w;
		d = (int)ceil(sqrt(1.0*h*h + 1.0*w*w));
		p = str + off;
		while (sscanf(p, "%d,%d%n", &a, &b, &off) == 2){
			p += off;
			if (a < w || b < w){
				putchar('N');
				continue;
			}else if (a >= d){
				putchar('Y');
				continue;
			}

			e1 = 0.0; e2 = pi_2;
			while (e2 - e1 > eps){
				e = (e1 + e2) * 0.5;
				tmp = pow3(cos(e))*h + sin(e)*w - a;
				if (tmp > 0) e1 = e; else e2 = e;
			}

			tmp = sin(e)*h + (w - sin(e)*a) / cos(e);
			if (tmp <= b + eps) putchar('Y'); else putchar('N');
		}

		putchar('\n');
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
