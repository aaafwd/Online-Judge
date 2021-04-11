/* @JUDGE_ID: 19899RK 10071 C++ "By Anadan" */
// Back to High School Physics
// Accepted (0.045 seconds with low memory spent)

#include <stdio.h>

int myscanf(int &x){
	int i, sgn = 0;

	while ((x = getchar()) != EOF && x != '-' && (x < '0' || x > '9'));
	if (x == EOF) return 0;
	if (x == '-'){
		sgn = 1;
		x = getchar();
	}

	x -= '0';
	while ((i = getchar()) != EOF && '0' <= i && i <= '9'){
		x = x * 10 + i - '0';
	}
	if (sgn) x = -x;

	return 1;
}

void myprintf(int x){
	int sgn = 0;
	char str[20], *p = str + 19;

	if (x == 0){
		putchar('0'); putchar('\n');
	}else{
		if (x < 0) { x = -x; sgn = 1; }
		*p-- = 0;
		while (x){
			*p-- = '0' + (x % 10);
			x /= 10;
		}

		if (sgn) putchar('-');
		puts(p + 1);
	}
}

int main(){
	int v, t;
	while (myscanf(v) && myscanf(t)) myprintf((t << 1) * v);
	return 0;
}
/* @END_OF_SOURCE_CODE */
