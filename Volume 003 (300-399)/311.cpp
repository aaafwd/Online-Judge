/* @JUDGE_ID: 19899RK 311 C++ "By Anadan" */ 
// Packets
// Accepted (0.010 seconds with low memory spent)

#include <stdio.h>

int main(){
	int a1, a2, a3, a4, a5, a6, N = 0;
	while (scanf("%d%d%d%d%d%d\n", &a1, &a2, &a3, &a4, &a5, &a6) > 0){
		if ((!a1)&&(!a2)&&(!a3)&&(!a4)&&(!a5)&&(!a6)) break;
		N = a4 + a5 + a6 + a3 / 4;
		a1 -= 11 * a5;
		a2 -= 5 * a4;
		a3 %= 4;
		if (a3){
			a2 -= (7 - 2 * a3);
			a1 -= (8 - a3);
			N++;
		}
		if (a2 < 0){
			if (a1 > 0) a1 += a2 * 4;
			a2 = 0;
		}
		N += a2 / 9; a2 %= 9;
		if (a2){ a1 -= (36 - a2 * 4); N++; }
		if (a1 < 0) a1 = 0;
		N += a1 / 36; a1 %= 36;
		if (a1) N++;
		printf("%d\n", N);
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */
