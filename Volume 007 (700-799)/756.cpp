/* @JUDGE_ID: 19899RK 756 C++ "By Anadan" */ 
// Biorhythms
// Accepted (0.070 seconds with low memory spent)

#include <stdio.h>

int main(){
	int p, e, i, d, day, set;

	set = 0;
	while (scanf("%d%d%d%d", &p, &e, &i, &d) == 4 && p >= 0){
		p %= 23; e %= 28; i %= 33;
		if (d >= i) day = i + 33 * (1 + (d - i) / 33); else day = i;
		while (day < e || day < p) day += 33;
		while ((day - e) % 28 || (day - p) % 23) day += 33;
		printf("Case %d: the next triple peak occurs in %d days.\n", ++set, day - d);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
