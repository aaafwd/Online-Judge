/* @JUDGE_ID: 19899RK 10464 C++ "By Anadan" */ 
// Big Big Real Numbers
// Accepted (0.008 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

char a[1100], b[1100];

void _reverse(char *p){
	char *q = p + strlen(p) - 1;
	while (p < q) *p++ ^= *q-- ^= *p ^= *q;
}

void strspcat(char *s, int sp){
	while (*s) ++s;
	while (sp--) *s++ = '0';
	*s = 0;
}

int subnums(char *s1, char *s2, char *res){
	int rest = 0;

	_reverse(s1); _reverse(s2);
	while (*s1 && *s2){
		rest += *s1++ - '0' - (*s2++ - '0');
		if (rest < 0){
			*res++ = '0' + rest + 10;
			rest = -1;
		}else{
			*res++ = '0' + rest;
			rest = 0;
		}
	}

	*res = 0;
	_reverse(b);
	s1 = b + strlen(b) - 1;
	while (s1 >= b && *s1 == '0') --s1;
	*(s1 + 1) = 0;

	return rest;
}

int addnums(char *s1, char *s2, char *res){
	int rest = 0;

	_reverse(s1); _reverse(s2);
	while (*s1 && *s2){
		rest += *s1++ - '0' + *s2++ - '0';
		if (rest > 9){
			*res++ = '0' + rest - 10;
			rest = 1;
		}else{
			*res++ = '0' + rest;
			rest = 0;
		}
	}

	*res = 0;
	_reverse(b);
	s1 = b + strlen(b) - 1;
	while (s1 >= b && *s1 == '0') --s1;
	*(s1 + 1) = 0;

	return rest;
}

void add(char *p1, char *p2){
	char *res = a;
	char *p = strchr(p1, '.');
	char *q = strchr(p2, '.');
	int l1, l2, rest;

	if (p == NULL) p = p1 + strlen(p1) - 1; else *p++ = 0;
	if (q == NULL) q = p2 + strlen(p2) - 1; else *q++ = 0;

	l1 = strlen(p); l2 = strlen(q);
	if (l1 > l2) strspcat(q, l1 - l2);
	else if (l1 < l2) strspcat(p, l2 - l1);

	rest = addnums(p, q, b);
	_reverse(p1); _reverse(p2);
	while (*p1 && *p2){
		rest += *p1++ - '0' + *p2++ - '0';
		if (rest > 9){
			*res++ = '0' + rest - 10;
			rest = 1;
		}else{
			*res++ = '0' + rest;
			rest = 0;
		}
	}

	while (*p1){
		rest += *p1++ - '0';
		if (rest > 9){
			*res++ = '0' + rest - 10;
			rest = 1;
		}else{
			*res++ = '0' + rest;
			rest = 0;
		}
	}

	while (*p2){
		rest += *p2++ - '0';
		if (rest > 9){
			*res++ = '0' + rest - 10;
			rest = 1;
		}else{
			*res++ = '0' + rest;
			rest = 0;
		}
	}

	if (rest) *res++ = '0' + rest;
	*res = 0;
	_reverse(a);
}

int sub(char *p1, char *p2){
	char *res = a;
	char *p = strchr(p1, '.');
	char *q = strchr(p2, '.');
	int l1, l2, rest;

	if (p == NULL) p = p1 + strlen(p1) - 1; else *p++ = 0;
	if (q == NULL) q = p2 + strlen(p2) - 1; else *q++ = 0;

	l1 = strlen(p); l2 = strlen(q);
	if (l1 > l2) strspcat(q, l1 - l2);
	else if (l1 < l2) strspcat(p, l2 - l1);

	rest = subnums(p, q, b);
	_reverse(p1); _reverse(p2);
	while (*p1 && *p2){
		rest += *p1++ - '0' - (*p2++ - '0');
		if (rest < 0){
			*res++ = '0' + rest + 10;
			rest = -1;
		}else{
			*res++ = '0' + rest;
			rest = 0;
		}
	}

	while (*p1){
		rest += *p1++ - '0';
		if (rest < 0){
			*res++ = '0' + rest + 10;
			rest = -1;
		}else{
			*res++ = '0' + rest;
			rest = 0;
		}
	}

	while (*p2){
		rest += *p2++ - '0';
		if (rest < 0){
			*res++ = '0' + rest + 10;
			rest = -1;
		}else{
			*res++ = '0' + rest;
			rest = 0;
		}
	}

	*res = 0;
	_reverse(a);

	return -rest;
}

int numcmp(char *p1, char *p2){
	int i;
	while (*p1 && *p1 == '0') ++p1;
	while (*p2 && *p2 == '0') ++p2;
	i = strlen(p1) - strlen(p2);
	if (i) return i;

	while (*p1 && *p1 == *p2) ++p1, ++p2;
	if (*p1 == *p2) return 0;
	return *p1 - *p2;
}

int cmp(char *p1, char *p2){
	int i;
	char *p = strchr(p1, '.');
	char *q = strchr(p2, '.');

	if (p) *p = 0;
	if (q) *q = 0;

	i = numcmp(p1, p2);
	if (p) *p = '.';
	if (q) *q = '.';
	if (i) return i;

	if (p == NULL) p = p1 + strlen(p1) - 2;
	if (q == NULL) q = p2 + strlen(p2) - 2;
	return numcmp(p + 1, q + 1);
}

int main(){
	int set, s1, s2, i;
	static char op1[2100], op2[2100], *p1, *p2;

	scanf("%d\n", &set);
	while (set--){
		scanf("%s%s\n", op1, op2);
		p1 = op1; if (*p1 == '-') { s1 = 1; ++p1; } else s1 = 0;
		p2 = op2; if (*p2 == '-') { s2 = 1; ++p2; } else s2 = 0;

		if (s1 ^ s2){
			i = cmp(p1, p2);
			if (i >= 0) s1 ^= sub(p1, p2);
			else s1 = s2 ^ sub(p2, p1);
		}else{
			add(p1, p2);
			s1 |= s2;
		}

		if (s1) putchar('-');
		for (p1 = a; *p1 && *p1 == '0'; ++p1);
		if (*p1 == 0) putchar('0'); else printf("%s", p1);
		putchar('.');
		if (strlen(b) == 0) putchar('0'); else printf("%s", b);
		putchar('\n');
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
