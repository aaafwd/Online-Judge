/* @JUDGE_ID: 19899RK 198 C++ "By Anadan" */
// Peter's Calculator
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>
#include <string.h>
#define SZ 1024

char vars[SZ][52], * definition[SZ], mask[SZ];
int varcount, hash[SZ], error_flag;

inline int isspace(int x) { return x == ' ' || x == '\t' || x == '\n'; }

void reset() {
	int i;
	for (i = 0; i < varcount; ++i) {
		delete[] definition[i];
	}
	varcount = 0;
}

int hashCode(char * str) {
	int res = 0, i;
	for (i = 0; str[i]; ++i) {
		res = res*31 + str[i] - ' ';
	}
	return res;
}

int getvar(char * str, int h = -1) {
	int i;

	if (h < 0) h = hashCode(str);
	for (i = 0; i < varcount; ++i) {
		if (hash[i] == h && strcmp(vars[i], str) == 0) {
			return i;
		}
	}
	return -1;
}

char * next_bracket(char * str) {
	int count = 1;
	for (++str; *str; ++str) {
		if (*str == '(') ++count;
		else if (*str == ')') --count;
		if (!count) break;
	}
	return str;
}

int evaluate(char * str);
int evaluate0(char * str);
int evaluate1(char * str);

// factor = "(" expression ")" | var | number
// var = letter { letter | digit }
// number = [ "-" ] digit { digit }
// letter = "A" | "B" | ... | "Z" | "a" | "b" | ... | "z"
// digit = "0" | "1" | ... | "8" | "9"
int evaluate1(char * str) {
	int res = 0, i;
	char * p, ch;

	if (error_flag) return 0;
	while (isspace(*str)) ++str;

	if (*str == '(') {
		p = next_bracket(str);
		*p = 0;
		res = evaluate(str + 1);
		*p = ')';
	} else if (*str == '-' || ('0' <= *str && *str <= '9')) {
		i = 0;
		if (*str == '-') { i = 1; ++str; }
		res = *str++ - '0';
		while ('0' <= *str && *str <= '9') {
			res = res * 10 + *str++ - '0';
		}
		if (i) res = -res;
	} else {
		for (p = str + 1; *p && !isspace(*p); ++p);
		ch = *p;
		*p = 0;
		i = getvar(str);
		*p = ch;

		if (i < 0 || mask[i]) error_flag = 1;
		else {
			mask[i] = 1;
			res = evaluate(definition[i]);
			mask[i] = 0;
		}
	}

	return res;
}

// term = factor { mulop factor }
// mulop = "*"
int evaluate0(char * str) {
	int res;
	char * p, * mulop = NULL;

	if (error_flag) return 0;

	for (p = str; *p; ++p) {
		if (*p == '(') p = next_bracket(p);
		else if (*p == '*') mulop = p;
	}

	if (!mulop) res = evaluate1(str);
	else {
		*mulop = 0;
		res = evaluate0(str) * evaluate1(mulop + 1);
		*mulop = '*';
	}
	return res;
}

// expression = term { addop term }
// addop = "+" | "-"
int evaluate(char * str) {
	int res;
	char * p, * addop = NULL, empty_flag = 1;

	if (error_flag) return 0;

	for (p = str; *p; ++p) {
		if (*p == '(') {
			p = next_bracket(p);
			empty_flag = 0;
		} else if (*p == '+' || *p == '-') {
			if (!empty_flag) addop = p;
			empty_flag = 1;
		}
		else if (*p == '*') empty_flag = 1;
		else if (!isspace(*p)) empty_flag = 0;
	}

	if (!addop) res = evaluate0(str);
	else if (*addop == '+') {
		*addop = 0;
		res = evaluate(str) + evaluate0(addop + 1);
		*addop = '+';
	} else {
		*addop = 0;
		res = evaluate(str) - evaluate0(addop + 1);
		*addop = '-';
	}

	return res;
}

int main() {
	int i;
	char str[256], *p, *q;

	varcount = 0;

	while (gets(str)) {
		for (p = str; isspace(*p); ++p);
		if (!*p) continue;

		if (strncmp(p, "PRINT", 5) == 0 && isspace(p[5])) {
			for (p += 5; isspace(*p); ++p);
			for (q = p+1; *q && !isspace(*q); ++q);
			*q = 0;

			i = getvar(p);
			if (i < 0) {
				error_flag = 1;
			} else {
				error_flag = 0;
				memset(mask, 0, sizeof(mask));
				mask[i] = 1;
				i = evaluate(definition[i]);
			}

			if (error_flag) puts("UNDEF");
			else printf("%d\n", i);

		} else if (strncmp(p, "RESET", 5) == 0 && (!p[5] || isspace(p[5]))) {
			reset();

		} else {
			// assignment = var ":=" expression
			for (q = p+1; *q != ':' && !isspace(*q); ++q);
			*q++ = 0;
			while (*q++ != '=');
			while (isspace(*q)) ++q;

			i = getvar(p);
			if (i < 0) {
				i = varcount++;
				strcpy(vars[i], p);
				hash[i] = hashCode(p);
			} else {
				delete[] definition[i];
			}
			definition[i] = strcpy(new char[strlen(q) + 1], q);
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
