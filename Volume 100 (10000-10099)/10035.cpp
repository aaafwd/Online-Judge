/* @JUDGE_ID: 19899RK 10035 C++ "By Anadan" */
// Primary Arithmetic
// Accepted (0.037 seconds with low memory spent)

#include <stdio.h>

int getcarries(int a, int b){
	int res = 0, rest = 0;

	if (a > b) { a ^= b; b ^= a; a ^= b; }
	while (b){
		rest += (a % 10) + (b % 10);
		a /= 10; b /= 10;
		if (rest >= 10) rest = 1; else rest = 0;
		res += rest;
	}

	return res;
}

int myscanf(int &x){
	int i;

	while ((x = getchar()) != EOF && (x < '0' || x > '9'));
	if (x == EOF) return 0;

	x -= '0';
	while ((i = getchar()) != EOF && '0' <= i && i <= '9'){
		x = x * 10 + i - '0';
	}

	return 1;
}

int main(){
	int c, a, b;

	while (myscanf(a) && myscanf(b) && (a || b)){
		c = getcarries(a, b);
		if (c == 0) puts("No carry operation.");
		else if (c == 1) puts("1 carry operation.");
		else printf("%d carry operations.\n", c);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
