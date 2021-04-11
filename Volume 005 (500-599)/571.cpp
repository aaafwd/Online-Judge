/* @JUDGE_ID: 19899RK 571 C++ "By Anadan" */ 
// Jugs
// Accepted (0.012 seconds with low memory spent)

#include <stdio.h>

int main(){
	int A, B, N, a, b;

	while (scanf("%d%d%d", &A, &B, &N) == 3){
		a = b = 0;
		while (a != N && b != N){
			if (a == 0){
				puts("fill A");
				a = A;
			}else if (b == B){
				puts("empty B");
				b = 0;
			}else{
				puts("pour A B");
				b += a;
				if (b > B){
					a = b - B;
					b = B;
				}else a = 0;
			}
		}
		puts("success");
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
