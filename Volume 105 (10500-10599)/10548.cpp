/* @JUDGE_ID: 19899RK 10548 C++ "By Anadan" */
// Find the Right Changes
// Accepted (0.004 seconds with low memory spent)

#include <stdio.h>

typedef long long qword;
int a, b, c, d;
qword x, y;

void doEuler(){
	int m = a, p = 1, q = 0;
	int n = b, r = 0, s = 1;

	if (m < 0) { m = -m; p = -1; }
	if (n < 0) { n = -n; s = -1; }

	while (m && n){
		if (m >= n){
			p -= (m / n) * r;
			q -= (m / n) * s;
			m %= n;
		}else{
			r -= (n / m) * p;
			s -= (n / m) * q;
			n %= m;
		}
	}

	d = m + n;
	if (c % d) { d = -1; return; }

	if (m == 0) { x = r; y = s; }
	else { x = p; y = q; }

	m = c / d;
	x *= m;
	y *= m;
}

inline void putresult(qword k){
	if (k <= 0) puts("Impossible");
	else printf("%lld\n", k);
}

inline qword _floor(qword x, int y){
	if (y < 0) { x = -x; y = -y; }
	if (x >= 0) return x / y;
	return (x - y + 1) / y;
}

inline qword _ceil(qword x, int y){
	if (y < 0) { x = -x; y = -y; }
	if (x >= 0) return (x + y - 1) / y;
	return x / y;
}

int main(){
	int set;

	scanf("%d", &set);
	while (set--){
		scanf("%d%d%d", &a, &b, &c);
		doEuler();
		if (d == -1) puts("Impossible");
		else{
			x = -x * d;
			y = y * d;

			if (a > 0){
				if (b > 0) putresult(_floor(y, a) - _ceil(x, b) + 1);
				else puts("Infinitely many solutions");
			}else{
				if (b > 0) puts("Infinitely many solutions");
				else putresult(_floor(x, b) - _ceil(y, a) + 1);
			}
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
