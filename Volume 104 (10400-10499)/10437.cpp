/* @JUDGE_ID: 19899RK 10437 C++ "By Anadan" */ 
// Playing With Fraction
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>

struct Fraction{
	int x, y;
	void operator = (int N) { x = N; y = 1; }
	void operator += (Fraction f);
	void operator -= (Fraction f);
	void operator *= (Fraction f);
	void operator /= (Fraction f);
};

inline int abs(int a) { return (a < 0) ? (-a) : (a); }

void simplify(int &a, int &b){
	int m, n;

	if (b < 0) { a = -a; b = -b; }

	m = abs(a); n = abs(b);
	while (m && n) if (m > n) m %= n; else n %= m;
	if (m == 0) m = n;

	if (m) { a /= m; b /= m; }
}

void Fraction::operator += (Fraction f){
	x = x * f.y + y * f.x;
	y *= f.y;
	simplify(x, y);
}

void Fraction::operator -= (Fraction f){
	x = x * f.y - y * f.x;
	y *= f.y;
	simplify(x, y);
}

void Fraction::operator *= (Fraction f){
	x *= f.x;
	y *= f.y;
	simplify(x, y);
}

void Fraction::operator /= (Fraction f){
	x *= f.y;
	y *= f.x;
	simplify(x, y);
}

int getdigit(char *&p, int &a){
	int sign = 0;

	while (1){
		if (*p == '-') { sign ^= 1; ++p; }
		else if (*p == '+') ++p;
		else break;
	}

	a = 0;
	while ('0' <= *p && *p <= '9'){
		a = a * 10 + *p - '0';
		++p;
	}

	if (sign) a = -a;
	return 1;
}

int getfraction(char *&p, Fraction &f){
	if (!getdigit(p, f.x)) return 0;
	if (*p == '|'){
		++p;
		if (!getdigit(p, f.y) || f.y == 0) return 0;
		simplify(f.x, f.y);
	}else f.y = 1;

	return 1;
}

int expression(char *&p, Fraction &f){
	Fraction tmp;

	if (*p == 0) return 0;
	if (*p == '('){
		++p;
		if (!expression(p, f)) return 0;
		++p;
	}else if (*p == '+' && *(p + 1) == '('){
		p += 2;
		if (!expression(p, f)) return 0;
		++p;
	}else if (*p == '-' && *(p + 1) == '('){
		p += 2;
		if (!expression(p, f)) return 0;
		++p;
		f.x = -f.x;
	}else{
		if (!getfraction(p, f)) return 0;
	}

	while (*p){
		if (*p == '*'){
			++p;
			if (*p == '('){
				++p;
				if (!expression(p, tmp)) return 0;
				++p;
			}else if (!getfraction(p, tmp)) return 0;
			f *= tmp;

		}else if (*p == '/'){
			++p;
			if (*p == '('){
				++p;
				if (!expression(p, tmp)) return 0;
				++p;
			}else if (!getfraction(p, tmp)) return 0;
			f /= tmp;

		}else if (*p == '+'){
			++p;
			if (!expression(p, tmp)) return 0;
			f += tmp;

		}else if (*p == '-'){
			if (!expression(p, tmp)) return 0;
			f += tmp;

		}else if (*p == ')'){
			break;
		}
	}

	if (f.y == 0) return 0;
	return 1;
}

int main(){
	int i;
	char str[510], *p;
	Fraction f;

	while (1){
		p = str;
		while ((i = getchar()) != '\n' && i != EOF){
			if (i != ' ' && i != '\t') *p++ = i;
		}
		*p = 0;
		if (p == str) break;

		p = str;
		if (expression(p, f)){
			printf("%d", f.x);
			if (f.y != 1) printf("|%d", f.y);
			putchar('\n');
		}else printf("INVALID\n");
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
