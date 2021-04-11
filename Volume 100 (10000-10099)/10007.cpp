/* @JUDGE_ID: 19899RK 10007 C++ "By Anadan" */ 
// Count the Trees
// Accepted (0.035 seconds with low memory spent)

#include <stdio.h>
#include <string.h>
#define SZ 300

void _reverse(char *p){
	char *q = p + strlen(p) - 1;
	while (p < q) *p++ ^= *q-- ^= *p ^= *q;
}

int gcd(int a, int b){
	while (a && b) if (a > b) a %= b; else b %= a;
	if (a) return a; else return b;
}

void add(char *p, char *q){
	int rest = 0;

	while (*q){
		rest += *p - '0' + *q - '0';
		if (rest >= 10){
			*p = '0' + rest - 10;
			rest = 1;
		}else{
			*p = '0' + rest;
			rest = 0;
		}
		++p; ++q;
	}

	while (*p && rest){
		rest += *p - '0';
		if (rest >= 10){
			*p = '0' + rest - 10;
			rest = 1;
		}else{
			*p = '0' + rest;
			rest = 0;
		}
		++p;
	}

	if (rest){
		*p++ = '1';
		*p = 0;
	}
}

void div(char *p, int b, char *q){
	int rest = 0;
	char *s = p + strlen(p) - 1, *res = q;

	while (s >= p){
		rest *= 10;
		rest += *s-- - '0';
		*q++ = '0' + rest / b;
		rest %= b;
	}

	*q-- = 0;
	_reverse(res);
	while (*q == '0') --q;
	*(q + 1) = 0;
}

void mul(char *p, int a){
	int rest = 0;

	while (*p){
		rest += (*p - '0') * a;
		*p++ = '0' + (rest % 10);
		rest /= 10;
	}

	while (rest){
		*p++ = '0' + (rest % 10);
		rest /= 10;
	}

	*p = 0;
}

int main(){
	int i, a, b, c;
	char *map[SZ + 1], s1[1000], s2[1000];

	// Catalan numbers * n!
	map[1] = "1";
	for (i = 1; i < SZ; ++i){
		a = 6; b = i + 2; c = gcd(a, b);
		a /= c; b /= c;

		strcpy(s1, map[i]);
		mul(s1, 4*i - 2);

		if (b > 1) div(map[i], b, s2);
		else strcpy(s2, map[i]);

		mul(s2, a);
		add(s1, s2);
		map[i + 1] = strcpy(new char [strlen(s1) + 1], s1);
	}

	for (i = 1; i <= SZ; ++i) _reverse(map[i]);
	while (scanf("%d\n", &i) == 1 && i) puts(map[i]);
	for (i = 2; i <= SZ; ++i) delete map[i];

	return 0;
}
/* @END_OF_SOURCE_CODE */
