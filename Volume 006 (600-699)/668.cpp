/* @JUDGE_ID: 19899RK 668 C++ "By Anadan" */ 
// Parliament
// Accepted (0.002 seconds with low memory spent)

#include <stdio.h>

int main(){
	int set, N, i, j, arr[45];

	scanf("%d\n\n", &set);
	while (set--){
		scanf("%d\n", &N);
		
		for (i = 2; i <= N; ++i){
			arr[i - 2] = i;
			N -= i;
		}

		for (i -= 3, j = i; N > 0; --N){
			++arr[i];
			if (i) --i; else i = j;
		}

		printf("%d", arr[0]);
		for (i = 1; i <= j; ++i) printf(" %d", arr[i]);
		putchar('\n');

		if (set) putchar('\n');
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
