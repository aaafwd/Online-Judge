/* @JUDGE_ID: 19899RK 172 C++ "By Anadan" */ 
// Calculator Language
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

int oldvals[26], vals[26];

int parse(char *s){
	int value, tmp;
	char ch = 0, op = 0, *p;

	while (*s == ' ' || *s == '\t') ++s;
	if (!*s) return 0;

	if (*s == '('){
		value = 1;
		for (p = s + 1; value; ++p){
			if (*p == '(') ++value;
			else if (*p == ')') --value;
		}

		*(p - 1) = 0;
	}else{
		p = s + 1;
	}

	for (; *p; ++p){
		if (*p == '-' || *p == '+' || *p == '*' || *p == '/' || *p == '=') break;
	}

	op = *p;
	*p++ = 0;

	if (op) value = parse(p);

	if (*s == '(') tmp = parse(s + 1);
	else{
		while (*s == ' ' || *s == '\t') ++s;
		p = s;
		if (*s == '_') ++s;
		if ('0' <= *s && *s <= '9'){
			tmp = 0;
			while ('0' <= *s && *s <= '9') tmp = 10 * tmp + *s++ - '0';
			if (*p == '_') tmp = -tmp;
		}else{
			if (op == '=') tmp = *s - 'A';
			else tmp = vals[*s - 'A'];
		}
	}

	if (!op) return tmp;

	if (op == '+') tmp += value;
	else if (op == '-') tmp -= value;
	else if (op == '*') tmp *= value;
	else if (op == '/') tmp /= value;
	else{
		vals[tmp] = value;
		tmp = value;
	}

	return tmp;
}

int main(){
	int i, flag;
	char str[128];

	memset(oldvals, 0, sizeof(oldvals));

	while (gets(str) && str[0] != '#'){
		memcpy(vals, oldvals, sizeof(vals));
		parse(str);

		flag = 0;
		for (i = 0; i < 26; ++i){
			if (vals[i] == oldvals[i]) continue;
			if (flag) printf(", "); else flag = 1;
			printf("%c = %d", i + 'A', vals[i]);
		}

		if (flag) putchar('\n');
		else puts("No Change");

		memcpy(oldvals, vals, sizeof(vals));
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
