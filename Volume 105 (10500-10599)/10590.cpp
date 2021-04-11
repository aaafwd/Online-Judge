/* @JUDGE_ID: 19899RK 10590 C++ "By Anadan" */
// Boxes of Chocolates Again
// Accepted (1.117 seconds using as much as 704 kbytes)

#include <stdio.h>
#include <string.h>
#define SZ 200

char * arr[5001];

inline void setres(int i, const char * str){
	arr[i] = strcpy(new char [strlen(str) + 1], str);
}

void _reverse(char * p){
	char * q = p + strlen(p) - 1;
	while (p < q) *p++ ^= *q-- ^= *p ^= *q;
}

void add(char * p, char * q){
	int rest = 0;

	while (*p && *q){
		rest += *p - '0' + *q - '0';
		if (rest > 9){
			*p = rest - 10 + '0';
			rest = 1;
		}else{
			*p = rest + '0';
			rest = 0;
		}

		++p; ++q;
	}

	while (*q){
		rest += *q - '0';
		if (rest > 9){
			*p = rest - 10 + '0';
			rest = 1;
		}else{
			*p = rest + '0';
			rest = 0;
		}

		++p; ++q;
	}

	while (*p){
		rest += *p - '0';
		if (rest > 9){
			*p = rest - 10 + '0';
			rest = 1;
		}else{
			*p = rest + '0';
			rest = 0;
		}

		++p;
	}

	if (rest) *p++ = '1';
	*p = 0;
}

void sub(char * p, char * q){
	int rest = 0;

	while (*p && *q){
		rest += *p - *q;
		if (rest < 0){
			*p = rest + 10 + '0';
			rest = -1;
		}else{
			*p = rest + '0';
			rest = 0;
		}

		++p; ++q;
	}

	while (*p){
		rest += *p - '0';
		if (rest < 0){
			*p = rest + 10 + '0';
			rest = -1;
		}else{
			*p = rest + '0';
			rest = 0;
		}

		++p;
	}

	*p = 0;
	while (p[-1] == '0') *--p = 0;
}

int main(){
	int i, j, q;
	char str[SZ];

	strcpy(str, "1");
	setres(0, str);

	for (i = 1; i < 5001; ++i){
		strcpy(str, "0");

		for (q = 1 ;; q += 2){
			j = (3*q*q-q) >> 1;
			if (i - j < 0) break;
			add(str, arr[i - j]);

			j += q;
			if (i - j < 0) continue;
			add(str, arr[i - j]);
		}

		for (q = 2 ;; q += 2){
			j = (3*q*q-q) >> 1;
			if (i - j < 0) break;
			sub(str, arr[i - j]);

			j += q;
			if (i - j < 0) continue;
			sub(str, arr[i - j]);
		}

		setres(i, str);
	}

	for (i = 1; i < 5001; ++i) _reverse(arr[i]);

	while (scanf("%d", &i) == 1){
		puts(arr[i]);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
