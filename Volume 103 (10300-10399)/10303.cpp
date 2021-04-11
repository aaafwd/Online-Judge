/* @JUDGE_ID: 19899RK 10303 C++ "By Anadan" */ 
// How Many Trees?
// Accepted (0.080 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

void _reverse(char *p){
	char *q = p + strlen(p) - 1;
	while (p < q) *p++ ^= *q-- ^= *p ^= *q;
}

int gcd(int a, int b){
	while (a && b) if (a > b) a %= b; else b %= a;
	if (a) return a; else return b;
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
	char map[1001][605];

	map[0][0] = '1'; map[0][1] = 0;
	for (i = 1; i <= 1000; ++i){
		a = 4*i - 2; b = i + 1; c = gcd(a, b);
		a /= c; b /= c;
		if (b > 1) div(map[i - 1], b, map[i]);
		else strcpy(map[i], map[i - 1]);
		mul(map[i], a);
	}

	for (i = 1; i <= 1000; ++i) _reverse(map[i]);
	while (scanf("%d\n", &i) == 1) printf("%s\n", map[i]);
	return 0;
}
/* @END_OF_SOURCE_CODE */
