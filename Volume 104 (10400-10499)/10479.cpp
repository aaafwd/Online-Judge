/* @JUDGE_ID: 19899RK 10479 C++ "By Anadan" */ 
// Hendrie Sequence
// Accepted (0.008 seconds with low memory spent)

#include <stdio.h>

typedef unsigned long long qword;

int H(qword n){
	int i, x;
	qword pos, l, p;

	while (1){
		pos = qword(1);
		for (i = 0; pos < n; ++i) pos <<= 1;
		if (n == pos) return i;
		if (n > pos - i) return 0;

		pos -= i;
		l = qword(1); p = qword(2); x = i - 2;

		while (n <= pos - l * x){
			pos -= l * x;
			p += l;
			l <<= 1; --x;
		}

		n = (n - pos + l * x - 1) % l + p;
	}
}

int main(){
	qword n;
	while (scanf("%llu", &n) == 1 && n) printf("%d\n", H(n));
	return 0;
}
/* @END_OF_SOURCE_CODE */
