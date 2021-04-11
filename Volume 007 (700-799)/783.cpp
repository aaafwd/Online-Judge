/* @JUDGE_ID: 19899RK 783 C++ "By Anadan" */ 
// Trains
// Accepted (0.006 seconds with low memory spent)

#include <stdio.h>

int main(){
	int d, v1, v2, t1, t2, t3, tf, res, p1, p2, p3, p4;

	while (scanf("%d%d%d%d%d%d\n", &d, &v1, &v2, &t1, &t2, &tf) == 6){
		tf = tf * (v1 + v2) - d;
		p1 = t1 * v1;
		p2 = t1 * v2;
		p3 = t2 * v1;
		p4 = t2 * v2;
		v1 = d;
		v2 = -d;

		res = 0;
		while (tf >= 0){
			if (v2 <= 0) t3 = 0;
			else t3 = (v2 + p1 - 1) / p1;
			t1 = tf / p1;
			t2 = v1 / p2;
			if (t1 > t2) t1 = t2;
			else if (t3 > t1) break;

			if (t3 <= t1) res += t1 - t3 + 1;

			tf -= p4;
			v1 += p4;
			v2 += p3;
		}

		printf("%d\n", res);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
