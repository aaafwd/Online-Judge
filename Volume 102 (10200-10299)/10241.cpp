/* @JUDGE_ID: 19899RK 10241 C++ "By Anadan" */
// Semi-triangular and also Square
// Accepted (0.002 seconds with low memory spent)

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

typedef long long qword;

class ContinuedFraction {
private:
	double r;
public:
	ContinuedFraction() { this->r = 1; }
	ContinuedFraction(double x) { this->r = x; }
	void reset(double x) { this->r = x; }
	int next() {
		int res = (int)r;
		r = 1 / (r - res);
		return res;
	}
};

// x^2 - D*y^2 = 1
class PellEquation {
private:
	int D, firstFraction;
	qword p0, p1, q0, q1;
	double sqrtD;
	ContinuedFraction fraction;

	void step() {
		int tmp = fraction.next();
		qword x = p0, y = q0;
		p0 = p1; q0 = q1;
		p1 = tmp*p0 + x;
		q1 = tmp*q0 + y;
		if (tmp == firstFraction*2) {
			fraction.reset(sqrtD);
			fraction.next();
		}
	}

public:
	PellEquation(int D) {
		reset(D);
	}

	void reset(int D) {
		this->D = D;
		fraction.reset(sqrtD = sqrt(D));
		q0 = 1;
		p0 = fraction.next();
		q1 = fraction.next();
		p1 = p0 * q1 + 1;
		firstFraction = p0;
	}

	void next(qword & x, qword & y) {
		while (p0*p0 - D*q0*q0 != 1) step();
		x = p0; y = q0;
		step();
	}
};

int sp = 0;
char * res[128];

int sort_function(const void *a, const void *b) {
	int l1 = strlen(*(char**)a), l2 = strlen(*(char**)b);
	if (l1 < l2) return -1;
	else if (l1 > l2) return 1;
	return strcmp(*(char**)a, *(char**)b);
}

void _reverse(char *p){
	char *q = p + strlen(p) - 1;
	while (p < q) *p++ ^= *q-- ^= *p ^= *q;
}

// n*(n+1)/2 * m
char * calcResult(qword a, int m) {
	qword b = a + 1, rest = 0;
	char * res = new char[64], *sav = res;
	int r1, r2;

	if (a & 1) { b /= 2; b *= m; }
	else { a /= 2; a *= m; }

	while (a || b) {
		r1 = a % 10;
		r2 = b % 10;
		rest += r1*r2;
		*res++ = rest%10 + '0';
		rest /= 10;
		a /= 10;
		b /= 10;
		rest += a*r2 + b*r1;
		*res++ = rest%10 + '0';
		rest /= 10;
	}

	while (rest) {
		*res++ = rest%10 + '0';
		rest /= 10;
	}
	*res-- = 0;
	while (*res == '0') *res-- = 0;
	_reverse(sav);
	return sav;
}

int main() {
	const qword limit = (qword)(400000000000000000LL);
	const int m[6] = { 3, 5, 7, 11, 13, 15 };
	PellEquation pe(2);
	qword x, y;
	int i;

	while (1) {
		pe.next(x, y);
		y = (x - 1) / 2;
		if (y < 0 || y >= limit) break;
		res[sp++] = calcResult(y, 1);
		if (y <= limit / 3) {
			res[sp++] = calcResult(y, 9);
		}
	}

	for (i = 0; i < 6; ++i) {
		pe.reset(m[i] * 2);
		while (1) {
			pe.next(x, y);
			y = (x - 1) /2;
			if (y < 0 || y >= limit) break;
			res[sp++] = calcResult(y, m[i]);
		}
	}

	qsort(res, sp, sizeof(char *), sort_function);
	puts(res[0]);
	for (i = 1; i < sp-2; ++i) {
		if (strcmp(res[i], res[i-1]) == 0) continue;
		puts(res[i]);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
