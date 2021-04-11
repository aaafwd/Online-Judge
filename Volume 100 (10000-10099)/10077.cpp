/* @JUDGE_ID: 19899RK 10077 C++ "By Anadan" */
// The Stern-Brocot Number System
// Accepted (0.010 seconds with low memory spent)

#include <stdio.h>

typedef unsigned long dword;
struct Fract{
	dword m, n;
	void operator += (Fract &f) { m += f.m; n += f.n; }
};

int main(){
	dword m, n;
	Fract left, right, cur, tmp;

	while (scanf("%lu%lu", &m, &n) == 2){
		if (m == 1L && n == 1L) break;
		cur.m = cur.n = right.m = left.n = 1L;
		left.m = right.n = 0L;

		while (cur.m != m || cur.n != n){
			tmp = cur;
			if (n*cur.m > m*cur.n){
				cur += left;
				right = tmp;
				putchar('L');
			}else{
				cur += right;
				left = tmp;
				putchar('R');
			}
		}
		putchar('\n');
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
