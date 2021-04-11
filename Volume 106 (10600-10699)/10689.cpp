/* @JUDGE_ID: 19899RK 10689 C++ "By Anadan" */
// Yet another Number Sequence
// Accepted (0.111 seconds using as much as 392 kbytes)

#include <stdio.h>

int a, b, n, m, x1, x2, x3, x4;

void doMul(){
	int y1 = 1, y2 = 1, y3 = 1, y4 = 0;
	x1 = x4 = 1; x2 = x3 = 0;

	while (n){
		if (n & 1){
			int t1 = (x1 * y1 + x2 * y3) % m;
			int t2 = (x1 * y2 + x2 * y4) % m;
			x1 = t1; x2 = t2;
			t1 = (x3 * y1 + x4 * y3) % m;
			t2 = (x3 * y2 + x4 * y4) % m;
			x3 = t1; x4 = t2;
			--n;
		}else{
			int t1 = (y1 * y1 + y2 * y3) % m;
			int t2 = (y1 * y2 + y2 * y4) % m;
			int t3 = (y3 * y1 + y4 * y3) % m;
			int t4 = (y3 * y2 + y4 * y4) % m;
			y1 = t1; y2 = t2; y3 = t3; y4 = t4;
			n >>= 1;
		}
	}
}

int main(){
	int set;

	scanf("%d", &set);
	while (set--){
		scanf("%d%d%d%d", &a, &b, &n, &m);
		switch(m){
			case 1: m = 10; break;
			case 2: m = 100; break;
			case 3: m = 1000; break;
			case 4: m = 10000; break;
		}

		if (n == 0){
			printf("%d\n", a % m);
			continue;
		}else if (n == 1){
			printf("%d\n", b % m);
			continue;
		}

		--n;
		doMul();
		printf("%d\n", (x1*b + x2*a) % m);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
