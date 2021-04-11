/* @JUDGE_ID: 19899RK 514 C++ "By Anadan" */ 
// Rails
// Accepted (0.186 seconds using as much as 392 kbytes)

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
	int i, N, M, a[1000], b[1000], sp, minrest;

	while (scanf("%d", &N) == 1 && N){
		while (1){
			myscanf(i);
			if (i == 0) break;

			sp = 0;
			minrest = 1;
			M = N;

			while (1){
				if (minrest <= i){
					a[sp] = minrest;
					b[sp] = i;
					minrest = i + 1;
					++sp;
				}

				if (i != b[sp - 1]) break;
				--b[sp - 1];
				if (a[sp - 1] > b[sp - 1]) --sp;

				if (--M == 0) break;
				myscanf(i);
			}

			if (M){
				puts("No");
				while (--M) myscanf(i);

			}else puts("Yes");
		}

		putchar('\n');
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
