/* @JUDGE_ID: 19899RK 10268 C++ "By Anadan" */ 
// 498-bis
// Accepted (0.152 seconds using as much as 384 kbytes)

#include <stdio.h>
#include <ctype.h>

int main(){
	int c, x, a, A, B;

	while (scanf("%d", &x) == 1){
		while (getchar() != '\n');
		A = B = 0;
		while ((c = getchar()) != '\n'){
			if (isdigit(c)){
				a = c - '0';
				while (isdigit(c = getchar())){
					a *= 10;
					a += c - '0';
				}
				B = x * B + A;
				A = x * A + a;
				if (c == '\n') break;
			}else if (c == '-'){
				scanf("%d", &a);
				B = x * B + A;
				A = x * A - a;
			}
		}

		printf("%d\n", B);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
