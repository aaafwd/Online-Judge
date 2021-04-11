/* @JUDGE_ID: 19899RK 10951 C++ "By Anadan" */
// Polynomial GCD
// Accepted (0.059 seconds with low memory spent)

#include <stdio.h>

class Polynom {
public:
	int coeff[128], N;
	void operator /= (const Polynom & p);
};

int prime;

int inv(int x) {
	int power = prime - 2, res = 1, tmp = x;
	while (power) {
		if (power & 1) {
			res *= tmp;
			res %= prime;
			--power;
		} else {
			tmp *= tmp;
			tmp %= prime;
			power >>= 1;
		}
	}
	return res;
}

void print(const Polynom * p) {
	int i;
	printf("%d", p->N);
	for (i = 0; i <= p->N; ++i) printf(" %d", p->coeff[i]);
	puts("");
}

void Polynom::operator /= (const Polynom & p) {
	int i, j, dN, x;

	while (N >= p.N) {
		x = (inv(p.coeff[0]) * coeff[0]) % prime;
		dN = N - p.N;
		for (i = 0; i <= p.N; ++i) {
			j = N - (p.N - i + dN);
			coeff[j] = (coeff[j] - ((p.coeff[i] * x) % prime) + prime) % prime;
		}

		for (j = 0; j <= N; ++j) if (coeff[j]) break;
		for (i = j; i <= N; ++i) coeff[i-j] = coeff[i];
		N = N - j;
	}
}

Polynom gcd(Polynom & p1, Polynom & p2) {
	if (p1.N < 0) return p2;
	if (p2.N < 0) return p1;

	if (p1.N < p2.N) return gcd(p2, p1);
	if (p1.N == p2.N && p1.coeff[0] < p2.coeff[0]) return gcd(p2, p1);

	p1 /= p2;
	return gcd(p2, p1);
}

int main() {
	int set = 0, i, x;
	Polynom p1, p2, p;

	while (scanf("%d", &prime) == 1 && prime) {
		scanf("%d", &p1.N);
		for (i = 0; i <= p1.N; ++i) {
			scanf("%d", &p1.coeff[i]);
			p1.coeff[i] %= prime;
		}
		scanf("%d", &p2.N);
		for (i = 0; i <= p2.N; ++i) {
			scanf("%d", &p2.coeff[i]);
			p2.coeff[i] %= prime;
		}
		p = gcd(p1, p2);
		printf("Case %d: ", ++set);
		x = inv(p.coeff[0]);
		for (i = 0; i <= p.N; ++i) {
			p.coeff[i] *= x;
			p.coeff[i] %= prime;
		}
		print(&p);
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */
