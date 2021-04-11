/* @JUDGE_ID: 19899RK 10213 C++ "By Anadan" */ 
// How Many Pieces of Land?
// Accepted (0.152 seconds using as much as 392 kbytes)

#include <stdio.h>
#include <string.h>

typedef long long qword;

void _reverse(char *p){
	char *q = p + strlen(p) - 1;
	while (p < q) { *p ^= *q; *q ^= *p; *p++ ^= *q--; }
}

void add(char *s1, char *s2, char *s3){
	char carry = 0, *s;

	while (*s1 && *s2){
		*s3 = *s1 + *s2 + carry - '0';
		if (*s3 > '9'){
			*s3 -= 10;
			carry = 1;
		}else carry = 0;
		++s1; ++s2; ++s3;
	}

	if (*s1) s = s1; else s = s2;
	while (*s){
		*s3 = *s + carry;
		if (*s3 > '9'){
			*s3 -= 10;
			carry = 1;
		}else carry = 0;
		++s; ++s3;
	}

	if (carry) *s3++ = '1';
	*s3 = 0;
}

void mult(char *s1, char *s2, char n){
	char rest = 0;

	n -= '0';
	if (n == 0){
		s2[0] = '0';
		s2[1] = 0;
		return;
	}

	while (*s1){
		rest += (*s1 - '0') * n;
		*s2 = rest % 10 + '0';
		rest /= 10;
		++s1; ++s2;
	}

	if (rest) *s2++ = rest + '0';
	*s2 = 0;
}

int main(){
	int set, i, N;
	qword a, b;
	char op1[100], op2[100], tmp[100], res[100], *p;

	// The answer is (N^4 - 6*N^3 + 23*N^2 - 18*N) / 24 + 1 =
	//  = N*(N - 1)*(N^2 - 5*N + 18) / 24 + 1
	scanf("%d\n", &set);
	while (set--){
		scanf("%d\n", &N);
		a = qword(N) * qword(N - 1);
		b = a + 18 - qword(N) * 4;
		a >>= 1; b >>= 1;
		if (a & 1) b >>= 1; else a >>= 1;
		if (a % 3) b /= 3; else a /= 3;

		res[0] = '0'; res[1] = 0;
		sprintf(op1, "%lld", a); _reverse(op1);
		sprintf(op2, "%lld", b); _reverse(op2);

		for (i = 0, p = op2; *p; p++, i++){
			mult(op1, tmp, *p);
			add(res + i, tmp, res + i);
		}

		add(res, "1", res);
		_reverse(res);
		for (p = res; *p == '0'; p++);
		if (*p) printf("%s\n", p); else printf("0\n");
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
