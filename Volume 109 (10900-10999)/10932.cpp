/* @JUDGE_ID: 19899RK 10932 C++ "By Anadan" */
// Calculator
// Accepted (0.002 seconds with low memory spent)

#include <stdio.h>

double values[26];

char * get_next_bracket(char * str) {
	int count = 1;
	++str;
	while (*str) {
		if (*str == '(') ++count;
		else if (*str == ')') --count;
		if (!count) break;
		++str;
	}
	return str;
}

double eval(char * str) {
	char * p, * curr = NULL;

	for (p = str; *p; ++p) {
		if (*p == '(') p = get_next_bracket(p);
		else if (*p == '+' || *p == '-') {
			curr = p;
		}
	}

	if (!curr) {
		for (p = str; *p; ++p) {
			if (*p == '(') p = get_next_bracket(p);
			else if (*p == '*' || *p == '/') {
				curr = p;
			}
		}
	}

	if (!curr) {
		if (*str == '(') {
			*(--p) = 0;
			return eval(str+1);
		}
		if ('a' <= *str && *str <= 'z') {
			return values[*str - 'a'];
		}
		double res;
		sscanf(str, "%lf", &res);
		return res;
	} else if (*curr == '+') {
		*curr = 0;
		return eval(str) + eval(curr+1);
	} else if (*curr == '-') {
		*curr = 0;
		return eval(str) - eval(curr+1);
	} else if (*curr == '*') {
		*curr = 0;
		return eval(str) * eval(curr+1);
	} else if (*curr == '/') {
		*curr = 0;
		return eval(str) / eval(curr+1);
	}
	return 0;
}

int main() {
	char str[8192];
	while (scanf("%s", &str) == 1) {
		if (str[1] == '=') {
			values[str[0]-'a'] = eval(str+2);
		} else {
			printf("%.2lf\n", eval(str));
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
