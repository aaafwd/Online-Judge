/* @JUDGE_ID: 19899RK 10190 C++ "By Anadan" */ 
// Divide, But Not Quite Conquer!
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>

int main(){
	int n, m, arr[32], i;

	while (scanf("%d%d\n", &n, &m) == 2){
		if (n < 2 || m < 2) printf("Boring!\n");
		else{
			for (i = 0; n != 1; ++i){
				if (n % m) break;
				arr[i] = n;
				n /= m;
			}

			if (n != 1) printf("Boring!\n");
			else{
				for (n = 0; n < i; ++n) printf("%d ", arr[n]);
				printf("1\n");
			}
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
