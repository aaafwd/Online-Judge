/* @JUDGE_ID: 19899RK 10328 C++ "By Anadan" */ 
// Coin Toss
// Accepted (0.400 seconds using as much as 396 kbytes)

#include <stdio.h>
#include <string.h>

void _reverse(char *p){
	char *q = p + strlen(p) - 1;
	while (p < q) *p++ ^= *q-- ^= *p ^= *q;
}

void add(char *p, char *q){
	int rest = 0;

	while (*p && *q){
		rest += *p - '0' + *q++ - '0';
		if (rest > 9){
			*p++ = '0' + rest - 10;
			rest = 1;
		}else{
			*p++ = '0' + rest;
			rest = 0;
		}
	}

	while (*q){
		rest += *q++ - '0';
		if (rest > 9){
			*p++ = '0' + rest - 10;
			rest = 1;
		}else{
			*p++ = '0' + rest;
			rest = 0;
		}
	}

	while (*p){
		rest += *p - '0';
		if (rest > 9){
			*p++ = '0' + rest - 10;
			rest = 1;
		}else{
			*p++ = '0' + rest;
			rest = 0;
		}
	}

	if (rest) *p++ = '1';
	*p = 0;
}

void sub(char *p, char *q){
	int rest = 0;

	while (*p && *q){
		rest += (*p - '0') - (*q++ - '0');
		if (rest < 0){
			*p++ = '0' + rest + 10;
			rest = -1;
		}else{
			*p++ = '0' + rest;
			rest = 0;
		}
	}

	while (*p && rest){
		rest += *p - '0';
		if (rest < 0){
			*p++ = '0' + rest + 10;
			rest = -1;
		}else{
			*p++ = '0' + rest;
			rest = 0;
		}
	}
}

int main(){
	int n, k, i;
	char A[100][33], tmp[33], *p;

	while (scanf("%d%d", &n, &k) == 2){
		if (k > n) while (1);
		strcpy(A[k - 1], "1");
		strcpy(tmp, "1");
		for (i = k; i < n; ++i){
			strcpy(A[i], A[i - 1]);
			add(A[i], A[i - 1]);
			add(A[i], tmp);
			if (i - k >= k) sub(A[i], A[i - k - 1]);
			add(tmp, tmp);
		}

		_reverse(A[n - 1]);
		for (p = A[n - 1]; *p == '0'; ++p);
		puts(p);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
