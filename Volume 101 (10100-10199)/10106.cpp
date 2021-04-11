/* @JUDGE_ID: 19899RK 10106 C++ "By Anadan" */ 
// Product
// Accepted (0.020 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

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

void _strrev(char *p){
	char *q = p + strlen(p) - 1;
	while (p < q) { *p ^= *q; *q ^= *p; *p++ ^= *q--; }
}

int main(){
	int i;
	char op1[256], op2[256], tmp[256], res[512], c, *p;

	while (gets(op1)){
		_strrev(op1);
		if (!gets(op2)) break;
		_strrev(op2);
		res[0] = '0';
		res[1] = 0;

		for (i = 0, p = op2; *p; p++, i++){
			mult(op1, tmp, *p);
			add(res + i, tmp, res + i);
		}

		_strrev(res);
		for (p = res; *p == '0'; p++);
		if (*p) printf("%s\n", p); else printf("0\n");
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
