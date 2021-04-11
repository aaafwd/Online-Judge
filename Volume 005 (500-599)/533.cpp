/* @JUDGE_ID: 19899RK 533 C++ "By Anadan" */ 
// Equation Solver
// Accepted (0.010 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

struct Term{
	int a, b;
	void operator += (Term t) { a += t.a; b += t.b; }
	void operator -= (Term t) { a -= t.a; b -= t.b; }
	void operator *= (Term t) { a = a * t.b + b * t.a; b *= t.b; }
};
char *cur;

Term expression();

Term factor(){
	int off;
	Term res;

	if (*cur == 'x'){
		res.a = 1;
		res.b = 0;
		++cur;
	}else if (*cur == '('){
		++cur;
		res = expression();
//		assert(*cur == ')');
		++cur;
	}else{
		res.a = 0;
		sscanf(cur, "%d%n", &res.b, &off);
		cur += off;
	}

	return res;
}

Term term(){
	Term res = factor();

	while (*cur == '*'){
		++cur;
		res *= factor();
	}

	return res;	
}

Term expression(){
	Term res = term();

	while (*cur){
		if (*cur == '+') { ++cur; res += term(); }
		else if (*cur == '-') { ++cur; res -= term(); }
		else break;
	}

	return res;
}

int main(){
	int set = 0;
	char str[128], *p;
	Term res;

	while (gets(str)){
		if (set) putchar('\n');
		printf("Equation #%d\n", ++set);
		p = strchr(str, '=');
		*p++ = 0;

		cur = str; res = expression();
		cur = p; res -= expression();

		if (res.a == 0){
			if (res.b == 0) printf("Infinitely many solutions.\n");
			else printf("No solution.\n");
		}else printf("x = %.6lf\n", -double(res.b) / double (res.a));
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
