/* @JUDGE_ID: 19899RK 10489 C++ "By Anadan" */ 
// Boxes of Chocolates
// Accepted (0.107 seconds using as much as 388 kbytes)

#include <stdio.h>

void myscanf(int &x){
	int i;

	while ((x = getchar()) != EOF && (x < '0' || x > '9'));

	x -= '0';
	while ((i = getchar()) != EOF && '0' <= i && i <= '9'){
		x = x * 10 + i - '0';
	}
}

int main(){
	int set, N, B, i, j, k, rest, tmp;

	scanf("%d", &set);
	while (set--){
		myscanf(N); myscanf(B);
		
		rest = 0;
		for (i = 0; i < B; ++i){
			myscanf(j);
			tmp = 1;
			while (j--){
				myscanf(k);
				tmp = (tmp * k) % N;
			}

			rest += tmp;
		}

		printf("%d\n", rest % N);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
