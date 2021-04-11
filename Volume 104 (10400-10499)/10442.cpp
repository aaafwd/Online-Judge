/* @JUDGE_ID: 19899RK 10442 C++ "By Anadan" */
// Basic
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

char str[81], xdigits[] = "0123456789abcdef";

int strdigit(char *p){
	while (*p){
		if (*p < '0' || *p > '9') return 0;
		++p;
	}
	return 1;
}

int getbase(char *p){
	int i, base;
	char *q;

	if (*p == '#'){
		*p-- = 0;
		for (q = p; q > str; --q) if (*q == '#') break;
		if (q <= str || q == p) return -1;
		*q = 0;
		i = getbase(q - 1);
		if (i == -1) return -1;
		p = q;
		base = 0;
		while (*++p){
			if ((q = strchr(xdigits, *p)) == NULL) break;
			if (int(q - xdigits) >= i) break;
			base = base * i + int(q - xdigits);
			if (base > 16) break;
		}

		if (*p) return -1;
	}else{
		for (q = str; q < p && *q == '0'; ++q);
		i = int(p - q);
		if (i < 0 || i > 1 || !strdigit(q)) return -1;
		base = q[0] - '0';
		if (q[1]) base = base * 10 + q[1] - '0';
	}

	if (base < 2 || base > 16) base = -1;
	return base;
}

int main(){
	int set, i;
	char *p, *q;

	scanf("%d\n", &set);
	while (set--){
		scanf("%s\n", str);
		i = strlen(str) - 1;
		if (str[i] != '#') printf("%s\n", strdigit(str) ? "yes" : "no");
		else{
			str[i] = 0;
			for (p = str + i; p > str; --p) if (*p == '#') break;
			if (p <= str || *(p + 1) == 0) { printf("no\n"); continue; }
			*p = 0;
			i = getbase(p - 1);
			if (i == -1) { printf("no\n"); continue; }
			while (*++p){
				if ((q = strchr(xdigits, *p)) == NULL) break;
				if (int(q - xdigits) >= i) break;
			}
			printf("%s\n", *p ? "no" : "yes");
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
