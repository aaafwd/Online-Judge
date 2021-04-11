/* @JUDGE_ID: 19899RK 10090 C++ "By Anadan" */ 
// Marbles
// Accepted (0.096 seconds with low memory spent)

#include <stdio.h>

typedef long long qword;

qword N, c1, n1, c2, n2, a, b, d;

void do_euclid(){
	qword n = n1, m = n2, p = 1, q = 0, r = 0, s = 1;

	while (n && m){
		if (n > m){
			p -= (n / m) * r;
			q -= (n / m) * s;
			n %= m;
		}else{
			r -= (m / n) * p;
			s -= (m / n) * q;
			m %= n;
		}
	}

	d = n + m;
	if (n) a = p, b = q;
	else a = r, b = s;
}

int main(){
	qword t, best, x, y;

	while (scanf("%lld\n", &N) == 1 && N){
		scanf("%lld%lld%lld%lld", &c1, &n1, &c2, &n2);
		do_euclid();
		if (N % d) puts("failed");
		else{
			a *= N / d; b *= N / d;

			best = -1;
			if (a < 0){
				t = (-d * a + n2 - 1) / n2;
				a += (n2 / d) * t;
				b -= (n1 / d) * t;
			}else{
				t = (d * a) / n2;
				a -= (n2 / d) * t;
				b += (n1 / d) * t;
			}

			if (b >= 0){
				best = a * c1 + b * c2;
				x = a; y = b;
			}

			if (b < 0){
				t = (-d * b + n1 - 1) / n1;
				a -= (n2 / d) * t;
				b += (n1 / d) * t;
			}else{
				t = (d * b) / n1;
				a += (n2 / d) * t;
				b -= (n1 / d) * t;
			}

			if (a >= 0 && (best == -1 || best > a * c1 + b * c2)){
				best = 1;
				x = a; y = b;
			}

			if (best == -1) puts("failed");
			else printf("%lld %lld\n", x, y);
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
