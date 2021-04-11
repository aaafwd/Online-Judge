/* @JUDGE_ID: 19899RK 10614 C++ "By Anadan" */
// Dreadful Vectors
// Accepted (0.002 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

class Term {
private:
	bool isVector, isError;
	int x, y, z;
public:

	Term() { isError = true; }
	
	Term(int v) {
		isVector = isError = false;
		x = v;
	}

	Term(int vx, int vy, int vz) {
		isVector = true;
		isError = false;
		x = vx; y = vy; z = vz;
	}

	bool isValid() const { return !isError; }
	bool isScalar() const { return !isError && !isVector; }
	int getX() const { return x; }
	int getY() const { return y; }
	int getZ() const { return z; }

	void operator += (const Term & term) {
		if (isError || term.isError || isVector != term.isVector) {
			isError = true;
			return;
		}
		x += term.x; y += term.y; z += term.z;
	}

	void operator -= (const Term & term) {
		if (isError || term.isError || isVector != term.isVector) {
			isError = true;
			return;
		}
		x -= term.x; y -= term.y; z -= term.z;
	}

	void operator *= (const Term & term) {
		if (isError || term.isError) { isError = true; return; }
		if (isVector) {
			if (term.isVector) {
				isVector = false;
				x = x * term.x + y * term.y + z * term.z;
			} else {
				x *= term.x; y *= term.x; z *= term.x;
			}
		} else {
			if (term.isVector) {
				isVector = true;
				y = term.y * x;
				z = term.z * x;
			}
			x *= term.x;
		}
	}

	void operator /= (const Term & term) {
		if (isError || term.isError || !isVector || !term.isVector) {
			isError = true;
			return;
		}
		int nx = y*term.z - z*term.y;
		int ny = z*term.x - x*term.z;
		int nz = x*term.y - y*term.x;
		x = nx; y = ny; z = nz;
	}

	void print() const {
		if (isError) puts("Bang!");
		else if (isVector) printf("[%d,%d,%d]\n", x, y, z);
		else printf("%d\n", x);
	}
};

bool legal(char * str) {
	static const char legalChars[] = " +-*x,[]()0123456789";
	for (; *str; ++str) {
		if (!strchr(legalChars, *str)) return false;
	}
	return true;
}

char * nextBracket(char * str) {
	int rest = 1;
	++str;
	while (*str) {
		if (*str == '[' || *str == '(') ++rest;
		if (*str == ']' || *str == ')') --rest;
		if (!rest) break;
		++str;
	}
	return str;
}

Term evaluate0(char * str);
Term evaluate1(char * str);
Term evaluate2(char * str);

Term parseVector(char * str) {
	int x, y, z;
	char *p;
	Term tt;

	for (; *str == ' '; ++str);
	for (p = str; *p; ++p) {
		if (*p == '(' || *p == '[') {
			p = nextBracket(p);
			if (!*p) break;
		} else if (*p == ',') {
			*p++ = 0;
			tt = evaluate0(str);
			x = tt.getX();
			str = p;
			break;
		}
	}
	if (!tt.isScalar()) return Term();
	tt = Term();

	for (; *str == ' '; ++str);
	for (p = str; *p; ++p) {
		if (*p == '(' || *p == '[') {
			p = nextBracket(p);
			if (!*p) break;
		} else if (*p == ',') {
			*p++ = 0;
			tt = evaluate0(str);
			y = tt.getX();
			str = p;
			break;
		}
	}
	if (!tt.isScalar()) return Term();

	tt = evaluate0(str);
	if (!tt.isScalar()) return Term();
	z = tt.getX();

	return Term(x, y, z);
}

Term evaluate2(char * str) {
	for (; *str == ' '; ++str);

	if (*str == '[') {
		char *p = nextBracket(str);
		if (*p != ']') return Term();
		for (*p++ = 0; *p; ++p) if (*p != ' ') return Term();
		return parseVector(str + 1);
	} else if (*str == '(') {
		char *p = nextBracket(str);
		if (*p != ')') return Term();
		for (*p++ = 0; *p; ++p) if (*p != ' ') return Term();
		return evaluate0(str + 1);
	} else if ('0' <= *str && *str <= '9') {
		int x, off;
		sscanf(str, "%d%n", &x, &off);
		for (str += off; *str; ++str) if (*str != ' ') return Term();
		return Term(x);
	}

	return Term();
}

Term evaluate1(char * str) {
	char *p = NULL, *sav = str;

	for (; *str; ++str) {
		if (*str == ' ') continue;
		if (*str == '[' || *str == '(') {
			str = nextBracket(str);
			if (!*str) break;
		} else if (*str == '*' || *str == 'x') {
			p = str;
		}
	}
	str = sav;

	if (p == NULL) return evaluate2(str);
	else if (*p == '*') {
		*p++ = 0;
		Term t1 = evaluate1(str);
		if (!t1.isValid()) return t1;
		Term t2 = evaluate2(p);
		t1 *= t2;
		return t1;
	} else if (*p == 'x') {
		*p++ = 0;
		Term t1 = evaluate1(str);
		if (!t1.isValid()) return t1;
		Term t2 = evaluate2(p);
		t1 /= t2;
		return t1;
	}
	return Term();
}

Term evaluate0(char * str) {
	char *p = NULL, *sav = str;

	for (; *str; ++str) {
		if (*str == ' ') continue;
		if (*str == '[' || *str == '(') {
			str = nextBracket(str);
			if (!*str) break;
		} else if (*str == '+' || *str == '-') {
			p = str;
		}
	}
	str = sav;

	if (p == NULL) return evaluate1(str);
	else if (*p == '+') {
		*p++ = 0;
		Term t1 = evaluate0(str);
		if (!t1.isValid()) return t1;
		Term t2 = evaluate1(p);
		t1 += t2;
		return t1;
	} else if (*p == '-') {
		*p++ = 0;
		Term t1 = evaluate0(str);
		if (!t1.isValid()) return t1;
		Term t2 = evaluate1(p);
		t1 -= t2;
		return t1;
	}
	return Term();
}

int main() {
	char str[128];

	while (gets(str) && str[0] != '#') {
		if (!legal(str)) puts("Bang!");
		else {
			evaluate0(str).print();
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
