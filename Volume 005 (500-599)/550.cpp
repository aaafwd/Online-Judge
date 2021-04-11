/* @JUDGE_ID: 19899RK 550 C++ "By Anadan" */
// Multiplying by Rotation
// Accepted (0.070 seconds using as much as 392 kbytes)

#include <stdio.h>

int main(){
	int base, lastdigit, curdigit, num, rest, result;

	while (scanf("%d%d%d", &base, &lastdigit, &num) == 3){
		rest = 0;
		result = 0;
		curdigit = lastdigit;
		do{
			rest += curdigit * num;
			curdigit = rest % base;
			rest /= base;
			++result;
		}while (curdigit != lastdigit || rest != 0);
		printf("%d\n", result);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
