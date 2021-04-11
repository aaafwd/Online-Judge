/* @JUDGE_ID: 19899RK 679 C++ "By Anadan" */ 
// Dropping Balls
// Accepted (0.264 seconds using as much as 384 kbytes)

#include <stdio.h>

int main(){
	int set, D, I, a, b;

	scanf("%d\n", &set);
	while (set--){
		scanf("%d%d\n", &D, &I);
		a = 1 << (D - 1); b = 1 << D;
		while (a < b - 1){
			if (I & 1) b = (a + b) >> 1;
			else a = (a + b) >> 1;
			I = (I + 1) >> 1;
		}

		printf("%d\n", a);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
