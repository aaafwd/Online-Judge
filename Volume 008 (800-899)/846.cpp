/* @JUDGE_ID: 19899RK 846 C++ "By Anadan" */ 
// Steps
// Accepted (0.004 seconds with low memory spent)

#include <stdio.h>
#include <math.h>

int main(){
	int set, x, y, res;

	scanf("%d\n", &set);
	while (set--){
		scanf("%d%d", &x, &y); y -= x;
		x = (int)sqrt(y); y -= x * x;
		res = x + x - 1;
		if (y != 0 || x == 0) ++res;
		if (y > x) ++res;
		printf("%d\n", res);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
