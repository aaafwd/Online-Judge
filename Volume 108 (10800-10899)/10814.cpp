/* @JUDGE_ID: 19899RK 10814 C++ "By Anadan" */
// Simplifying Fractions
// Accepted (0.004 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

void _reverse(char * p) {
	char * q = p + strlen(p) - 1;
	while (p < q) *p++ ^= *q-- ^= *p ^= *q;
}

void mul2(char * s) {
	int rest = 0;
	while (*s) {
		rest += (*s - '0') * 2;
		*s++ = (rest % 10) + '0';
		rest /= 10;
	}
	if (rest) *s++ = rest + '0';
	*s = 0;
}

void div2(char * s) {
	int rest = 0;
	char *p = s + strlen(s) - 1, *sav = p;
	while (p >= s) {
		rest = rest*10 + *p - '0';
		*p-- = (rest/2) + '0';
		rest &= 1;
	}
	if (*sav == '0') *sav = 0;
}

// true, if (p1 < p2)
int less(char * p1, char * p2) {
	int len1 = strlen(p1), len2 = strlen(p2);
	while (p1[len1 - 1] == '0') p1[--len1] = 0;
	while (p2[len2 - 1] == '0') p2[--len2] = 0;
	if (len1 < len2) return 1;
	if (len1 > len2) return 0;
	while (len1--) {
		if (p1[len1] < p2[len1]) return 1;
		if (p1[len1] > p2[len1]) return 0;
	}
	return 0;
}

// p1 -= p2 (p1 > p2)
void sub(char * p1, char * p2) {
	int rest = 0;
	while (*p2) {
		rest += *p1 - *p2;
		if (rest >= 0) {
			*p1 = rest + '0';
			rest = 0;
		} else {
			*p1 = rest + 10 + '0';
			rest = -1;
		}
		++p1; ++p2;
	}
	while (rest) {
		rest += *p1 - '0';
		if (rest >= 0) {
			*p1 = rest + '0';
			rest = 0;
		} else {
			*p1 = rest + 10 + '0';
			rest = -1;
		}
		++p1;
	}
	if (!*p1--) {
		while (*p1 == '0') *p1-- = 0;
	}
}

// p1 += p2
void add(char * p1, char * p2) {
	int rest = 0;
	while (*p1 && *p2) {
		rest += *p1 - '0' + *p2 - '0';
		if (rest <= 9) {
			*p1 = rest + '0';
			rest = 0;
		} else {
			*p1 = rest - 10 + '0';
			rest = 1;
		}
		++p1; ++p2;
	}
	while (*p1) {
		rest += *p1 - '0';
		if (rest <= 9) {
			*p1 = rest + '0';
			rest = 0;
		} else {
			*p1 = rest - 10 + '0';
			rest = 1;
		}
		++p1;
	}
	while (*p2) {
		rest += *p2 - '0';
		if (rest <= 9) {
			*p1 = rest + '0';
			rest = 0;
		} else {
			*p1 = rest - 10 + '0';
			rest = 1;
		}
		++p1; ++p2;
	}
	if (rest) *p1++ = '1';
	*p1 = 0;
}

void simplify(char * s1, char * s2) {
	if (strcmp(s1, s2) == 0) {
		strcpy(s1, "1"); strcpy(s2, "1");
		return;
	}

	while (!((*s1 - '0')&1) && !((*s2 - '0')&1)) {
		div2(s1);
		div2(s2);
	}

	if (!((*s1 - '0')&1)) {
		div2(s1);
		simplify(s1, s2);
		mul2(s1);
	} else if (!((*s2 - '0')&1)) {
		div2(s2);
		simplify(s1, s2);
		mul2(s2);
	} else if (less(s1, s2)) {
		sub(s2, s1);
		simplify(s1, s2);
		add(s2, s1);
	} else {
		sub(s1, s2);
		simplify(s1, s2);
		add(s1, s2);
	}
}

int main() {
	int set;
	char s1[32], s2[32];

	scanf("%d", &set);
	while (set--) {
		scanf("%s / %s", s1, s2);
		_reverse(s1);
		_reverse(s2);
		simplify(s1, s2);
		_reverse(s1);
		_reverse(s2);
		printf("%s / %s\n", s1, s2);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
